
extern void welcome_screen(void);        /* Welcome Screen */
extern void initialize_interrupt(void);  /* Initialize Interrupt */
extern void I2C_start();
extern void I2C_stop();
extern void I2C_byte_write(unsigned char dat);
extern unsigned char I2C_byte_read();
extern void i2c_slave_ack();	
extern void i2c_noack();
extern void i2c_master_ack();
extern	void i2c_device_byte_write(unsigned char sa,unsigned char buf_addr,unsigned char dat);
extern	unsigned char i2c_device_byte_read(unsigned char sa,unsigned char buf_addr);
extern void i2c_device_seq_write(unsigned char sa,unsigned char buf_addr,unsigned char dat);
extern unsigned char i2c_device_seq_read(unsigned char sa,unsigned char buf_addr);
extern void lcd_data(unsigned char  d);
extern void lcd_cmd(unsigned char c);
extern void lcd_init(void);
extern void string_data(unsigned char *d);
extern void delay_ms(unsigned int ms);
extern void row_Init(void);
//extern unsigned char master_key[10]="00000";
extern bit Is_Keypressed(void);
extern char key_Val(void);
extern unsigned int cmp(const char *,const char *);
//extern void EINT0(void) interrupt 0
//extern 	void en_ext_interrupt(void)
extern void init_pass_write(void);
extern unsigned char* init_pass_read(void);
//extern unsigned char temp;
// extern char b[10];
extern void edit_pass(void);
extern unsigned char * init_pass_read_1(void);

extern signed char taking_id(void);

extern const unsigned char * select_id(signed char); 

extern void init_pass_write_user_one(void);

extern void init_pass_write_user_two(void);

extern void init_pass_write_user_three(void);

extern unsigned char * init_pass_read_user_one(void);

extern unsigned char * init_pass_read_user_two(void);

extern unsigned char * init_pass_read_user_three(void);

extern unsigned char * enter_password(void);

extern void compare_password(unsigned char*, unsigned char*);

extern void door_open(void);

extern void door_close(void);



extern void password_count(signed int);
