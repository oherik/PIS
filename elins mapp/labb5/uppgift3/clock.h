//header (typ interface)

typedef unsigned long int time_type;

//nollst�ller klockan, genererar avbrott
void init_clock();

//tickar upp klockan,anropas av avborttsrutinen
void clock_inter();

//get antalet ms som g�tt sedan klockan initierades
time_type get_time(void);

//f�rdr�jer exekveringen ett visst antal ms
void hold(time_type);  

