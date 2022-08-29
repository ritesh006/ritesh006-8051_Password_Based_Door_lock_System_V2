#include"header.h"
unsigned char * init_pass_read_user_one(void)
{
	
	unsigned char b[5]={0};
	unsigned char temp;
	
  temp=i2c_device_byte_read(0xA0,0x3);
	b[0]=temp;
	
	
  
  temp=i2c_device_byte_read(0xA0,0x4);
	b[1]=temp;
	
	
  temp=i2c_device_byte_read(0xA0,0x5);
	b[2]=temp;
	
	
	
	string_data(b);   /* glich */
	
	return b;
}


unsigned char * init_pass_read_user_two(void)
{
	unsigned char b[5]={0};
	unsigned char temp;
	

  temp=i2c_device_byte_read(0xA0,0x8);
	b[0]=temp;

  
  temp=i2c_device_byte_read(0xA0,0x9);
	b[1]=temp;
	
	
  temp=i2c_device_byte_read(0xA0,0x0A);
	b[2]=temp;
	
	return b;
}

unsigned char * init_pass_read_user_three(void)
{
	unsigned char b[5]={0};
	unsigned char temp;
	
  temp=i2c_device_byte_read(0xA0,0x0D);
	b[0]=temp;
	
  
  temp=i2c_device_byte_read(0xA0,0x0E);
	b[1]=temp;
	
	
  temp=i2c_device_byte_read(0xA0,0x0F);
	b[2]=temp;
	
	return b;
	
}