#ifndef __FLITER_H
#define __FLITER_H

#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "arm_math.h"


#define ADC_SAMPLE_SIZE 4096
#define ADC_FIFO_SAMPLES (ADC_SAMPLE_SIZE >> 1)

void arm_fir_f32_lp(float *testInput_f32_1000Hz);
extern float testOutput[ADC_FIFO_SAMPLES];
#endif