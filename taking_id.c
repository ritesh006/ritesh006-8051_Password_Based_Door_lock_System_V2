#include "header.h"
int i = 0;
signed char taking_id(void)
{
	unsigned char user_id = 0;
	
		lcd_cmd(0x01);   					/* clear screen */
		lcd_cmd(0x80);	 					/* Select first row */
	  string_data("  SELECT ID FROM"); /* sending data to lcd */
	  lcd_cmd(0xC0);
		string_data("      1 2 3"); 
		delay_ms(900);						/* delay for two second */
	
		
		lcd_cmd(0x01);   							/* clear screen */
		lcd_cmd(0x80);	 							/* Select first row */
	  string_data("    ENTER ID"); 	/* sending data to lcd */
		delay_ms(100);      		 			/* optional */
		lcd_cmd(0xc0);								/* Set Cursor on 2nd line */
		lcd_cmd(0x0f);								/* Cursor Blinking */

	for( i = 0; i < 7; i++)
	{
		lcd_cmd(0x14);								/* Cursor right shift by Seven times */ 
	}
	
		row_Init();									//Row initialization
		while(Is_Keypressed());//waiting for sw press
		user_id =	key_Val();		/* storing user id to variable */
		//lcd_cmd(0xC0);					/* set curser to second line */
		lcd_data(user_id);     /* display id to lcd */
		delay_ms(1000);
		return user_id;
		

}