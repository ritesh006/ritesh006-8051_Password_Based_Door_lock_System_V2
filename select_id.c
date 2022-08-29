#include "header.h"

const unsigned char * select_id(signed char user_id ) /* take_id is formal argument */
{
	
	const unsigned char * read_pass;
	
	switch (user_id)
	{
		case '1': read_pass = init_pass_read_user_one(); 
							lcd_cmd(0x01);    // clear display
							break; 
		
		case '2': read_pass = init_pass_read_user_two(); 
							lcd_cmd(0x01);    // clear display
							break; 
		
		case '3': read_pass = init_pass_read_user_three(); 
							lcd_cmd(0x01); 		// clear display
							break;					 
	}
	
	return read_pass;
	
}