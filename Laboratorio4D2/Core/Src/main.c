/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */
volatile uint8_t contador = 0;
volatile uint8_t cont = 5;
volatile uint16_t banTimer = 0; // Necesita ser de 16 para que no se queda en 255
volatile uint8_t cont1 = 0;
volatile uint8_t cont2 = 0;
volatile uint8_t gana = 0;

uint8_t DIS7SEG[6] = {0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B}; //cambiar el valor dentro de la llaves.

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */
void display(uint8_t num);
void ledJ1(uint8_t n1);
void ledJ2(uint8_t n2);
void reset(void);


/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  display(0);
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  { //Mi codigo base para


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 83;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 999;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LedG_Pin|Led1J1_Pin|Led2J1_Pin|Led3J1_Pin
                          |Led4J1_Pin|LedA_Pin|LedB_Pin|LedC_Pin
                          |LedD_Pin|LedE_Pin|LedF_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, Led1J2_Pin|Led2J2_Pin|Led3J2_Pin|Led4J2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LedG_Pin Led1J1_Pin Led2J1_Pin Led3J1_Pin
                           Led4J1_Pin LedA_Pin LedB_Pin LedC_Pin
                           LedD_Pin LedE_Pin LedF_Pin */
  GPIO_InitStruct.Pin = LedG_Pin|Led1J1_Pin|Led2J1_Pin|Led3J1_Pin
                          |Led4J1_Pin|LedA_Pin|LedB_Pin|LedC_Pin
                          |LedD_Pin|LedE_Pin|LedF_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : USART_TX_Pin */
  GPIO_InitStruct.Pin = USART_TX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
  HAL_GPIO_Init(USART_TX_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : BTN3_Pin */
  GPIO_InitStruct.Pin = BTN3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(BTN3_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : BTN1_Pin BTN2_Pin */
  GPIO_InitStruct.Pin = BTN1_Pin|BTN2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : Led1J2_Pin Led2J2_Pin Led3J2_Pin Led4J2_Pin */
  GPIO_InitStruct.Pin = Led1J2_Pin|Led2J2_Pin|Led3J2_Pin|Led4J2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2)
	{
		if (contador == 1)
		{
			banTimer++;
			if (banTimer >= 1000)
			{
				banTimer = 0;
				cont--;
				display(cont); // Actualizar display

				if (cont == 0)
				{
					contador = 0;
					ledJ1(0);
					ledJ2(0);
				}
			}
		}
	}
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin == BTN1_Pin){
		if ((cont == 0) && (gana == 0))
				{
					cont1++;
					ledJ1(cont1);

					if (cont1 >= 4)
					{
						gana = 1;
						display(1);
						ledJ1(5);
						ledJ2(0);
					}
				}
	}

	else if (GPIO_Pin == BTN2_Pin){
		if ((cont == 0) && (gana == 0))
				{
					cont2++;
					ledJ2(cont2);

					if (cont2 >= 4)
					{
						gana = 1;
						display(2);
						ledJ1(0);
						ledJ2(5);
					}
				}
	}

	else if (GPIO_Pin == BTN3_Pin){
		if (contador == 0) // Se podria quidar el if para entrar directo al conteo sin
						   //esperar el conteo completo
				{
					reset(); // Reinicio variables y LEDs
					contador = 1;
					cont = 5;
					banTimer = 0;
					display(cont);
				}

	}
}

