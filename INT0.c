#include<reg51.h>
//#include"int0.h"
#include"header.h"
sbit led = P2^3;
//sbit row1=P^1.3;
void ext_INT0(void) interrupt 0
{

	
//row_init();
led=~led;
edit_pass();

}


