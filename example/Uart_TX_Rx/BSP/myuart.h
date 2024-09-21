
#ifndef __MYUART_H
#define __MYUART_H

#include "main.h"
#include "stdbool.h"
#include "usart.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdarg.h"
#include "stdlib.h"

#define PACKSIZE 64   //串口发送和串口接收缓冲区大小
#define USE_DMA 1     //0：不使用DMA，1：使用DMA
#define USE_CACHE 0   //0：不使用Cache，1：使用Cache，只有H7系列需要


typedef struct {
    uint8_t Rxbuffer[PACKSIZE];           
    uint8_t RxPjbuffer[PACKSIZE];         
    uint8_t Txbuffer[PACKSIZE];           
    UART_HandleTypeDef *huart;                
    __IO bool RxFinish;                        
}Uart_It;

void Uart_Send_DMA(Uart_It*uart,char *fmt, ...);//串口DMA发送，类似printf的用法
void Uart_Receive_DMA(Uart_It*uart,uint16_t RxSize);//串口DMA接收，初始化中调用一次启动串口空闲中断，串口空闲中断回调函数中再次调用
#endif