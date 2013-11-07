#ifndef CURRENT_DETECT_H_
#define CURRENT_DETECT_H_

void init_adc();
unsigned int ad_convert();
void fast_ad_convert();
void current_detect();

#endif /* CURRENT_DETECT_H_ */