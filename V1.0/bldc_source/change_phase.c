/*
 * change.c
 *
 * Created: 2013/4/18 星期四 22:27:12
 *  Author: 聪
 */
/*
相位从0开始一次为ab,ac,bc,ba,ca,cb
*/
#include "main.h"
void change_phase()
{
    unsigned char sense_flag = 0;
    do
    {
        if (SENSE_H) sense_flag = 1;
        else sense_flag = 0;//这里flag用来表示在中断以后还是否满足换相条件，用于屏蔽消磁事件

        switch (phase) //此处为控制换相，已经屏蔽消磁事件
        {
        case 0:
            if (sense_flag)
            {
				MOS_TEMP_OFF
                MOS_A_H;
                MOS_C_L;
                ANALOG_B;
                ANALOG_FALLING;
                phase++;
                count_change_phase++;

            }

            break;

        case 1:
            if (!sense_flag)
            {
				MOS_TEMP_OFF
                MOS_C_L;
                MOS_B_H;	
                ANALOG_A;
                ANALOG_RISING;
                phase++;
                count_change_phase++;
            }

            break;

        case 2:
            if (sense_flag)
            {
				MOS_TEMP_OFF
                MOS_B_H;
                MOS_A_L;			
                ANALOG_C;
                ANALOG_FALLING;
                phase++;
                count_change_phase++;

            }

            break;

        case 3:
            if (!sense_flag)
            {
				MOS_TEMP_OFF;
                MOS_A_L;
                MOS_C_H;				
                ANALOG_B;
                ANALOG_RISING
                phase++;
                count_change_phase++;
            }

            break;

        case 4:
            if (sense_flag)
            {
				MOS_TEMP_OFF
                MOS_C_H;
                MOS_B_L;
                ANALOG_A;
                ANALOG_FALLING
                phase++;
                count_change_phase++;
            }

            break;

        case 5:
            if (!sense_flag)
            {
				MOS_TEMP_OFF
                MOS_B_L;
                MOS_A_H;
                ANALOG_C;
                ANALOG_RISING
                phase = 0;
                count_change_phase++;
            }

            break;
        }
    }
    while ( (sense_flag && SENSE_H) || (sense_flag && SENSE_L));
}
