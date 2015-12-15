#include "ports.h"
#include "drill.h"
#include "clock.h"

static unsigned int DCShadow;

void Outone(int bit){		//Sätter en bit i borren till 1
	unsigned int mask = 1;
	if(bit>7 || bit <0){
		return;
	} else {
		mask = mask << bit;
		DCShadow = DCShadow | mask;
		DRILL = DCShadow;
	}
}

void Outzero(int bit){ 		//Sätter en bit i borren till 0
	unsigned int mask = 1;
	if(bit>7 || bit <0){
		return;
	} else {
		mask = mask << bit;
		DCShadow = DCShadow & ~mask;
		DRILL = DCShadow;
	}
}

void MotorStart(void){
	if(DCShadow & 0x02 == 0){		//Kolla om motorn är startad
		Outone(2);
		hold((time_type)1000);	
	}
}

void MotorStop(void){
	Outzero(2);
}

void DrillDown(void){
	Outone(3);
}

void DrillUp(void){
	Outzero(3);
}

void Alarm(int count){
	while(count>0){
		Outone(4);
		hold((time_type)1000);
		Outzero(4);
		count--;
		if(count == 0){
			hold((time_type)500);
		}
	}
}

int Step(void){
	unsigned int status = DRILLSTATUS;
	if(status & 0x02 == 0){
		Alarm(2);
		return 0;
	}
	Outone(1);
	Outone(0);
	hold((time_type)500);
	Outzero(0);
	return 1;

}

int NStep(int steps){
int error;
	while(steps>0){
		error = Step();
		if(error == 0){
			return 0;
		}
	}
	return 1;
}

int DrillDownTest(void){
	char tries = 20;
	unsigned int status;
	while((status & 0x04 != 0)){
		status = DRILLSTATUS;
		if(tries == 0){
			Alarm(2);
			return 0;
		} else{
			hold((time_type)250);
			tries--;
		}
	}
	return 1;
}


int DrillHole(void){
	int error; 
	DrillDown();
	error = DrillDownTest();
	DrillUp();
	return error;
}


int DrillDownTest(void);
int RefPos(void);
void DoAuto(void);
