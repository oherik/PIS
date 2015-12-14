
void main(void){
unsigned long int tst;
unsigned int inten;
while(1){
	init_clock();
	tst = get_time();
	inten = tst/1000;
	display_dec(inten);
	}
}
