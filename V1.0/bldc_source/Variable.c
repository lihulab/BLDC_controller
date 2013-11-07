/*
 * Variable.c
 *
 * Created: 2013/4/23 星期二 22:52:18
 *  Author: 聪
 *这个文件用于存储所有的全局变量
 */
#ifndef   _VARIABLE_C_
#define   _VARIABLE_C_
volatile unsigned char phase = 0;
volatile unsigned int count_change_phase = 0;
volatile unsigned int pwm = 50;
volatile unsigned int rev = 0;
volatile unsigned int rev_timer = 0;
volatile unsigned char rev_flag = 0;
volatile unsigned int delay;//通用延时变量
unsigned int set_rev = 1200;
#endif
