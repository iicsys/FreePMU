/* ------------------------ BRTOS includes ----------------------------- */
#include "main.h"

/* ------------------------ lwIP includes --------------------------------- */
#include "lwip/api.h"
#include "lwip/tcpip.h"
#include "lwip/sockets.h"
#include "lwip/tcp.h"
#include "lwip/ip.h"
#include "lwip/memp.h"
#include "lwip/stats.h"

#include "lwip/mem.h"
#include "lwip/udp.h"
#include "netif/etharp.h"
#include "lwip/dhcp.h"
#include "lwip/sys.h"

/* ------------------------ Project includes ------------------------------ */
#include <string.h>
#include <stdio.h>
#include "vnc_app.h"
#include "frameDataQ.h"
/* ------------------------ IEEE C37118 includes --------------------------- */
#define TCP_PORT 4712

#define A_SYNC_AA 0xAA
#define A_SYNC_DATA 0x01
#define A_SYNC_HDR 0x11
#define A_SYNC_CFG1 0x21
#define A_SYNC_CFG2 0x31
#define A_SYNC_CFG3 0x51
#define A_SYNC_CMD 0x41

unsigned char cmd;
volatile unsigned char connected=0;
extern unsigned char ucData[128];
extern int frame_data(void);
extern int frame_config(void);
extern int frame_header(void);
osMutexId ethMut_id;
volatile int newsockfd_out;
volatile unsigned char data_flag=0;

osMutexDef(ethMut);
void pmu_tcp_server(void const * argument)
{
	int sockfd, newsockfd, clilen;
	struct sockaddr_in serv_addr, cli_addr;
	int n;
	unsigned char buffer[1024];

	int nbytes;


	/* Parameters are not used - suppress compiler error. */
    //LWIP_UNUSED_ARG(pvParameters);

    ethMut_id = osMutexCreate(osMutex(ethMut));

reboot_server:
    /* First call to socket() function */
	sockfd = lwip_socket(AF_INET, SOCK_STREAM, 0);
	int on = 1;
	int status = lwip_setsockopt(sockfd, SOL_SOCKET,SO_REUSEADDR, (const char *) &on, sizeof(on));
	if (sockfd < 0) {
		//erro
		while(1){
			osDelay(1000);
		}
	}

	/* Initialize socket structure */
	/* set up address to connect to */
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_len = sizeof(serv_addr);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = PP_HTONS(TCP_PORT);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	/* Now bind the host address using bind() call.*/
	if (lwip_bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	{
		//erro
		lwip_close(sockfd);
		while(1){
			osDelay(1000);
		}
	}
	/* Now start listening for the clients, here
	 * process will go in sleep mode and will wait
	 * for the incoming connection
	 */
	if ( lwip_listen(sockfd, 5) != 0 ){
		lwip_close(sockfd);
		while(1){
			osDelay(1000);
		}
	}

	clilen = sizeof(cli_addr);

	 // While true
	while (1)
	{


		// Accept all requests
		newsockfd = lwip_accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t*)&clilen);
		if (newsockfd < 0){
			//erro
			while(1){
				osDelay(1000);
			}
		}

		connected = 1;
		newsockfd_out = newsockfd;
		while(1)
		{



			bzero(buffer,1024);
			n = lwip_read(newsockfd,buffer,1024);
			osMutexWait(ethMut_id,0);
			if (n < 0){
				//erro
				close(newsockfd);
				close(sockfd);
				connected = 0;
				osMutexRelease(ethMut_id);
				goto reboot_server;
			}else
			{
				if (n == 0)
				{

					close(newsockfd);
					connected = 0;
					osMutexRelease(ethMut_id);
					break;
				}else
				{
					// processa o pacote recebido
					if(buffer[0] == A_SYNC_AA){

						if(buffer[1] == A_SYNC_CMD){

							switch(buffer[15]){

								case 0x01:  //Desliga transmiss�o
									data_flag = 0;
									break;

								case 0x02: // Liga transmiss�o
									data_flag = 1;
									break;

								case 0x03: // Envia frame de cabe�alho
									nbytes = frame_header();
									lwip_send(newsockfd, ucData, nbytes, 0);
									break;

								case 0x04: // Envia frame de cofigura��o 1
									nbytes = frame_config();
									lwip_send(newsockfd, ucData, nbytes, 0);
									break;

								case 0x05: // Envia frame de cofigura��o 2
									nbytes = frame_config();
									lwip_send(newsockfd, ucData, nbytes, 0);
									break;

									default:
										// pacote desconhecido
									break;
								}


						}else{
							// pacote desconhecido
							break;
						}

					}
				}
			}
			osMutexRelease(ethMut_id);
		}
	} /* end of while */
}


osSemaphoreId syncSem_id;
osSemaphoreDef(syncSem);
char isSyncCreated = 0;

extern struct frameDataQueue* qUcData;
int i;

void pmu_tcp_server_out(void const * argument)
{
	int nbytes;

	/* Parameters are not used - suppress compiler error. */
    //LWIP_UNUSED_ARG(pvParameters);

    syncSem_id = osSemaphoreCreate(osSemaphore(syncSem), 1);
    isSyncCreated = 1;;
	while(1){
		osSemaphoreWait(syncSem_id, osWaitForever);
		if(connected){
			osMutexWait(ethMut_id,0);
			nbytes = frame_data();

			// Caso seja 1, s� h� um ucData para mandar, pois a fila est� vazia
			if (nbytes == 1) {
				// Os data frames aparentam ter sempre 50 bytes de tamanho
				lwip_send(newsockfd_out, ucData, 50, 0);
			// Caso contr�rio, envia-se a fila toda
			} else if (nbytes > 1) {
				struct frameDataElement* temp = (struct frameDataElement*)removeQueueElement(qUcData);

				while (temp != NULL) {
					lwip_send(newsockfd_out, temp->ucData, 50, 0);

					// E transcorre-se para o pr�ximo elemento da fila
					temp = temp->next;
				}
			}

			osMutexRelease(ethMut_id);
		}
	}
}

