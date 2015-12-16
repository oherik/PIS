#include "port.h"

void main(void)
{
	int c;
	while(1)
	{
		c=ML4IN;
		ML4OUT=c;
	}
}

