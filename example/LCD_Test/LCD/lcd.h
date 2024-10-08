/***************************************************************************** 
此文件为ST7789LCD驱动文件，驱动芯片一致时，可以更改长宽适配不同分辨率屏幕
该文件通过宏定义可更改不同模式：
1.竖屏或横屏显示
2.软件或硬件SPI
3.硬件SPI的DMA传输
4.添加LVGL底层驱动支持

                        CUBEMX的SPI配置
Mode:Full-Duplex Master 或 Transmis Only Master
Data Size:8Bit
First Bit:MSB
Clock Polarity(CPOL):High
Clock Phase(CPHA):1Edge
DMA:SPI_TX,normal Mode
可以不用开启SPI中断
********************************************************************************/


#ifndef __LCD_H
#define __LCD_H

#include "main.h"
#include "spi.h"

#define USE_HORIZONTAL 3  // 设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏
#define USE_ANALOG_SPI 0	// 可选的软件SPI或者硬件SPI		0: 硬件SPI  1: 软件SPI
#define USE_DMA_MODE 1     //0：不使用DMA    1：使用DMA	(仅当使用硬件SPI时)

#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
    #define LCD_W 135
    #define LCD_H 240

#else
    #define LCD_W 240
    #define LCD_H 135
#endif

//-----------------LCD引脚定义---------------- 
#if USE_ANALOG_SPI
    #define LCD_SCLK_Clr() HAL_GPIO_WritePin(LCD_SCK_GPIO_Port,LCD_SCK_Pin, GPIO_PIN_RESET)//SCL=SCLK
    #define LCD_SCLK_Set() HAL_GPIO_WritePin(LCD_SCK_GPIO_Port,LCD_SCK_Pin, GPIO_PIN_SET)
    #define LCD_MOSI_Clr() HAL_GPIO_WritePin(LCD_SDA_GPIO_Port,LCD_SDA_Pin, GPIO_PIN_RESET)//SDA=MOSI
    #define LCD_MOSI_Set() HAL_GPIO_WritePin(LCD_SDA_GPIO_Port,LCD_SDA_Pin, GPIO_PIN_SET)
#else 
    #define LCDSPI hspi4   //这里改为自己使用的spi
#endif

#define LCD_RST_Clr()  HAL_GPIO_WritePin(LCD_RST_GPIO_Port,LCD_RST_Pin, GPIO_PIN_RESET)//RES
#define LCD_RST_Set()  HAL_GPIO_WritePin(LCD_RST_GPIO_Port,LCD_RST_Pin, GPIO_PIN_SET)

#define LCD_DC_Clr()   HAL_GPIO_WritePin(LCD_DC_GPIO_Port,LCD_DC_Pin, GPIO_PIN_RESET)//DC
#define LCD_DC_Set()   HAL_GPIO_WritePin(LCD_DC_GPIO_Port,LCD_DC_Pin, GPIO_PIN_SET)
 		     
#define LCD_CS_Clr()   HAL_GPIO_WritePin(LCD_CS_GPIO_Port,LCD_CS_Pin, GPIO_PIN_RESET)//CS
#define LCD_CS_Set()   HAL_GPIO_WritePin(LCD_CS_GPIO_Port,LCD_CS_Pin, GPIO_PIN_SET)

void LCD_Init(void); //LCD初始化
void LCD_Writ_Bus(uint8_t dat);	// 模拟SPI时序
void LCD_WR_DATA8(uint8_t dat);	// 写入一个字节
void LCD_WR_DATA(uint16_t dat);	// 写入两个字节
void LCD_WR_REG(uint8_t dat);	// 写入一个指令
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2); // 设置坐标函数

void LCD_Fill(uint16_t xsta,uint16_t ysta,uint16_t xend,uint16_t yend,uint16_t color); // 指定区域填充颜色
void LCD_DrawPoint(uint16_t x,uint16_t y,uint16_t color); // 在指定位置画一个点
void LCD_DrawLine(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color); // 在指定位置画一条线
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,uint16_t color); // 在指定位置画一个矩形
void Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r,uint16_t color); // 在指定位置画一个圆

void LCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint16_t fc,uint16_t bc,uint8_t sizey,uint8_t mode);				// 显示一个字符
void LCD_ShowString(uint16_t x,uint16_t y,const uint8_t *p,uint16_t fc,uint16_t bc,uint8_t sizey,uint8_t mode); // 显示字符串
uint32_t mypow(uint8_t m,uint8_t n); // 求幂
void LCD_ShowIntNum(uint16_t x,uint16_t y,uint16_t num,uint8_t len,uint16_t fc,uint16_t bc,uint8_t sizey); // 显示整数变量
void LCD_ShowFloatNum1(uint16_t x,uint16_t y,float num,uint8_t len,uint16_t fc,uint16_t bc,uint8_t sizey); // 显示两位小数变量

void LCD_ShowPicture(uint16_t x,uint16_t y,uint16_t length,uint16_t width,const uint8_t pic[]); //显示图片


//画笔颜色

#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE           	 0x001F  
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //棕色
#define BRRED 			 0XFC07 //棕红色
#define GRAY  			 0X8430 //灰色
#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色
#define GRAYBLUE       	 0X5458 //灰蓝色
#define LIGHTGREEN     	 0X841F //浅绿色
#define LGRAY 			 0XC618 //浅灰色(PANNEL),窗体背景色
#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)
#endif
