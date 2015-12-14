#include "ports.h"
#include "clock.h"
volatile time_type tick;	//Sparar antalet avbrottsticks

extern void clear_i(void);	//Assemblerrutin, nollställ i-flaggan
extern void IRQ_r(void);	//Assemblerrutin, avbrottsrutin

void init_clock(void){
	IRQ_VEC = IRQ_r;
	clear_i();
}
void clock_inter(void){

}

time_type get_time(void){
 return 0;
}
void hold(time_type time){

}

