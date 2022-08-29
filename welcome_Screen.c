#include "header.h"
void welcome_screen(void)
{ 
	lcd_init();
	
	lcd_cmd(0x01);
	lcd_cmd(0x84);
	string_data("WELCOME");
	delay_ms(1000);
	
	lcd_cmd(0x01);
	string_data("ELECTRONIC DOOR");
	
	lcd_cmd(0xC0);
	string_data("  LOCK SYSTEM");
	delay_ms(1000);
	
	
}