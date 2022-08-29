#include "header.h"
#include<string.h>
void edit_pass(void)
{
	unsigned char key,temp1, user_id = 0;
	signed char i,ret;
	char a[5]={0};
	unsigned char *read_pass;
	
	unsigned char c[5]={0};
	lcd_init();
	label:	lcd_cmd(0x01);
	lcd_cmd(0x80);
string_data("ENTER OLD PASS");
	for(i=0;i<3;i++)
		  {
				row_Init();//Row initialization
				while(Is_Keypressed());//waiting for sw press
				temp1=	key_Val();
				a[i]=temp1;
				lcd_cmd(0xC0+i);
				lcd_data(temp1);
					delay_ms(100);
					lcd_cmd(0xC0+i);
					lcd_data('*');
			} 
				a[i]='\0';
		//	ptr = init_pass_read();
		 // strcpy(c,ptr);
		user_id	= taking_id();
			
			
			if(user_id == '1')
			{
				read_pass = init_pass_read_user_one(); 
			
			}
			
			else if(user_id == '2')
			{
				read_pass = init_pass_read_user_two(); 
			
			}
			
			
			else if(user_id == '3')
			{
				read_pass = init_pass_read_user_three(); 
			
			}
			
			ret=strcmp(a,read_pass);
			lcd_cmd(0x01);
	lcd_cmd(0x80);
			
			
			if(ret==0)
			{
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	string_data("PASS MATCH");
delay_ms(400);					
				
			 lcd_cmd(0x01);
	lcd_cmd(0x80);
string_data("SET UR NEW PASS"); 
	lcd_cmd(0xC0);
	row_Init(); 
	delay_ms(400);
				
	
	  
	switch (user_id)
	{
		case '1' : 
							while(Is_Keypressed());//waiting for sw press1
		     key=key_Val();
	//row_init();                  //row stuck in the same position so initialze again
	lcd_data(key);
	//c[0]=key;
	i2c_device_byte_write(0xA0,0x3,key);//write 1 byte of data into eeprom memory loaction

	row_Init(); 
	while(Is_Keypressed());//waiting for sw press2
		     key=key_Val();
	//row_init();                //row stuck in the same position so initialze again
	lcd_data(key);
	//c[1]=key;
i2c_device_byte_write(0xA0,0x4,key);//write 1 byte of data into eeprom memory loaction

 
 row_Init();
 while(Is_Keypressed());//waiting for sw press3
		     key=key_Val();
				 //row_init();             //row stuck in the same position so initialze again
	lcd_data(key);
	//c[2]=key;
i2c_device_byte_write(0xA0,0x5,key);//write 1 byte of data into eeprom memory loaction

break;



		case '2' :
			
		while(Is_Keypressed());//waiting for sw press1
		     key=key_Val();
	//row_init();                  //row stuck in the same position so initialze again
	lcd_data(key);
	//c[0]=key;
	i2c_device_byte_write(0xA0,0x8,key);//write 1 byte of data into eeprom memory loaction

	row_Init(); 
	while(Is_Keypressed());//waiting for sw press2
		     key=key_Val();
	//row_init();                //row stuck in the same position so initialze again
	lcd_data(key);
	//c[1]=key;
i2c_device_byte_write(0xA0,0x9,key);//write 1 byte of data into eeprom memory loaction

 
 row_Init();
 while(Is_Keypressed());//waiting for sw press3
		     key=key_Val();
				 //row_init();             //row stuck in the same position so initialze again
	lcd_data(key);
	//c[2]=key;
i2c_device_byte_write(0xA0,0x0A,key);//write 1 byte of data into eeprom memory loaction

break;
		
		
		case '3' :
			
		while(Is_Keypressed());//waiting for sw press1
		     key=key_Val();
	//row_init();                  //row stuck in the same position so initialze again
	lcd_data(key);
	//c[0]=key;
	i2c_device_byte_write(0xA0,0x0D,key);//write 1 byte of data into eeprom memory loaction

	row_Init(); 
	while(Is_Keypressed());//waiting for sw press2
		     key=key_Val();
	//row_init();                //row stuck in the same position so initialze again
	lcd_data(key);
	//c[1]=key;
i2c_device_byte_write(0xA0,0x0E,key);//write 1 byte of data into eeprom memory loaction

 
 row_Init();
 while(Is_Keypressed());//waiting for sw press3
		     key=key_Val();
				 //row_init();             //row stuck in the same position so initialze again
	lcd_data(key);
	//c[2]=key;
i2c_device_byte_write(0xA0,0x0F,key);//write 1 byte of data into eeprom memory loaction

break;
		
	}

}
			else
			{
				lcd_cmd(0x01);
	lcd_cmd(0x80);
	string_data("PASS NOT MATCH");
	lcd_cmd(0xC0);	
	string_data("TRY AGAIN");
				delay_ms(400);
				
				goto label;	
			}
				

}			