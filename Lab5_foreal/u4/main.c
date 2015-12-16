#include "clock.h"
#include "drill.h"
#include "keyboardML15.h"


void main(void){
//int pattern[21] = { 0, 1, 1, 1, 1, 1, 1, 1, 2, 1, 5, 2, 2, 2, 2, 4, 4, 3, 8, 2, 0xFF}; 
//int* pattern_ptr = pattern;
char key;

init_clock();
DrillInit();
while(1){
key = get_key();

switch(key) {
      case 0 :
         MotorStart();
         break;
      case 1 :
	MotorStop();
	break;
	case 2:
	DrillDown();
	break;
	case 3:
	DrillUp();
	break;
	case 4:
	Step();
	break;
	case 5:
	DrillHole();
	break;
	case 6:
	RefPos();
	break;
	case 7:
	DoAuto();
	break;    
   }

}


}
