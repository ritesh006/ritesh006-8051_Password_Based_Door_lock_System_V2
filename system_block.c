#include <reg51.h>
#include "header.h"

void password_count(signed int count)
{
	if(count == 3 )
	{
		lcd_cmd(0x01);
		lcd_cmd(0x80);
	  string_data("UR SYTEM BLOCK"); 
		delay_ms(2000);
	}
	
}

