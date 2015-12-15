#include "keyboardML15.h"
#include "ports.h"
#define clear(x, mask)	(x) &= ~(mask)

char get_key(void){
	char tmp;
	char key = ML15IN;		//Läs in fråm ML2
	while(key<0){			//key kommer vara >0 när en tangent finns tillgänglig
		key = ML15IN;	
	}
	tmp = ML15IN;
	while(tmp>=0){
		tmp = ML15IN;
	}				//Busy wait tills personen släppt knappen
	clear(key, 0xF0);		//Tangenten ligger i bit 0-3
	return key;	
}

