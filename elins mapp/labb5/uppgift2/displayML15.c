//display_digits,display_dec
#include "ports.h"
#include "displayML15.h"

void display_digits(unsigned char * vector)
{
int j;
	//visa talen i displayen ML3
	ML15MODE=1;
	ML15DATA=0x90;
	ML15MODE=0;
	
	for( j = 0 ; j < 6; j++ )
	{
		ML15DATA=vector[j];
		
	}
	ML15DATA = 0;
	ML15DATA = 0;
	
}

void display_dec(unsigned int keynumber)
{
	//skriv om till array
	int i;
	unsigned char vec[6];
	for(i=0;i<6;i++) 
		{
			vec[5-i]=keynumber%10;
			keynumber=keynumber/10;
		}
		
	display_digits(vec);
}