

i2c_device_byte_write(0xA0,0x3,'1');
  temp=i2c_device_byte_read(0xA0,0x3);
	b[0]=temp;
  i2c_device_byte_write(0xA0,0x4,'2');
  temp=i2c_device_byte_read(0xA0,0x4);
	b[1]=temp;
	i2c_device_byte_write(0xA0,0x5,'3');
  temp=i2c_device_byte_read(0xA0,0x5);
	b[2]=temp;
	i2c_device_byte_write(0xA0,0x6,'4');
  temp=i2c_device_byte_read(0xA0,0x6);
	b[3]=temp;
	i2c_device_byte_write(0xA0,0x7,'5');
  temp=i2c_device_byte_read(0xA0,0x7);
	b[4]=temp;