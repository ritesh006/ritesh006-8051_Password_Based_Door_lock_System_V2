#include <reg51.h>  /* register address included with header file */
#include "header.h" /* user defined header file added */
#include <string.h> /* from this liabrary used string compare function "strcmp" */

sbit buzzer  = P3^7; /* declare buzzer for alarming purpose when user enter wrong password */

sbit trigger = P2^7; 
/* delcaring trigger pin to trigger the external interrrupt 0 when pin goes high it will trigger to pin 3.2 */

sbit in1=P3^5;   /* declaring pin for motor driver input IN1 */
sbit in2=P3^6;	 /* declaring pin for motor driver input IN1 */


/* ---------------------- Main Starts from Here ------------------------------ */

void main()
{
	
	unsigned char master_key[5] = "000"; /* initialise variable to store the master password which can use to change the password of user */
	unsigned char temp = 0;							 /* initialise variable to store the key_value of '=' key when its pressed */
	signed int count = 0;							   /* storing value to check wrong password is equal to three or not */
  unsigned char compare_value = 0;  	 /* storing result of string compare function */     
	char x[5]={0};
	char d[5]={0};
	char b[5]= {0};

	/* extra comment to test */
	const unsigned char * a;
	signed char user_id;
	const	unsigned char * read_pass;
	
	buzzer = 0;
	
	init_pass_write_user_one(); 	/* writing password to the eeprom */
	init_pass_write_user_two(); 	/* writing password to the eeprom */
	init_pass_write_user_three(); /* writing password to the eeprom */
	
	
	welcome_screen();				      /* Calling welcome Screen function */

	initialize_interrupt();       /* initialize the interupts */
	
/*---------------------------- While One starts from here -----------------------------------------*/
	while(1)
	{ 
		
		user_id = taking_id();          /* select id from user */
		
		read_pass = select_id(user_id);	/* select one from three id */
		
		strcpy(x , read_pass);
		
		a = enter_password();
		
		compare_value = strcmp(a , x); 
				
	 if( compare_value == 0 )
	{
				 
				lcd_cmd(0x01);
				
		   string_data(" PASSWORD MATCH");
				
		   lcd_cmd(0xC0);
		   string_data("  DOOR OPENING");
				
			 door_open();
		
			 delay_ms(2000);
				 

	}
		   else if(( compare_value = strcmp( a, master_key)) ==0 )
			 {
				lcd_cmd(0x01);
				lcd_cmd(0x80);
	     string_data("SET YOUR PASSWORD"); 
	      //delay_ms(4000);
	      lcd_cmd(0xC0);
	      string_data("PRESS = KEY");
				delay_ms(400);
	       while(Is_Keypressed());//waiting for sw press
		     temp=key_Val();
				 
				 trigger = 0;
				 trigger = 1;
			
				 
	       }
		 
		else
		{
			lcd_cmd(0x01);
			lcd_cmd(0x80);
			
			string_data("WRONG PASS");	
			lcd_cmd(0xC0);
			string_data("TRY AGAIN ");
			count++;
			lcd_data(count+48);
			buzzer = 1;
				
			door_close();
			
			buzzer = 0;
				
			password_count(count);
			
		}
					
	}
/*---------------------------- While One Ends here -----------------------------------------*/

}
/* ---------------------- Main Ends Here ------------------------------ */
