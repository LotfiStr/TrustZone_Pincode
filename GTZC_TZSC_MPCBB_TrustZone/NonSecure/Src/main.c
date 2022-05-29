/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    GTZC/GTZC_TZSC_MPCBB_TrustZone/NonSecure/Src/main.c
  * @author  MCD Application Team
  * @brief   Non-secure main application
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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
#include "icache.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include "secure_nsc.h"


//#ifdef __GNUC__
///* With GCC/RAISONANCE, small printf (option LD Linker-
//>Libraries->Small printf
//set to 'Yes') calls __io_putchar() */
//#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
//#else
//#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
//#endif /* __GNUC__ */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define PRINTF_NSE DbgConsole_Printf_NSE
#define SCANF_NSE DbgConsole_Scanf_NSE

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint32_t testCaseNumber =306199800;
int testCaseNumber2;
char testCaseChar;
int testCaseNumber3;


__IO uint32_t IllegalMemoryAccessDetected = 0U;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
/* Callbacks prototypes */
void SecureFault_Callback(void);
void SecureError_Callback(void);

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
	  int num;
	  int result;

  /* Register SecureFault callback defined in non-secure and to be called by secure handler */
  SECURE_RegisterCallback(SECURE_FAULT_CB_ID, (void *)SecureFault_Callback);

  /* Register SecureError callback defined in non-secure and to be called by secure handler */
  SECURE_RegisterCallback(GTZC_ERROR_CB_ID, (void *)SecureError_Callback);

  /* STM32L5xx **NON-SECURE** HAL library initialization:
       - Non-secure Systick timer is configured by default as source of time base,
         but user can eventually implement his proper time base source (a general
         purpose timer for example or other time source), keeping in mind that
         Time base duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined
         and handled in milliseconds basis.
       - Set NVIC Group Priority to 3
       - Low Level Initialization
     */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  //setvbuf(stdin, NULL, _IONBF, 0);
  setbuf(stdin, NULL);

  /* USER CODE END Init */

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ICACHE_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */

  //PRINTF_NSE("Welcome in non-secure world!\r\n");
  //printf("Program has started!\r\n");
  PRINTF_NSE("Please Enter the Access Code: \r\n");
  //testCaseNumber2=SCANF_NSE();

	scanf("%d", &num);
	//printf("Code Pin Entered = %d \r\n", num);



  //code is 3061998
  result = PinCompare_NSE(num);
  if (result == 1)
  {
      PRINTF_NSE("Correct Code!\r\n");
      Access_ok_toggle();
      HAL_Delay(5000);
      Access_ok_toggle();
  }
  else
  {
      PRINTF_NSE("Wrong Code!\r\n");
      Access_Nok_toggle();
  }

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


  }
  /* USER CODE END 3 */
}

/* USER CODE BEGIN 4 */

int __io_putchar(int ch)
{
	if(HAL_UART_Transmit(&huart3, (uint8_t *)&ch, 1, 10) != HAL_OK)
		return -1;
	return ch;
}

int __io_getchar(void)
{
	char data[4];
	uint8_t ch, len = 1;

	while(HAL_UART_Receive(&huart3, &ch, 1, 10) != HAL_OK)
	{
	}

	memset(data, 0x00, 4);
	switch(ch)
	{
		case '\r':
		case '\n':
			len = 2;
			sprintf(data, "\r\n");
			break;

		case '\b':
		case 0x7F:
			len = 3;
			sprintf(data, "\b \b");
			break;

		default:
			data[0] = ch;
			break;
	}
	HAL_UART_Transmit(&huart3, (uint8_t *)data, len, 10);
	return ch;
}
/**
  * @brief  EXTI line rising detection callback.
  * @param  GPIO_Pin Specifies the port pin connected to corresponding EXTI line.
  * @retval None
  */
void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin)
{
//  if (GPIO_Pin == GPIO_PIN_13)
//  {
//	PRINTF_NSE("pleaser enter your ID");
//  }
}

/**
  * @brief  Callback called by secure code following a secure fault interrupt
  * @note   This callback is called by secure code thanks to the registration
  *         done by the non-secure application with non-secure callable API
  *         SECURE_RegisterCallback(SECURE_FAULT_CB_ID, (void *)SecureFault_Callback);
  * @retval None
  */
void SecureFault_Callback(void)
{
  /* Go to error infinite loop when Secure fault generated by IDAU/SAU check */
  /* because of illegal access */
  IllegalMemoryAccessDetected = 1U;

  Error_Handler();
}


/**
  * @brief  Callback called by secure code following a GTZC TZIC secure interrupt (GTZC_IRQn)
  * @note   This callback is called by secure code thanks to the registration
  *         done by the non-secure application with non-secure callable API
  *         SECURE_RegisterCallback(GTZC_ERROR_CB_ID, (void *)SecureError_Callback);
  * @retval None
  */
void SecureError_Callback(void)
{
  /* Go to error infinite loop when Secure error generated by GTZC check */
  /* because of illegal access */

  Error_Handler();
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

  /* IllegalMemoryAccessDetected variable is expected to be set to 1 */
  /* after the SecureFault generation */

  /* LED3 on */
  //HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
  /*Message error*/

  /* Infinite loop */
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
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

  /* Infinite loop */
  while (1)
  {
  }
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
