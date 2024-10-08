#include "key.h"

/**
 * @brief  Read the key number,Long and short presses can be recognized
 * @param  LongKeyMode             key mode address
 * @retval key number address,if 0 is returned, no key has been pressed
 */
const uint16_t ShortKey=8;//count number of short presses
const uint16_t LongKey=40;//count number of long presses

uint8_t Key_Read(bool *LongKeyMode){	
	static uint8_t number;
	static bool KeyUp=true;
	static uint16_t count=0;

	if(KEY1==0) count++, number=1,KeyUp=false;
	else if(KEY2==0) count++, number=2,KeyUp=false;
	else if(KEY3==0) count++, number=3,KeyUp=false;
	else if(KEY4==0) count++, number=4,KeyUp=false;
	else KeyUp=true;

	if(KeyUp==true){
		//elimination buffeting of keystroke
		if(count<ShortKey){
			count=0;
			number=0;
			return 0;
		}
		//short presses
		else if(count>=ShortKey&&count<=LongKey){
			count=0;		
			return number;
		}
		//long presses
		else /*if(count>=LongKey)*/{
			count=0;	
			*LongKeyMode=true;	
			return number;
		}
	}
	else return 0;	
}
