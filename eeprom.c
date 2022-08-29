#include<reg51.h>
#include"header.h"
//#include"types.h"
sbit sda=P2^4;
sbit scl=P2^5;



void I2C_stop(void)
{
	scl=0;
	sda=0;
	scl=1;
	sda=1;
}
void I2C_byte_write(unsigned char dat)
{
	signed char i;
	for(i=7;i>=0;i--)
	{
		scl=0;
		sda=((dat>>i)&1);
		scl=1;
	}
}
unsigned char I2C_byte_read(void)
{
	unsigned char ch=0;
	signed char i;
	for(i=7;i>=0;i--)
	{
		scl=0;
		scl=1;
		if(sda==1)		
		ch|=1<<i;//updating bit status to ch variable
	}
	return ch;
}
void i2c_slave_ack(void)
{
	scl=0;
	sda=1;
	scl=1;
	while(sda==1);//waiting
}
void i2c_noack(void)
{
	scl=0;
	sda=1;
	scl=1;
}
/*void i2c_master_ack(void)
{
	scl=0;//Master making the scl line low
	sda=0;//master pulling the sda line low
	scl=1;
	scl=0;//Master has applied the clock pulse
	sda=1;//Master releasing the sda line 
}*/
void i2c_device_byte_write(unsigned char sa,unsigned char buf_addr,unsigned char dat)
{
	I2C_start();
	I2C_byte_write(sa);
	i2c_slave_ack();			
	I2C_byte_write(buf_addr);
	i2c_slave_ack();			
	I2C_byte_write(dat);
	i2c_slave_ack();			
	I2C_stop();
	delay_ms(10);
}
unsigned char i2c_device_byte_read(unsigned char sa,unsigned char buf_addr)
{
	unsigned char ch;
	I2C_start();
	I2C_byte_write(sa);
	i2c_slave_ack();			
	I2C_byte_write(buf_addr);
	i2c_slave_ack();			
	I2C_start();
	I2C_byte_write(sa|0x01);
	i2c_slave_ack();
	ch=I2C_byte_read();
	
	i2c_noack();				
	I2C_stop();
	delay_ms(10);
	return(ch);
}
/*void i2c_device_seq_write(unsigned char sa,unsigned char buf_addr,unsigned char dat)
{
	unsigned char i;
	I2C_start();
	I2C_byte_write(sa);
	i2c_slave_ack();			
	I2C_byte_write(buf_addr);
	i2c_slave_ack();
	for(i=1;i<9;i++)			
	{
		I2C_byte_write(dat+i);
		i2c_slave_ack();			
	}
	I2C_stop();
	delay_ms(10);
}
unsigned char* i2c_device_seq_read(unsigned char sa,unsigned char buf_addr)
{
	unsigned char a[10],i;
	I2C_start();
	I2C_byte_write(sa);
	i2c_slave_ack();			
	I2C_byte_write(buf_addr);
	i2c_slave_ack();			
	I2C_start();
	I2C_byte_write(sa|0x01);
	i2c_slave_ack();
	for(i=0;i<7;i++)
	{
		a[i]=I2C_byte_read();
		i2c_master_ack();
	}
	a[i]=I2C_byte_read();
	i2c_noack();				
	I2C_stop();
	delay_ms(10);
	return(a);
}

*/
void I2C_start(void)
{
	scl=0;
	sda=1;
	scl=1;
	sda=0;
}
