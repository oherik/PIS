#include "clock.h"
#include "displayML15.h"

void main(void){
time_type time;
unsigned int time_sec;
init_clock();
while(1){
	time = get_time();
	time_sec = time/1000;
	display_dec(time_sec);
	hold((time_type)1000);
	}
}
