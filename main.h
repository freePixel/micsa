/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define ROW1_Pin GPIO_PIN_0
#define ROW1_GPIO_Port GPIOC
#define ROW2_Pin GPIO_PIN_1
#define ROW2_GPIO_Port GPIOC
#define COL2_Pin GPIO_PIN_0
#define COL2_GPIO_Port GPIOA
#define COL1_Pin GPIO_PIN_1
#define COL1_GPIO_Port GPIOA
#define ROW4_Pin GPIO_PIN_4
#define ROW4_GPIO_Port GPIOA
#define D3_Pin GPIO_PIN_7
#define D3_GPIO_Port GPIOA
#define BUZZER_Pin GPIO_PIN_4
#define BUZZER_GPIO_Port GPIOC
#define ROW3_Pin GPIO_PIN_0
#define ROW3_GPIO_Port GPIOB
#define SEGG_Pin GPIO_PIN_10
#define SEGG_GPIO_Port GPIOB
#define SEGB_Pin GPIO_PIN_6
#define SEGB_GPIO_Port GPIOC
#define D1_Pin GPIO_PIN_7
#define D1_GPIO_Port GPIOC
#define SEGA_Pin GPIO_PIN_8
#define SEGA_GPIO_Port GPIOC
#define SEGP_Pin GPIO_PIN_8
#define SEGP_GPIO_Port GPIOA
#define D0_Pin GPIO_PIN_9
#define D0_GPIO_Port GPIOA
#define SEGC_Pin GPIO_PIN_10
#define SEGC_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SEGD_Pin GPIO_PIN_3
#define SEGD_GPIO_Port GPIOB
#define SEGF_Pin GPIO_PIN_4
#define SEGF_GPIO_Port GPIOB
#define SEGE_Pin GPIO_PIN_5
#define SEGE_GPIO_Port GPIOB
#define D2_Pin GPIO_PIN_6
#define D2_GPIO_Port GPIOB
#define COL3_Pin GPIO_PIN_8
#define COL3_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
