#ifndef CHANGE_PHASE_H_
#define CHANGE_PHASE_H_

void change_phase();

#define MOS_OFF {PWM_OFF;}//还要根据Mos l的io关闭负极的mos
#define MOS_A_H {TCCR0=0x69; TCCR1A=0xa1; TCCR1B=0x09; DDRD=0x20; DDRB &= ~0x08;}
#define MOS_B_H {TCCR0=0x69; TCCR1A=0xa1; TCCR1B=0x09; DDRD=0x10; DDRB &= ~0x08;}
#define MOS_C_H {TCCR0=0x69; TCCR1A=0xa1; TCCR1B=0x09; DDRD=0x80; DDRB |= 0x08;}//控制pwm输出的开关，同样注意开启pwm输出的同时关闭其它的pwm
#define MOS_A_L {PORTC &= ~0x06; PORTC |= 0x01;}
#define MOS_B_L {PORTC &= ~0x05; PORTC |= 0x02;}
#define MOS_C_L {PORTC &= ~0x03; PORTC |= 0x04;}//根据实际情况填入连接负极的io口，注意打开mos的同时关闭其它两个mos
#define ANALOG_A ADMUX = 0x01;//用于切换比较器的反向输入端(注意这里不能使用|=的形式)
#define ANALOG_B ADMUX = 0x02;
#define ANALOG_C ADMUX = 0x03;
#define ANALOG_FALLING ACSR &= ~0x01;//用于切换模拟比较器中断模式，书上说必须先清零中断允许位？
#define ANALOG_RISING ACSR |= 0x03;
#define SENSE ((ACSR & 0x10))
#define SENSE_L (!(ACSR & 0x20))
#define SENSE_H (ACSR & 0x20)
#define MOS_TEMP_OFF {DDRD = 0x00;PORTD = 0x00; PORTC = 0x00;}



#endif /* CHANGE_PHASE_H_ */
