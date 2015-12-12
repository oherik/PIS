#include "ports.h"

#define	set(x, mask)	(x) = (x) | (mask)
#define clear(x, mask)	(x) = (x) & ~(mask)

unsigned char ML4shadow = 0;

void main(void){
	int value;
	while(1){
		value = ML4IN;
		ML4shadow = value;
		ML4OUT = value;
	}
}

