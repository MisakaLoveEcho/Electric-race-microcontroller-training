#include "fft.h"

static float fft_inputbuf[FFT_LENGTH * 2];  //FFT需要分开输入实部和虚部，所以实际长度是定义长度的两倍
    //FFT结果输出
float fft_outputbuf[FFT_LENGTH];
//进行快速傅里叶正变换
void FFT_Start(float *FFTValueBuff){
    for (int i = 0; i < FFT_LENGTH; i++)
    {
        fft_inputbuf[i * 2] = FFTValueBuff[i];//将传入的值保存在实部
        fft_inputbuf[i * 2 + 1] = 0;//虚部赋值，固定为0.
    }
    arm_cfft_f32(&arm_cfft_sR_f32_len4096, fft_inputbuf, 0, 1);//FFT函数，对输入数据进行快速傅里叶变换
/*  
    参数1：FFT参数结构体，可以使用官方设计好的参数，根据数据长度选择不同参数
    参数2：数据输入数组
    参数3：为0，正变换，为1，逆变换
    参数4：为0，禁用输出反转，为1，使能输出反转
    计算结果保存在fft_inputbuf中，以复数形式保存，Z=a+bi，相位=arctan（b/a），取模为幅值
*/    
    arm_cmplx_mag_f32(fft_inputbuf, fft_outputbuf, FFT_LENGTH);//计算FFT结果的幅度值
/*
    参数1：复数输入数组
    参数2：复数输出保存数组
    参数3：数据长度
*/ 
		float VPP=FFT_LENGTH;
		float VPP2=(float)FFT_LENGTH/2.0f;
    fft_outputbuf[0] /= VPP;
    for (int i = 1; i < FFT_LENGTH; i++)//输出各次谐波幅值
    {
        fft_outputbuf[i] /= VPP2;
    }
}





