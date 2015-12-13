#include "keyboardML15.h"
#include "ports.h"
#define clear(x, mask)	(x) &= ~(mask)

char get_key(void){
	char key = ML15IN;		//L�s in fr�m ML2
	while(key<=0){			//key kommer vara >0 n�r en tangent finns tillg�nglig
		key = ML15IN;	
	}
	clear(key, 0xF0);		//Tangenten ligger i bit 0-3
	return key;	
}

