#include "clock.h"
#include "ports.h"

#ifdef SIMULATOR
	#define DIVIDER 0x10
   #define RATIO 130
#else
	#define DIVIDER 0x49
   #define RATIO 1
#endif

static volatile time_type millis;
port8	crgintshadow, crgflgshadow;

extern void clear_i(void);	//Assemblerrutin, nollställ i-flaggan
extern void IRQ_r(void);	//Assemblerrutin, avbrottsrutin

void init_clock(void){
int tst;
	//Nollställ variabler
	millis = 0;
	crgflgshadow = 0;
	
	//Sätt avbrottstid
	tst = DIVIDER;
	RTICTL = tst;
	
	//Aktivera avbrott i CRG
	crgintshadow = 0x80;
	CRGINT = crgintshadow;
	
	//På med avbrottsurtinen
	IRQ_VEC = IRQ_r;
	
	//Nollställ i-flaggan
	clear_i();
}
void clock_inter(void){
	millis+=RATIO;
	crgflgshadow |= 0x80L;
	CRGFLG = crgflgshadow;
}

time_type get_time(void){
	return millis;
}
void hold(time_type time){
	time_type start_time = get_time();
	while(get_time()<(start_time+time)){
	}					//busy wait
}

