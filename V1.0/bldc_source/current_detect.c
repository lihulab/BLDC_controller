/*
 * current_detect.c
 *
 * Created: 2013/4/16 星期二 22:24:03
 *  Author: 聪
 */
#include "main.h"
#include <stdio.h>
unsigned int ad_convert() //在需要检测电流时打开aden，检测完成之后需要关闭
{
	unsigned char str[10];//串口用的
	unsigned char temp;//用来记录模拟比较器在admux里设定的反向输入端
	unsigned int current_temp=0;
	temp = ADMUX; //记录下admux原来的值
	ADMUX = 0x00; //指定adc输入通道
	SFIOR = 0x00; //关闭模拟比较器adc管脚复用
	ADCSRA = 0xd3;
	ADCSRA |= 0x40;
	while (((ADCSRA & 0x10) == 0));
	current_temp = ADCW;
	sprintf(str,"c:%d",current_temp);
	usart_send_string(str);
	ADMUX =temp;   // zurück auf den Sense-Kanal
	ADCSRA = 0x00;
	SFIOR |= 0x08;  // Analog Comperator ein
	return 0;
}
void fast_ad_convert()
{
    current = ad_convert();
    current_max = current_max > current ? current_max : current;
}
void current_detect()
{
    current = (ad_convert() + current * 7) / 8;
}