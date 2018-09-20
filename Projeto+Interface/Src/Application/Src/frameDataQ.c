/*
 * frameDataQ.c
 *
 *  Created on: 24 de jul de 2018
 *      Author: Leonardo
 */

#include "frameDataQ.h"

/* Cria um novo elemento. */
struct frameDataElement* newElement (unsigned char* newUcData) {
	struct frameDataElement *temp = (struct frameDataElement*)malloc(sizeof(struct frameDataElement));
	strcpy(temp->ucData, newUcData);
	//temp->ucData = newUcData;
	temp->next = NULL;
	return temp;
}

/* Cria uma fila vazia. */
struct frameDataQueue* createFDQueue () {
	struct frameDataQueue* q = (struct frameDataQueue*)malloc(sizeof(struct frameDataQueue));
	q->ini = q->end = NULL;
	return q;
}

/* Enfila o elemento. */
void insertQueueElement (struct frameDataQueue* q, unsigned char* newUcData) {
	// Cria o novo elemento
	struct frameDataElement* temp = newElement(newUcData);

	// Se a fila estiver vazia, o novo elemento sera o inicio e o fim da fila
	if (q->end == NULL) {
		q->ini = q->end = temp;
	// Caso nao esteja vazia, coloca o elemento no fim da fila e o ponteiro do final aponta para o novo elemento
	} else {
		q->end->next = temp;
		q->end = temp;
	}
}

/* Desenfila o elemento e retorna a struct. */
struct frameDataElement* removeQueueElement (struct frameDataQueue* q) {
	// Se a fila estiver vazia, retorna nulo
	if (q->ini == NULL) {
		return NULL;
	}

	// Armazena o primeiro elemento e coloca o ponteiro de inicio um elemento a frente
	struct frameDataElement* temp = q->ini;
	q->ini = q->ini->next;

	// Caso a fila fique vazia apos a remocao, ambos os ponteiros serao nulos
	if (q->ini == NULL) {
		q->end = NULL;
	}

	return temp;
}

/* Verifica se a fila esta vazia. 1 caso sim, 0 caso contrario. */
int isQueueEmpty (struct frameDataQueue* q) {
	if (q->ini == NULL) {
		return 1;
	} else {
		return 0;
	}
}

/* Funcao para trocar o SOC do ucData. Retorna int para dizer qtos elementos ha na fila. */
int changeSOC (struct frameDataQueue* q, int nSOC) {
	uint16_t CRC_CCITT;
	int qtdE = 0;

	// O ponteiro de temp � colocado no in�cio da fila para iterar sobre os elementos
	struct frameDataElement* temp = q->ini;

	// O final da fila ocorre quando este pointeiro chegar a NULL, ent�o para cada item...
	while (temp != NULL) {
		// ... altera-se o SOC com o novo SOC
		temp->ucData[6] = (unsigned char)((nSOC & 0xFF000000) >> 24);
		temp->ucData[7] = (unsigned char)((nSOC & 0x00FF0000) >> 16);
		temp->ucData[8] = (unsigned char)((nSOC & 0x0000FF00) >> 8);
		temp->ucData[9] = (unsigned char)(nSOC & 0x000000FF);

		// Recalcula-se o CRC
		CRC_CCITT = ComputeCRC(temp->ucData, 48);

		temp->ucData[48] = (unsigned char)((CRC_CCITT & 0xFF00) >> 8);
		temp->ucData[49] = (unsigned char)(CRC_CCITT & 0x00FF);

		// E transcorre-se para o pr�ximo elemento da fila
		temp = temp->next;

		++qtdE;
	}

	return qtdE;
}
