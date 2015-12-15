#include "ports.h"
#include "drill.h"
#include "clock.h"

static unsigned char DCShadow;
static int pattern[21] = { 0, 1, 1, 1, 1, 1, 1, 1, 2, 1, 5, 2, 2, 2, 2, 4, 4, 3, 8, 2, 0xFF};


void DrillInit(void){
	DCShadow = 0;
}

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
	//if(DCShadow & 0x02 == 0){		//Kolla om motorn är startad
		Outone(2);
		hold((time_type)1000);	
	//}
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
	unsigned char status = DRILLSTATUS;
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

int Nstep(int steps){
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
	unsigned char status = DRILLSTATUS;
	while(tries > 0){
		status = DRILLSTATUS;
		if((status & 4) != 0){
			return 1;
		} else {
			hold((time_type)250);
			tries = tries - 1;
		}
	}
	Alarm(2);
	return 0;
}


int DrillHole(void){
	int error; 
	DrillDown();
	error = DrillDownTest();
	DrillUp();
	return error;
}

int RefPos(void){
	int step_error;
	unsigned int status = DRILLSTATUS;
	while(status & 0x01 == 0){
		step_error = Step();
		if(step_error == 0){
			return 0;
		}
	}
	return 1;
}

void DoAuto(void){
	int error;
	int* steps = pattern;

	error = RefPos();
	if(error == 0){
		return;
	}
	MotorStart();
	hold((time_type)250);
	while(*steps != 0xFF){
		error = Nstep(*steps);
		if(error == 0){
			MotorStop();
			return;
		}
		error = DrillHole();
		if(error == 0){
			MotorStop();
			return;
		}
		steps = steps+ 1;
		
		}
	MotorStop();
}
