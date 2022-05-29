/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    Secure/Src/secure_nsc.c
  * @author  MCD Application Team
  * @brief   This file contains the non-secure callable APIs (secure world)
  ******************************************************************************
    * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* USER CODE BEGIN Non_Secure_CallLib */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "secure_nsc.h"
#include "arm_cmse.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** @addtogroup STM32L5xx_HAL_Examples
  * @{
  */

/** @addtogroup Templates
  * @{
  */

/* Global variables ----------------------------------------------------------*/
void *pSecureFaultCallback = NULL;   /* Pointer to secure fault callback in Non-secure */
void *pSecureErrorCallback = NULL;   /* Pointer to secure error callback in Non-secure */


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define MAX_STRING_LENGTH 0x400
//typedef int (*callbackptr_NS)(char const *s1, char GetTestCaseChar_NSE()) CMSE_NS_CALL;
//typedef int (*callbackptr_NS)(uint32_t s) CMSE_NS_CALL;
//funcptr_NS callback_NS;

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
extern uint32_t GetTestCaseNumber(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Secure registration of non-secure callback.
  * @param  CallbackId  callback identifier
  * @param  func        pointer to non-secure function
  * @retval None
  */
CMSE_NS_ENTRY void SECURE_RegisterCallback(SECURE_CallbackIDTypeDef CallbackId, void *func)
{
  if(func != NULL)
  {
    switch(CallbackId)
    {
      case SECURE_FAULT_CB_ID:           /* SecureFault Interrupt occurred */
        pSecureFaultCallback = func;
        break;
      case GTZC_ERROR_CB_ID:             /* GTZC Interrupt occurred */
        pSecureErrorCallback = func;
        break;
      default:
        /* unknown */
        break;
    }
  }
}


/* strnlen function implementation for arm compiler */
#if defined(__arm__)
size_t strnlen(const char *s, size_t maxLength)
{
    size_t length = 0;
    while ((length <= maxLength) && (*s))
    {
        s++;
        length++;
    }
    return length;
}
#endif

/*--------------------------------------------------------------------------------------------------*/
/*----------------------------------Printf non secure entry ---------------------------------------------------*/
CMSE_NS_ENTRY void DbgConsole_Printf_NSE(char const *s)
{
    size_t string_length;
    /* Access to non-secure memory from secure world has to be properly validated */
    /* Check whether string is properly terminated */
    string_length = strnlen(s, MAX_STRING_LENGTH);
    if ((string_length == MAX_STRING_LENGTH) && (s[string_length] != '\0'))
    {
        printf("Input data error: String too long or invalid string termination!\r\n");
        abort();

    }

/*---------------------------------------------------------------------------------------------------------------*/
    /* Check whether string is located in non-secure memory */
    /* Due to the bug in GCC 10 cmse_check_pointed_object() always fail, do not call it, see GCC Bugzilla - Bug 99157.
       Solved in GCC 10.3 version */
#if !((__GNUC__ == 10) && (__GNUC_MINOR__ < 3))
    if (cmse_check_address_range((void *)s, string_length, CMSE_NONSECURE | CMSE_MPU_READ) == NULL)
    {
        printf("Input data error: String is not located in non secure world!\r\n");
        abort();
    }
#endif
    printf(s);
}


CMSE_NS_ENTRY int DbgConsole_Scanf_NSE()
{
	int s;
	scanf("%d",&s);
	return s;
}

/*-----------------------------------------------------------------------------------------------------------------*/
/**
  * @}
  */

/*--------------------------------------------------------------------------------------------------*/
/*----------------------------------Non-secure callable (entry) function---------------------------------------------------*/
CMSE_NS_ENTRY uint32_t GetTestCaseNumber_NSE(void)
{
    return GetTestCaseNumber();
}

/*--------------------------------------------------------------------------------------------------*/
/*-----------Non-secure callable (entry) function, calling a non-secure callback function-----------*/
CMSE_NS_ENTRY int PinCompare_NSE(uint32_t s1)
{
	if(s1 == GetTestCaseNumber_NSE())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*--------------------------------------------------------------------------------------------------*/
/*---------------------------------------------LED CONTROL-----------------------------------------*/
CMSE_NS_ENTRY void Access_ok_toggle(void)
{
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_7);
}

CMSE_NS_ENTRY void Access_Nok_toggle(void)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_9);
}

/**
  * @}
  */
/* USER CODE END Non_Secure_CallLib */

