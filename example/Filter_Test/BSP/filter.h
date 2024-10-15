#ifndef __FILTER_H
#define __FILTER_H

#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "arm_math.h"


#define FILTER_SIZE 4096

void arm_fir_f32_lp(float *testInput_f32_1000Hz);
extern float testOutput[FILTER_SIZE];
#endif