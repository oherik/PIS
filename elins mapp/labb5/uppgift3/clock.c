#include 	"clock.h"
#include	"ports3.h"

extern void avbrottsrutin(void);
extern void nollstalla_I_flaggan();

static volatile time_type tick;

void init_clock()
{
	//anropa assemblerrutin
	tick = 0;
	CRGINT = 0x80;		//aktivera avbrott från kretsen
	RTICLT = 0x10;		//sätt abbrottsintervall till korstast möjliga
	IRQ_VEC=avbrottsrutin;
	CLOCK_VEC=avbrottsrutin;
	nollstalla_I_flaggan(); 
}

void clock_inter()
{
	tick++;
	CRGFLG=0x80;
	nollstalla_I_flaggan();	
}

time_type get_time()
{
	return tick*10;
}

void hold(time_type ms)
{
	//anrpa get_time och se vad tiden är
	//lopa och kolla ifall tiden är rätt
	//fördröjer saker på borren
	time_type tiden=get_time();
	
	while((get_time()-tiden)<ms)
		{		
		}
}