void display(uint8_t num)
{
	uint8_t val = DIS7SEG[num];

	HAL_GPIO_WritePin(GPIOC, LedA_Pin, (val & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LedB_Pin, (val & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LedC_Pin, (val & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LedD_Pin, (val & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LedE_Pin, (val & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LedF_Pin, (val & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LedG_Pin, (val & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void reset(void)
{
	gana = 0;
	cont1 = 0;
	cont2 = 0;
	ledJ1(0);
	ledJ2(0);
}

void ledJ1(uint8_t n1)
{
	switch(n1)
		  {
		  case 0: HAL_GPIO_WritePin(Led1J1_GPIO_Port, Led1J1_Pin,0);
		  	  	  HAL_GPIO_WritePin(Led2J1_GPIO_Port, Led2J1_Pin,0);
		  	  	  HAL_GPIO_WritePin(Led3J1_GPIO_Port, Led3J1_Pin,0);
		  	  	  HAL_GPIO_WritePin(Led4J1_GPIO_Port, Led4J1_Pin,0);
					 break;
		  case 1: HAL_GPIO_WritePin(Led1J1_GPIO_Port, Led1J1_Pin,1);
		  	  	  HAL_GPIO_WritePin(Led2J1_GPIO_Port, Led2J1_Pin,0);
		  	  	  HAL_GPIO_WritePin(Led3J1_GPIO_Port, Led3J1_Pin,0);
		  	  	  HAL_GPIO_WritePin(Led4J1_GPIO_Port, Led4J1_Pin,0);
			  break;
		  case 2: HAL_GPIO_WritePin(Led1J1_GPIO_Port, Led1J1_Pin,0);
		  	  	  HAL_GPIO_WritePin(Led2J1_GPIO_Port, Led2J1_Pin,1);
		  	  	  HAL_GPIO_WritePin(Led3J1_GPIO_Port, Led3J1_Pin,0);
		  	  	  HAL_GPIO_WritePin(Led4J1_GPIO_Port, Led4J1_Pin,0);
		  		  break;
		  case 3: HAL_GPIO_WritePin(Led1J1_GPIO_Port, Led1J1_Pin,0);
		  	  	  HAL_GPIO_WritePin(Led2J1_GPIO_Port, Led2J1_Pin,0);
		  	  	  HAL_GPIO_WritePin(Led3J1_GPIO_Port, Led3J1_Pin,1);
		  	  	  HAL_GPIO_WritePin(Led4J1_GPIO_Port, Led4J1_Pin,0);
		  		  break;

		  case 4: HAL_GPIO_WritePin(Led1J1_GPIO_Port, Led1J1_Pin,0);
		  	  	  HAL_GPIO_WritePin(Led2J1_GPIO_Port, Led2J1_Pin,0);
		  	  	  HAL_GPIO_WritePin(Led3J1_GPIO_Port, Led3J1_Pin,0);
		  	  	  HAL_GPIO_WritePin(Led4J1_GPIO_Port, Led4J1_Pin,1);
		  	  	  break;
		  case 5: HAL_GPIO_WritePin(Led1J1_GPIO_Port, Led1J1_Pin,1);
		  		  HAL_GPIO_WritePin(Led2J1_GPIO_Port, Led2J1_Pin,1);
		  		  HAL_GPIO_WritePin(Led3J1_GPIO_Port, Led3J1_Pin,1);
		  		  HAL_GPIO_WritePin(Led4J1_GPIO_Port, Led4J1_Pin,1);
		  		  break;
		  default:
		  break;
		  }
}

void ledJ2(uint8_t n2)
{
	switch(n2)
		  	  {
		 case 0: HAL_GPIO_WritePin(Led1J2_GPIO_Port, Led1J2_Pin,0);
		 	 	 HAL_GPIO_WritePin(Led2J2_GPIO_Port, Led2J2_Pin,0);
		 	 	 HAL_GPIO_WritePin(Led3J2_GPIO_Port, Led3J2_Pin,0);
		 	 	 HAL_GPIO_WritePin(Led4J2_GPIO_Port, Led4J2_Pin,0);
				 break;
		  case 1: HAL_GPIO_WritePin(Led1J2_GPIO_Port, Led1J2_Pin,1);
				  HAL_GPIO_WritePin(Led2J2_GPIO_Port, Led2J2_Pin,0);
				  HAL_GPIO_WritePin(Led3J2_GPIO_Port, Led3J2_Pin,0);
				  HAL_GPIO_WritePin(Led4J2_GPIO_Port, Led4J2_Pin,0);
			  break;
		  case 2: HAL_GPIO_WritePin(Led1J2_GPIO_Port, Led1J2_Pin,0);
				  HAL_GPIO_WritePin(Led2J2_GPIO_Port, Led2J2_Pin,1);
				  HAL_GPIO_WritePin(Led3J2_GPIO_Port, Led3J2_Pin,0);
				  HAL_GPIO_WritePin(Led4J2_GPIO_Port, Led4J2_Pin,0);
				  break;
		  case 3: HAL_GPIO_WritePin(Led1J2_GPIO_Port, Led1J2_Pin,0);
				  HAL_GPIO_WritePin(Led2J2_GPIO_Port, Led2J2_Pin,0);
				  HAL_GPIO_WritePin(Led3J2_GPIO_Port, Led3J2_Pin,1);
				  HAL_GPIO_WritePin(Led4J2_GPIO_Port, Led4J2_Pin,0);
				  break;

		  case 4: HAL_GPIO_WritePin(Led1J2_GPIO_Port, Led1J2_Pin,0);
				  HAL_GPIO_WritePin(Led2J2_GPIO_Port, Led2J2_Pin,0);
				  HAL_GPIO_WritePin(Led3J2_GPIO_Port, Led3J2_Pin,0);
				  HAL_GPIO_WritePin(Led4J2_GPIO_Port, Led4J2_Pin,1);
				  break;
		  case 5: HAL_GPIO_WritePin(Led1J2_GPIO_Port, Led1J2_Pin,1);
		  	  	  HAL_GPIO_WritePin(Led2J2_GPIO_Port, Led2J2_Pin,1);
		  	  	  HAL_GPIO_WritePin(Led3J2_GPIO_Port, Led3J2_Pin,1);
		  	  	  HAL_GPIO_WritePin(Led4J2_GPIO_Port, Led4J2_Pin,1);
		  	  	  break;
		  default:
		  break;
		  }
}


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
