#include "ports.h"
#include "drill.h"

static unsigned int DCShadow;

void Outone(int bit){	//Sets a bit in DCShadow to 1
	unsigned int mask = 1;
	if(bit>7 || bit <0){
		return;
	} else {
		mask = mask << bit;
		DCShadow = DCShadow | mask;	
	}
}

void Outzero(int bit){ //Sets a bit in DCShadow to 0
unsigned int mask = 1;
	if(bit>7 || bit <0){
		return;
	} else {
		mask = mask << bit;
		DCShadow = DCShadow & ~mask;	
	}


}

void MotorStart(void);
void MotorStop(void);
void DrillDown(void);
void DrillUp(void);
int Nste(int);
int DrillDownTest(void);
void Alarm(int);
void DrillHole(void);
int RefPos(void);
void DoAuto(void);
void Outzero(int);
void Outone(int);
