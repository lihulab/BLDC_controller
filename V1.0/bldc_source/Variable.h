/*
 * Variable.h
 *
 * Created: 2013/4/23 星期二 22:52:28
 *  Author: 聪
 */


#ifndef VARIABLE_H_
#define VARIABLE_H_
extern volatile unsigned char phase;
extern volatile unsigned int count_change_phase;
extern volatile unsigned int pwm;
extern volatile unsigned int rev;
extern volatile unsigned int rev_timer;
extern volatile unsigned int delay;
extern volatile unsigned char rev_flag;
extern unsigned int set_rev;
#endif /* VARIABLE_H_ */
