#include<reg51.h>
#include"header.h"
sbit in1=P3^5;
sbit in2=P3^6;

void door_open(void) 
{
		in1=1;
		in2=0;
		delay_ms(2000);
		in1=0;
		in2=0;   
}



void door_close(void)
{
	in1=0;
	in2=1;
	delay_ms(1000);
	in1=0;
	in2=0;
				
	
}
