#ifndef __FFT_H__
#define __FFT_H__

#include "arm_math.h"
#include "arm_const_structs.h"

#define FFT_LENGTH 4096  //定义FFT的长度，范围16——4096，只能是2的幂指数
void FFT_Start(float *FFTValueBuff);
extern float fft_outputbuf[FFT_LENGTH]; 

#endif