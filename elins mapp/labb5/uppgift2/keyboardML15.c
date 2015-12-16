//get_key
#include "keyboardML15.h"
#include "ports.h"


int get_key(void)
{
	while(1){
		char key = ML2IN;
		if(key>=0)
		{
			return key;
		}
	}
}

