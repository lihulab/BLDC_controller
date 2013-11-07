/*
 * pwm.c
 *
 * Created: 2013/4/16 星期二 9:19:59
 *  Author: 聪
 */
#include "main.h"
volatile unsigned char highduty = 0;
void init_pwm_a()
{
    TCCR0 = 0x6d;//快速pwm模式，比较匹配置位，不分频
    OCR0 = highduty;
    TIMSK |= (1 << TOIE0);
}

ISR (TIMER0_OVF_vect)
{
    OCR0 = highduty;
}

void init_pwm_bc() //16位定时器已经修改，等待测试
{
    TCCR1A = 0xa1;//双8位pwm输出，比较匹配置位
    TCCR1B = 0x0d;//不分频
    OCR1A = highduty;
    OCR1B = highduty;
    TIMSK |= (1 << TOIE1);
}

ISR (TIMER1_OVF_vect)
{
    OCR1A = highduty;
    OCR1B = highduty;
}

void setpwm (unsigned char PWM)
{

    highduty = PWM;
	
    /*
    if (current > limit_current)
    {
        MOS_OFF;
        blink (10); //暂时设定为10，以后根据需要进行更改
    }
    */
}
