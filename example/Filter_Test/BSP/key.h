
#ifndef __KEY_H
#define __KEY_H

#include "main.h"
#include "stdbool.h"
#define KEY1 HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)
#define KEY2 HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin)
#define KEY3 HAL_GPIO_ReadPin(KEY3_GPIO_Port,KEY3_Pin)
#define KEY4 HAL_GPIO_ReadPin(KEY4_GPIO_Port,KEY4_Pin)

uint8_t Key_Read();

typedef enum{
	KEY_NONE = 0,
	
	KEY1_Short,
	KEY1_Long,
	
	KEY2_Short,
	KEY2_Long,
	
	KEY3_Short,
	KEY3_Long,
	
	KEY4_Short,
	KEY4_Long,

}KEY_ENUM;
#endif