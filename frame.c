#include "header.h"
void i2c_byte_write_frame(unsigned char sa,unsigned char mr,unsigned char d)
{
bit ret;
i2c_start();
i2c_write(sa);
ret=i2c_ack();
if(ret==1)
goto out;
i2c_write(mr);
ret=i2c_ack();
if(ret==1)
goto out;
i2c_write(d);
ret=i2c_ack();
if(ret==1)
goto out;
out:
i2c_stop();
}



unsigned char i2c_byte_read_frame(unsigned char sa,unsigned char mr)
{
unsigned temp; 
bit ret;
i2c_start();
i2c_write(sa);
ret=i2c_ack();
if(ret==1)
goto out;
i2c_write(mr);
ret=i2c_ack();
if(ret==1)
goto out;
i2c_start();
i2c_write(sa|1);
ret=i2c_ack();
if(ret==1)
goto out;
temp=i2c_read();
i2c_noack();
out:
i2c_stop();
return temp;
}
