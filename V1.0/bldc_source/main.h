#ifndef MAIN_H_
#define MAIN_H_
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include "analog.h"
#include "pwm.h"
#include "timer.h"
#include "change_phase.h"
#include "Variable.h"
#include "function.h"
#define RED_ON PORTC |= 0x80;
#define RED_OFF PORTC &= ~0x80;//红色为错误指示灯
#define GREEN_OFF PORTC &= ~0x40;
#define GREEN_ON PORTC |= 0x40;//绿色为工作指示灯
#define RED_LED 0x40//绿色led的io
#define PWM_OFF {OCR1A = 0; OCR1B = 0; OCR0 = 0; TCCR1A = 0x01; TCCR0 = 0x61; DDRD &= ~0xb0;}
#endif /* MAIN_H_ */
