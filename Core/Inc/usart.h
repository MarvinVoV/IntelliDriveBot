/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

#define UART_BUFFER_SIZE 100

/* USER CODE END Includes */

extern UART_HandleTypeDef huart4;

/* USER CODE BEGIN Private defines */

extern char uart_rx_buffer[UART_BUFFER_SIZE];
extern char uart_tx_buffer[UART_BUFFER_SIZE];

/* USER CODE END Private defines */

void MX_UART4_Init(void);

/* USER CODE BEGIN Prototypes */

void UART_Transmit(char *data, uint16_t size);
void UART_Receive(void);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

