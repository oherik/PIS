#include "clock.h"
#include "drill.h"

void main(void){
double pattern[21] = { 0, 1, 1, 1, 1, 1, 1, 1, 2, 1, 5, 2, 2, 2, 2, 4, 4, 3, 8, 2, 0xFF}; 
int* pattern_ptr = pattern;
time_type time;
unsigned int time_sec;

init_clock();
while(1){
	time = get_time();
	time_sec = time/1000;
	hold((time_type)1000);
	}
}
