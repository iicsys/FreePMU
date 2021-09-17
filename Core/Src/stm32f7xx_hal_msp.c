/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file         stm32f7xx_hal_msp.c
  * @brief        This file provides code for the MSP Initialization
  *               and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* USER CODE BEGIN Includes */
/* User can use this section to tailor ADCx instance used and associated resources */
/* Definition for ADCx clock resources */
#define ADC1_CLK_ENABLE()					__HAL_RCC_ADC1_CLK_ENABLE()
#define ADC2_CLK_ENABLE()					__HAL_RCC_ADC2_CLK_ENABLE()
#define ADC3_CLK_ENABLE()					__HAL_RCC_ADC3_CLK_ENABLE()

#define ADCPA_CHANNEL_GPIO_CLOCK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()
#define ADCPC_CHANNEL_GPIO_CLOCK_ENABLE()	__HAL_RCC_GPIOC_CLK_ENABLE()
#define ADCPF_CHANNEL_GPIO_CLOCK_ENABLE()	__HAL_RCC_GPIOF_CLK_ENABLE()

#define ADC_FORCE_RESET()              		__HAL_RCC_ADC_FORCE_RESET()
#define ADC_RELEASE_RESET()           		__HAL_RCC_ADC_RELEASE_RESET()

/* Definition for ADCx Channel Pin */
#define ADC1_CHANNEL_0_PIN               	GPIO_PIN_0
#define ADC1_CHANNEL_6_PIN               	GPIO_PIN_6
#define ADC2_CHANNEL_4_PIN               	GPIO_PIN_4
#define ADC2_CHANNEL_12_PIN               	GPIO_PIN_2
#define ADC3_CHANNEL_8_PIN                	GPIO_PIN_10
#define ADC3_CHANNEL_7_PIN               	GPIO_PIN_9

/* Definition for DMA */
#define DMA_CLK_ENABLE()					__HAL_RCC_DMA2_CLK_ENABLE()

/* Definition for ADCx's DMA */
#define ADC_DMA_CHANNEL                		DMA_CHANNEL_0
#define ADC_DMA_STREAM                 		DMA2_Stream4

/* Definition for ADCx's NVIC */
#define ADC_DMA_IRQn                   		DMA2_Stream4_IRQn
#define ADC_DMA_IRQHandler             		DMA2_Stream4_IRQHandler

/* Definition for TIMx clock resources */
#define TIMx                              	TIM8
#define TIMx_CLK_ENABLE()                 	__HAL_RCC_TIM8_CLK_ENABLE()

#define TIMx_FORCE_RESET()                	__HAL_RCC_TIM8_FORCE_RESET()
#define TIMx_RELEASE_RESET()             	__HAL_RCC_TIM8_RELEASE_RESET()


extern DMA_HandleTypeDef hdma_adc1;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */

