#include "ports.h"
#include "drill.h"
#include "clock.h"

static unsigned int DCShadow = 0;

void Outone(int bit){		//Sätter en bit i borren till 1
	unsigned int mask = 1;
	if(bit>7 || bit <0){
		return;
	} else {
		mask = mask << bit;
		DCShadow = DCShadow | mask;
		//DRILL = DCShadow;
	}
}

void Outzero(int bit){ 		//Sätter en bit i borren till 0
	unsigned int mask = 1;
	if(bit>7 || bit <0){
		return;
	} else {
		mask = mask << bit;
		DCShadow = DCShadow & ~mask;
		//DRILL = DCshadow;
	}


}

void MotorStart(void){
	if(DCShadow & 0x02 == 0){		//Kolla om motorn är startad
		Outone(2);
		hold(1000);	
	}
}

void MotorStop(void);
void DrillDown(void);
void DrillUp(void);
int Nste(int);
int DrillDownTest(void);
void Alarm(int);
void DrillHole(void);
int RefPos(void);
void DoAuto(void);
