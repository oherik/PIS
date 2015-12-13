#include "keyboardML15.h"

#define	set(x, mask)	(x) = (x) | (mask)
#define clear(x, mask)	(x) = (x) & ~(mask)

char get_key(void){
	char key = ML15IN;		//Läs in fråm ML2
	while(key<=0){			//key kommer vara >0 när en tangent finns tillgänglig
		key = ML15IN;	
	}
	clear(key, 0xF0);		//Tangenten ligger i bit 0-3
	return key;	
}

void main(void){
 
}
