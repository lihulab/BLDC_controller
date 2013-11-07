#include "main.h"

int main (void)
{
	DDRA &= ~0x07;
	DDRB &= ~0xff;
	DDRC |= 0xFF;
	DDRD |= 0x20;
	DDRC &= ~0x80;
	init_analog();
    init_pwm_a();
    init_pwm_bc();
	init_usart();
	init_timer();
    asm ("sei"); //开总中断
	//start(15);
	ANALOG_ACIE_ON;//打开比较器中断
    while (1)
    {
		if(rev_flag == 1)
		{
			rev_flag = 0;
			rev_count();
		}
		setpwm(pwm);
    }
}
