#include "clock.h"
#include "ports.h"

#define setbit(x, bit) (x) |= (1 << (bit))
#define clearbit(x, bit) (x) &= ~(1 << (bit)) 

volatile time_type tick;	//Sparar antalet avbrottsticks
port8	crgintshadow, crgflgshadow;

extern void clear_i(void);	//Assemblerrutin, nollställ i-flaggan
extern void IRQ_r(void);	//Assemblerrutin, avbrottsrutin

void init_clock(void){
	tick = 0;
	crgintshadow = 0;
	crgflgshadow = 0;
	
	RTICTL = 1;
	
	setbit(crgintshadow,7);
	CRGINT = crgintshadow;
	
	IRQ_VEC = IRQ_r;
	clear_i();
}
void clock_inter(void){
	tick++;
	setbit(crgflgshadow, 7);
	CRGFLG = crgflgshadow;
}

time_type get_time(void){
	//beräkna? 
	return tick/10;
}
void hold(time_type time){

}

