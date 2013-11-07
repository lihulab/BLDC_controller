/*
 * timer.c
 *
 * Created: 2013/4/16 星期二 9:20:26
 *  Author: 聪
 */
#include "main.h"
volatile unsigned int count_ms = 0;
volatile unsigned int count_us = 0;
void init_timer()
{
    TCCR2 = 0x0c;
    TIMSK |= (1 << OCIE2);
	OCR2 = 250;
}

ISR (TIMER2_COMP_vect)
{
	count_ms++;
	rev_timer++;
	if(rev_timer == 200)
	{
		rev_flag = 1;
		rev_timer = 0;
	}		
}

//毫秒延时函数
void delayms (unsigned int target_time)
{
	count_ms = 0;
	while(count_ms!=target_time);
}
void delayus(unsigned int target_time)//只用于换相延时30电角度用
{
	count_us = 0;
	//while(count_us!=target_time);
}
/*
*两个用于自检的不定时延时函数
*/
unsigned char Delay (unsigned int time)
{
    while (time--);
    return 0;
}
