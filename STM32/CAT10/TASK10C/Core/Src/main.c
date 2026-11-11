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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
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
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
char at_cmd[128];
char rx_buf[512];
char response[512];
char html_body[256];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

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
  MX_USART1_UART_Init();

  /* USER CODE BEGIN 2 */
  sprintf(at_cmd, "AT\r\n");
  HAL_UART_Transmit(&huart1, (uint8_t *)at_cmd, strlen(at_cmd), HAL_MAX_DELAY);
  HAL_Delay(1000);

  sprintf(at_cmd, "AT+CWMODE=1\r\n");
  HAL_UART_Transmit(&huart1, (uint8_t *)at_cmd, strlen(at_cmd), HAL_MAX_DELAY);
  HAL_Delay(1000);

  sprintf(at_cmd, "AT+CWJAP=\"iPhone\",\"rith1100\"\r\n");
  HAL_UART_Transmit(&huart1, (uint8_t *)at_cmd, strlen(at_cmd), HAL_MAX_DELAY);
  HAL_Delay(8000);

  sprintf(at_cmd, "AT+CIFSR\r\n");
  HAL_UART_Transmit(&huart1, (uint8_t *)at_cmd, strlen(at_cmd), HAL_MAX_DELAY);
  HAL_Delay(1500);

  sprintf(at_cmd, "AT+CIPMUX=1\r\n");
  HAL_UART_Transmit(&huart1, (uint8_t *)at_cmd, strlen(at_cmd), HAL_MAX_DELAY);
  HAL_Delay(1000);

  sprintf(at_cmd, "AT+CIPSERVER=1,80\r\n");
  HAL_UART_Transmit(&huart1, (uint8_t *)at_cmd, strlen(at_cmd), HAL_MAX_DELAY);
  HAL_Delay(1000);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    memset(rx_buf, 0, sizeof(rx_buf));

    if (HAL_UART_Receive(&huart1, (uint8_t *)rx_buf, sizeof(rx_buf) - 1, 1000) == HAL_OK || strlen(rx_buf) > 0)
    {
			
      char *ipd_ptr = strstr(rx_buf, "+IPD,");
      if (ipd_ptr != NULL)
      {
        int link_id = ipd_ptr[5] - '0';

        int captured_data = 10 + (rand() % 91);

        // Put the HTML together with the dynamic value
        int body_length = sprintf(html_body,
          "<html><body>"
          "<h1>STM32 IoT Node</h1>"
          "<p>Hello from STM32</p>"
          "<p>Captured data = %d</p>"
          "</body></html>",
          captured_data);

        int total_len = sprintf(response,
                                "HTTP/1.1 200 OK\r\n"
                                "Content-Type: text/html\r\n"
                                "Content-Length: %d\r\n"
                                "\r\n"
                                "%s", body_length, html_body);

        sprintf(at_cmd, "AT+CIPSEND=%d,%d\r\n", link_id, total_len);
        HAL_UART_Transmit(&huart1, (uint8_t *)at_cmd, strlen(at_cmd), HAL_MAX_DELAY);

        HAL_Delay(200);

        HAL_UART_Transmit(&huart1, (uint8_t *)response, total_len, HAL_MAX_DELAY);

        HAL_Delay(200);

        sprintf(at_cmd, "AT+CIPCLOSE=%d\r\n", link_id);
        HAL_UART_Transmit(&huart1, (uint8_t *)at_cmd, strlen(at_cmd), HAL_MAX_DELAY);
      }
    }
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

  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 84;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

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
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
  }
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
}
#endif /* USE_FULL_ASSERT */