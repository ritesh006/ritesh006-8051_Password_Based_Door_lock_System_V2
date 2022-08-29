#include"header.h"

void init_pass_write_user_one(void)
{
	  /* password write for user one */
	
	i2c_device_byte_write(0xA0,0x3,'0');
		
	i2c_device_byte_write(0xA0,0x4,'0');
		
	i2c_device_byte_write(0xA0,0x5,'1');
	 
}

void init_pass_write_user_two(void)
{
	
	/* password write for user two */
	
	i2c_device_byte_write(0xA0,0x8,'0');
		
	i2c_device_byte_write(0xA0,0x9,'1');
		
	i2c_device_byte_write(0xA0,0x0A,'0');
	 	
}

void init_pass_write_user_three(void)
{
		
	/* password write for user three */
	
	i2c_device_byte_write(0xA0,0x0D,'1');
		
	i2c_device_byte_write(0xA0,0x0E,'0');
		
	i2c_device_byte_write(0xA0,0x0F,'0');
	
}