/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{
  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_RCC_SYSCFG_CLK_ENABLE();

  /* System interrupt init*/
  /* PendSV_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(PendSV_IRQn, 15, 0);

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/* USER CODE BEGIN 1 */
void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{

  GPIO_InitTypeDef GPIO_InitStruct;
  if(huart->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /**USART1 GPIO Configuration
    PA10     ------> USART1_RX
    PA9     ------> USART1_TX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspInit 1 */
  } else if(huart->Instance == USART6) {
	__HAL_RCC_USART6_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_6;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF8_USART6;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	HAL_NVIC_SetPriority(USART6_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(USART6_IRQn);
	/* USER CODE END USART1_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{

  if(huart->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PA10     ------> USART1_RX
    PA9     ------> USART1_TX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_10|GPIO_PIN_9);

    /* USART1 interrupt DeInit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspDeInit 1 */
  } else if(huart->Instance == USART6) {
	  __HAL_RCC_USART6_CLK_DISABLE();
	  HAL_GPIO_DeInit(GPIOC, GPIO_PIN_7|GPIO_PIN_6);
  /* USER CODE END USART1_MspDeInit 1 */
  }

}

/**
  * @brief ADC MSP Initialization
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_ADC_MspInit(ADC_HandleTypeDef *hadc){
	GPIO_InitTypeDef          GPIO_InitStruct;

	/*##-1- Enable peripherals and GPIO Clocks #################################*/
	/* Enable GPIO clock */
	ADCPA_CHANNEL_GPIO_CLOCK_ENABLE();
	ADCPC_CHANNEL_GPIO_CLOCK_ENABLE();
	ADCPF_CHANNEL_GPIO_CLOCK_ENABLE();

	/* ADCx Periph clock enable */
	ADC1_CLK_ENABLE();
	ADC2_CLK_ENABLE();
	ADC3_CLK_ENABLE();

	/* Enable DMA clock */
	DMA_CLK_ENABLE();

	/*##-2- Configure peripheral GPIO ##########################################*/
	/* ADCx and ADCy Channel GPIO pin configuration */
	GPIO_InitStruct.Pin = ADC1_CHANNEL_6_PIN | ADC2_CHANNEL_4_PIN; //ADC1_CHANNEL_0_PIN
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	//GPIO_InitStruct.Pin = ADC2_CHANNEL_12_PIN;
	//GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	//GPIO_InitStruct.Pull = GPIO_NOPULL;
	//HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = ADC3_CHANNEL_8_PIN;// | ADC3_CHANNEL_7_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
}

/**
  * @brief ADC MSP De-Initialization
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO to their default state
  * @param hadc: ADC handle pointer
  * @retval None
  */
void HAL_ADC_MspDeInit(ADC_HandleTypeDef *hadc){

	/*##-1- Reset peripherals ##################################################*/
	ADC_FORCE_RESET();
	ADC_RELEASE_RESET();

	/*##-2- Disable peripherals and GPIO Clocks ################################*/
	/* De-initialize the ADC Channel GPIO pin */
	HAL_GPIO_DeInit(GPIOA, ADC1_CHANNEL_6_PIN);
	//HAL_GPIO_DeInit(GPIOA, ADC1_CHANNEL_0_PIN);
	HAL_GPIO_DeInit(GPIOA, ADC2_CHANNEL_4_PIN);
	//HAL_GPIO_DeInit(GPIOC, ADC2_CHANNEL_12_PIN);
	HAL_GPIO_DeInit(GPIOF, ADC3_CHANNEL_8_PIN);
	//HAL_GPIO_DeInit(GPIOF, ADC3_CHANNEL_7_PIN);

	/*##-3- Disable the DMA Streams ############################################*/
	/* De-Initialize the DMA Stream associated to transmission process */
	//HAL_DMA_DeInit(&hdma_adc1);

	/*##-4- Disable the NVIC for DMA ###########################################*/
	//HAL_NVIC_DisableIRQ(ADC_DMA_IRQn);
}

/**
  * @brief TIM MSP Initialization
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  * @param htim: TIM handle pointer
  * @retval None
  */
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* htim_base)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	  if(htim_base->Instance==TIM1)
	  {
	  /* USER CODE BEGIN TIM1_MspInit 0 */

	  /* USER CODE END TIM1_MspInit 0 */
	    /* Peripheral clock enable */
		  __HAL_RCC_TIM1_CLK_ENABLE();

		  /**TIM1 GPIO Configuration
		  PA12     ------> TIM1_ETR
		  */
		  GPIO_InitStruct.Pin = GPIO_PIN_12;
		  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		  GPIO_InitStruct.Pull = GPIO_NOPULL;
		  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		  GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
		  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	  /* USER CODE BEGIN TIM1_MspInit 1 */

	  /* USER CODE END TIM1_MspInit 1 */
	  }
	  else if(htim_base->Instance==TIM8){
		  /* USER CODE BEGIN TIM8_MspInit 0 */

		  /* USER CODE END TIM8_MspInit 0 */
		    /* Peripheral clock enable */
		    __HAL_RCC_TIM8_CLK_ENABLE();

		    /**TIM8 GPIO Configuration
		    PA0     ------> TIM8_ETR
		    */
		    GPIO_InitStruct.Pin = GPIO_PIN_0;
		    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		    GPIO_InitStruct.Pull = GPIO_NOPULL;
		    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		    GPIO_InitStruct.Alternate = GPIO_AF3_TIM8;
		    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		  /* USER CODE BEGIN TIM8_MspInit 1 */

		  /* USER CODE END TIM8_MspInit 1 */
	  }
	  else if(htim_base->Instance==TIM12){
		  /* USER CODE BEGIN TIM12_MspInit 0 */

		  /* USER CODE END TIM12_MspInit 0 */
		    /* Peripheral clock enable */
		    __HAL_RCC_TIM12_CLK_ENABLE();

		    /**TIM12 GPIO Configuration
		    PB14     ------> TIM12_CH1
		    */
		    GPIO_InitStruct.Pin = GPIO_PIN_14;
		    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		    GPIO_InitStruct.Pull = GPIO_NOPULL;
		    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		    GPIO_InitStruct.Alternate = GPIO_AF9_TIM12;
		    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

		  /* USER CODE BEGIN TIM12_MspInit 1 */

		  /* USER CODE END TIM12_MspInit 1 */
	  }

}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* htim_base)
{
	if(htim_base->Instance==TIM1)
	  {
	    __HAL_RCC_TIM1_CLK_DISABLE();

		  /**TIM1 GPIO Configuration
		  PA12     ------> TIM1_ETR*/
	    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_12);
	  }
	else if(htim_base->Instance==TIM8)
	  {
	    __HAL_RCC_TIM8_CLK_DISABLE();

	    /**TIM8 GPIO Configuration
	    PI3     ------> TIM8_ETR
	    */
	    HAL_GPIO_DeInit(GPIOI, GPIO_PIN_3);

	  }
	else if(htim_base->Instance==TIM12)
		  {
		    __HAL_RCC_TIM12_CLK_DISABLE();

		    /**TIM12 GPIO Configuration
		    PB14     ------> CHANNEL1_PWM
		    */
		    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_14);

		  }
}


/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
