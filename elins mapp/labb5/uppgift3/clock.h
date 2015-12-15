//header (typ interface)

typedef unsigned long int time_type;

//nollställer klockan, genererar avbrott
void init_clock();

//tickar upp klockan,anropas av avborttsrutinen
void clock_inter();

//get antalet ms som gått sedan klockan initierades
time_type get_time(void);

//fördröjer exekveringen ett visst antal ms
void hold(time_type);  

