#include "clock.h"

void main(void){
time_type time;
unsigned int time_sec;
init_clock();
while(1){
	time = get_time();
	time_sec = time/1000;
	hold((time_type)1000);
	}
}
