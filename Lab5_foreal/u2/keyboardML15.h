//Port pointers
typedef unsigned char * prt8ptr;		//8-bit port

//Keyboard in
#define KEYDECODE_ADDRESS 0x9c0
#define ML15IN *((prt8ptr) KEYDECODE_ADDRESS) 

char get_key(void);
