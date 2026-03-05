/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LedG_Pin GPIO_PIN_13
#define LedG_GPIO_Port GPIOC
#define Led1J1_Pin GPIO_PIN_0
#define Led1J1_GPIO_Port GPIOC
#define Led2J1_Pin GPIO_PIN_1
#define Led2J1_GPIO_Port GPIOC
#define Led3J1_Pin GPIO_PIN_2
#define Led3J1_GPIO_Port GPIOC
#define Led4J1_Pin GPIO_PIN_3
#define Led4J1_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define BTN3_Pin GPIO_PIN_7
#define BTN3_GPIO_Port GPIOA
#define BTN3_EXTI_IRQn EXTI9_5_IRQn
#define BTN1_Pin GPIO_PIN_5
#define BTN1_GPIO_Port GPIOC
#define BTN1_EXTI_IRQn EXTI9_5_IRQn
#define Led1J2_Pin GPIO_PIN_12
#define Led1J2_GPIO_Port GPIOB
#define Led2J2_Pin GPIO_PIN_13
#define Led2J2_GPIO_Port GPIOB
#define Led3J2_Pin GPIO_PIN_14
#define Led3J2_GPIO_Port GPIOB
#define Led4J2_Pin GPIO_PIN_15
#define Led4J2_GPIO_Port GPIOB
#define BTN2_Pin GPIO_PIN_6
#define BTN2_GPIO_Port GPIOC
#define BTN2_EXTI_IRQn EXTI9_5_IRQn
#define LedA_Pin GPIO_PIN_7
#define LedA_GPIO_Port GPIOC
#define LedB_Pin GPIO_PIN_8
#define LedB_GPIO_Port GPIOC
#define LedC_Pin GPIO_PIN_9
#define LedC_GPIO_Port GPIOC
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define LedD_Pin GPIO_PIN_10
#define LedD_GPIO_Port GPIOC
#define LedE_Pin GPIO_PIN_11
#define LedE_GPIO_Port GPIOC
#define LedF_Pin GPIO_PIN_12
#define LedF_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
