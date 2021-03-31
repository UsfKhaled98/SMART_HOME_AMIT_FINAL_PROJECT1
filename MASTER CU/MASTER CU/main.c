/*
 * MASTER CU.c
 *
 * Created: 3/27/2021 12:08:50 PM
 * Author : hp
 */ 

#include <avr/interrupt.h>
# define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "IOdriver.h"
#include "UART.h"
#include "SPI.h"
#include "mydefines.h"
#include "LCD_8Bits.h"

// we use interrupt to REC. data from blue_tooth module through UART used in master CU then send this data to slave CU by SPI
ISR(USART_RXC_vect){ 
	char data = UDR;  
  	 SPI_send(data);
	   switch(data){
		   case 'A':
		   case 'a':
		   clr_LCD8();
		   str_LCD8("Actua_1 is active");
		   commond_LCD8(0xC0);
		   str_LCD8("enter B to close");
		   break;
		   // if we REC. letter A or a the LCD will indicate the user that Actuator_1 is active 
		   case 'B':
		   case 'b':
		   clr_LCD8();
		   str_LCD8("Actua_1 is display");
		   commond_LCD8(0xC0);
		   str_LCD8("enter A OR C");
		   break;
		   // if we REC. letter B or b the the LCD will indicate the user that Actuator_1 is inactive 
		   case 'C':
		   case 'c':
		   clr_LCD8();
		   str_LCD8("Actua_2 is active");
		   commond_LCD8(0xC0);
		   str_LCD8("enter D to close");
		   break;
		   // if we REC. letter C or c the LCD will indicate the user that Actuator_2 is active 
		   case 'D':
		   case 'd':
		   clr_LCD8();
		   str_LCD8("Actua_2 is display");
		   commond_LCD8(0xC0);
		   str_LCD8("enter C OR A");
		   break;
		   // if we REC. letter D or d // if we REC. letter C or c the LCD will indicate the user that Actuator_2 is inactive 
	   }
}
int main(void)
{
	init_UART(9600);                      //init. UART with baud_rate 9600
	SPI_int_MASTER(SPI_freq_128,LSB);     //init. SPI (in master mood) 
	sei();                                //set ON globale interrupt as we use interrupt way
	init_LCD8();                          //init. LCD 
	str_LCD8("WELCOME TO SMART");         //send string 
	commond_LCD8(0xC0);                   //start writing in new line
	str_LCD8("HOME control unit");        //send string 
	_delay_ms(1000);                      //make delay so the user can take time to read the sent data
	clr_LCD8();                           //clear the data in LCD screen
	str_LCD8("please Enter any of");      //send string
	commond_LCD8(0xC0);                   //start writing in new line
	str_LCD8("A or a or C or c");         //send string
    while (1) 
    {
    }
}

