#include <reg51.h>
#include "header.h"


unsigned char * enter_password(void)
{
		unsigned char a[5] = {0};
		unsigned char i,j=7,temp1 = 0;
	
		lcd_init();
		lcd_cmd(0x01);
		lcd_cmd(0x80);
	  string_data("   ENTER PASS"); 
			
		delay_ms(100);
		lcd_cmd(0xC0);

		lcd_cmd(0x0f);								/* Cursor Blinking */

	for( i = 0; i < 7; i++)
	{
		lcd_cmd(0x14);								/* Cursor right shift by Seven times */ 
	}
	
			
		for(i=0;i<3;i++)
		  {
				row_Init();//Row initialization
				while(Is_Keypressed());//waiting for sw press
				temp1=	key_Val();
				a[i]=temp1;
				lcd_cmd(0xC0+j);				/* taking j for force to cursor to the middle of lcd while entering password */
				lcd_data(temp1);
					delay_ms(100);
					lcd_cmd(0xC0+j);
					lcd_data('*');
					j++;									/* incrementing j for next location of lcd for password */
			} 
				a[i]='\0';
				
				delay_ms(300);
			
							
	
		return a;
}