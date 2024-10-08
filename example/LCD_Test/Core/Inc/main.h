/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

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
#define LCD_CS_Pin GPIO_PIN_3
#define LCD_CS_GPIO_Port GPIOE
#define LCD_RST_Pin GPIO_PIN_4
#define LCD_RST_GPIO_Port GPIOE
#define LCD_DC_Pin GPIO_PIN_5
#define LCD_DC_GPIO_Port GPIOE
#define RGB_B_Pin GPIO_PIN_13
#define RGB_B_GPIO_Port GPIOC
#define RGB_G_Pin GPIO_PIN_14
#define RGB_G_GPIO_Port GPIOC
#define RGB_R_Pin GPIO_PIN_15
#define RGB_R_GPIO_Port GPIOC
#define KEY1_Pin GPIO_PIN_0
#define KEY1_GPIO_Port GPIOC
#define KEY2_Pin GPIO_PIN_1
#define KEY2_GPIO_Port GPIOC
#define KEY3_Pin GPIO_PIN_2
#define KEY3_GPIO_Port GPIOC
#define KEY4_Pin GPIO_PIN_3
#define KEY4_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
