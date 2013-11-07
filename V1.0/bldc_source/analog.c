/*
 * analog.c
 *
 * Created: 2013/4/19 星期五 15:20:14
 *  Author: 聪
 */
#include "main.h"
void init_analog()
{
    ACSR = 0x03;
    SFIOR = 0x08; //启动比较器多路输入
    ADMUX |= 0x01; //先设定为adc1输入
}
ISR (ANA_COMP_vect)
{
    change_phase();//检测到过零，启动换向
}
