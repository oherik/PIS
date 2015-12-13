#include "keyboardML15.h"

#define	set(x, mask)	(x) = (x) | (mask)
#define clear(x, mask)	(x) = (x) & ~(mask)

char get_key(void){
	char key = ML15IN;
	while(key<=0){
		key = ML15IN;	
	}
	return key;	
}

void main(void){
 
}
