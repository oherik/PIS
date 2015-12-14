#include "displayML15.h"
#include "ports.h"
#define	set(x, mask)	(x) |= (mask)
#define clear(x, mask)	(x) &= ~(mask)


void display_digits(unsigned char * digits){	//Ta in en pekare till arrayen
	char i;
	
	//Initiate controller
	ML15MODE  = 1;
	ML15DATA = 0x90;
	ML15MODE  = 0;
	
	//Display the digits
	for(i=0; i<6; i++){
		ML15DATA = *digits;
		digits++;			//Peka på nästa siffra
	}
	ML15DATA = 0;
	ML15DATA = 0;

}

void display_dec(unsigned int value){
	unsigned char digits[6];
	unsigned char i,b;
	for(i=0; i<6; i++){
		b = value%10;
		value=value/10;;
		digits[5-i] = b;
	}
	display_digits(digits);
}
