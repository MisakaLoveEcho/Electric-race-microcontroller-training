#include "myuart.h"

//使用DMA时，检测串口DMA准备就绪
#if USE_DMA
    #define _UART_NOT_READY(huart)  \
        (huart->gState != HAL_UART_STATE_READY ||(huart->hdmatx && huart->hdmatx->State != HAL_DMA_STATE_READY))
#else 
    #define _UART_NOT_READY(huart) huart->gState != HAL_UART_STATE_READY
#endif
/**
 * @brief  向目标串口DMA发送
 * @param  uart             串口结构体句柄
 * @param  fmt              类似printf的格式化字符串
 * @retval 发送的字节数
 */
void Uart_Send_DMA(Uart_It*uart,char *fmt, ...){        
    va_list ap;  
    va_start(ap, fmt); 
		while(_UART_NOT_READY(uart->huart)){} //等待串口准备完成
    int sendLen = vsnprintf((char*)uart->Txbuffer, PACKSIZE, fmt, ap);
//使用Cache的情况下，手动将数据写入内存    
#if USE_CACHE   
    SCB_CleanInvalidateDCache_by_Addr((uint32_t*)uart->Txbuffer,(sendLen+31)/32*32);
#endif 
    
		HAL_UART_Transmit_DMA(uart->huart,uart->Txbuffer,sendLen);
    va_end(ap);
}

/**
 * @brief  配置串口DMA空闲接收中断
 * @param  uart             串口结构体句柄
 * @param  RxBuffer         串口接收数据长度
 * @retval 发送的字节数
 */
void Uart_Receive_DMA(Uart_It*uart,uint16_t RxSize){
    if(RxSize) uart->RxFinish=true;
    
    memset(uart->RxPjbuffer,0,sizeof(uart->RxPjbuffer));
    memcpy(uart->RxPjbuffer,uart->Rxbuffer,RxSize);
    
    memset(uart->Rxbuffer,0,RxSize);
//使用Cache的情况下，手动将数据写入内存    
#if USE_CACHE     
    SCB_CleanInvalidateDCache_by_Addr((uint32_t*)uart->Rxbuffer,(UartPackSize+31)/32*32);
#endif
    HAL_UARTEx_ReceiveToIdle_DMA(uart->huart,uart->Rxbuffer, PACKSIZE);  
}

int fputc(int ch, FILE *f)
{
	//具体哪个串口可以更改huart1为其它串口
	HAL_UART_Transmit(&huart1 , (uint8_t *)&ch, 1 , 0x0f);
	return ch;
}
