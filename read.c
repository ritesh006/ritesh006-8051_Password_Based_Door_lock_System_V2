#include"header.h"
unsigned char * init_pass_read_1(void)
{
	
	unsigned char b[10];
	unsigned char temp;
	lcd_init();
	lcd_cmd(0x80);

  temp=i2c_device_byte_read(0xA0,0x11);
	b[0]=temp;
	lcd_data(b[0]);
	
  
  temp=i2c_device_byte_read(0xA0,0x12);
	b[1]=temp;
	lcd_data(b[1]);
	
  temp=i2c_device_byte_read(0xA0,0x13);
	b[2]=temp;
	lcd_data(b[2]);
	
  
	temp=i2c_device_byte_read(0xA0,0x14);
	b[3]=temp;
	lcd_data(b[3]);
	
 
 temp=i2c_device_byte_read(0xA0,0x15);
	b[4]=temp;
	lcd_data(b[4]);
	return b;
}