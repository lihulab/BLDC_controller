#include "main.h"
#include <math.h>
void Wait(unsigned char dauer)
//############################################################################
{
	dauer = (unsigned char)TCNT0 + dauer;
	while((TCNT0 - dauer) & 0x80);
}
//----------------------------------------------------
//启动部分
//----------------------------------------------------
unsigned char start (unsigned char pwm_start) //成功返回0，失败返回1
{
    unsigned int i,temp = 0,times = 300;//没必要用long吧？
	usart_send_string("begin start");
    ANALOG_ACIE_OFF;
    setpwm (5);
    phase_en();
    setpwm (15);
    while (1)
    {
		for (i=0;i<times;i++)
		{
			_delay_ms(1);
		}
		times -= times / 15 + 1;
        if (times < 15)
		{
			return 1;
		}
        phase_en();
        phase ++;
        phase %= 6;
        setpwm (pwm_start);
    }


}
/*
*开关对应相位的MOS管
*顺序依次为：ab,ac,bc,ba,ca,cb
*/
void phase_en()
{
    switch (phase)
    {
    case 0:
        MOS_A_H;
        MOS_B_L;
        ANALOG_C;
        ANALOG_RISING;
        break;

    case 1:
        MOS_A_H;
        MOS_C_L;
        ANALOG_B;
        ANALOG_FALLING;
		break;

    case 2:
        MOS_B_H;
        MOS_C_L;
        ANALOG_A;
        ANALOG_RISING;
        break;

    case 3:
        MOS_B_H;
        MOS_A_L;
        ANALOG_C;
        ANALOG_FALLING;
		break;

    case 4:
        MOS_C_H;
        MOS_A_L;
        ANALOG_B;
        ANALOG_RISING;
        break;

    case 5:
        MOS_C_H;
        MOS_B_L;
        ANALOG_A;
        ANALOG_FALLING;
		break;
    }
}
void blink (unsigned char i)
{
    while (i--)
    {
        _delay_ms(500);
        RED_ON;
        _delay_ms(500);
        RED_OFF;
    }
}
void init_usart()
{
	UBRRH = 0x00;
	UBRRL = 0x67;
	UCSRB = (1<<TXEN);
	UCSRC = (1<<URSEL)|(3<<UCSZ0);
}
void usart_send(unsigned char data)
{
	while(!(UCSRA & (1 << UDRE)));
	UDR = data;
}
void usart_newline()
{
	usart_send (0x0d);
	usart_send (0x0a);
}
void usart_send_string(unsigned char data[])
{
	int i;
	for(i=0;data[i]!=0;i++)
	{
		usart_send(data[i]);
	}
	usart_newline();
}

void rev_count()
{
	unsigned char str[10];
	int temp_pwm = 0;
	double pGain = 0.0015;
	double iGain = 0.0005;
	double dGain = 0.0055;
	static long int ierror = 0;
	static int error = 0,error_last = 700;
	rev = count_change_phase*300.0/42.0; //0.2秒检查一次转速，转速为转每分钟
	count_change_phase = 0;
	error_last = error;
	error = set_rev - rev;
	if((error < 150) && (error > (-150)))
	{
		ierror += error; 
		
	}
	sprintf(str,"ierror:%d",ierror);
	usart_send_string(str);
	temp_pwm = pwm + (int)(pGain * error) - (int)(dGain * abs(error_last - error)) + (int)(iGain * ierror);
	if((int)(iGain * ierror) != 0 ) ierror = 0;
	sprintf(str,"-------:%d",temp_pwm);
	usart_send_string(str);
	if((rev > 500) && (rev < 3000))
	{
		if((temp_pwm > 1) && (temp_pwm < 255)) pwm = temp_pwm;
	}
	else pwm = 50;		
	sprintf(str,"rev:%d",rev);
	usart_send_string(str);
	sprintf(str,"highduty:%d",pwm);
	usart_send_string(str);
}