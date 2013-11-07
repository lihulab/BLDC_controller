#ifndef TIMER_H_
#define TIMER_H_
void init_timer();
unsigned int SetDelay (unsigned int t);
char CheckDelay (unsigned int t);
void delayms (unsigned int t);
unsigned char Delay (unsigned int time);
unsigned char DelayM (unsigned int time);
unsigned int set(unsigned int t);
char check(unsigned int time);
void delayus(unsigned int w);
extern volatile unsigned int count_us;
extern volatile unsigned int count_ms;
#endif /* TIMER_H_ */
