
void blink (unsigned char);
//----------------------------------------------------
//启动部分
//----------------------------------------------------
#ifndef _START_H_
#define _START_H_

void phase_en();
unsigned char start (unsigned char pwm_start);
void Wait(unsigned char dauer);
void init_usart();
void usart_send(unsigned char data);
void usart_send_string(unsigned char data[]);
void rev_count();
#define ANALOG_ACIE_OFF (ACSR &= ~(1 << ACIE))
#define ANALOG_ACIE_ON (ACSR |= (1 << ACIE))
#define BAUD 2400
#endif // _START_H_

//----------------------------------------------------
//MOS自检部分
//----------------------------------------------------

#define HIGH_A_ON {DDRD |= 0x20; PORTD |= 0x20;}//这六个宏为自检函数要用的
#define HIGH_B_ON {DDRD |= 0x10; PORTD |= 0x10;}
#define HIGH_C_ON {DDRD |= 0x80; PORTD |= 0x80;}
#define HIGH_A_OFF {DDRD |= 0x20; PORTD &= ~0x20;}
#define HIGH_B_OFF {DDRD |= 0x10; PORTD &= ~0x10;}
#define HIGH_C_OFF {DDRD |= 0x80; PORTD &= ~0x80;}
#define LOW_A_ON {PORTC |= 0x01;}
#define LOW_B_ON {PORTC |= 0x02;}
#define LOW_C_ON {PORTC |= 0x04;}
#define LOW_A_OFF {PORTC &= ~0x01;}
#define LOW_B_OFF {PORTC &= ~0x02;}
#define LOW_C_OFF {PORTC &= ~0x04;}