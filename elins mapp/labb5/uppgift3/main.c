#include	"clock.h"
#include	"displayML15.h"

void main(void)
{
	unsigned int temp;
	init_clock();
	while(1)
	{
		time_type delay = 10;
		hold(delay);
		//ska jag g�ra om tick till en int och hur g�r jag det?
		temp =(unsigned int) get_time();
		display_dec(temp);
		
		//int keynumber=get_key();
		//display_dec(keynumber);
	}
}