#include<reg51.h>
#include"header.h"
sbit in1 =P3^5;
sbit in2 =P3^6;
sbit buzzer =P3^7;

void led_toggle(unsigned char ret1)
{
	buzzer = 0;
	
 if(ret1==0)
  {
		in1=1;
		in2=0;
		delay_ms(1000);
		in1=0;
		in2=0;    
  }
			else
			{
				in1=0;
				in2=1;
				delay_ms(1000);
				in1=0;
				in2=0;
				
				buzzer = 1;
				delay_ms(500);
				buzzer = 0;
			}
	
}