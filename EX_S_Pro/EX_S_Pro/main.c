/*
 * EX_S_Pro.c
 *
 * Created: 3/30/2021 10:46:59 AM
 * Author : hp
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "IOdriver.h"
#include "mydefines.h"
#define F_CPU 8000000UL
void init_spi_slave();  // init. of SPI (in slave mood) 
char rec_SPI();   // for bolling if we wanna to use it 


// SPI PINs
  
#define MISO   6
#define MOSI   5
#define SS     4
#define SCK    7


// we will use the interrupt way to REC. data coming from master SPI so we use ISR
ISR(SPI_STC_vect){
	char data = (SPDR>>1);
	switch(data){
		case 'A':
		case 'a':
			setpinC(led0); 
		break;
// if we REC. letter A or a the led0 one will be glow 
		case 'B':
		case 'b':
			resetpinC(led0);
		break;
// if we REC. letter B or b the led0 one will be turn OFF
		case 'C':
		case 'c':
			setpinC(led1);
		break;
// if we REC. letter C or c the led1 one will be glow 
		case 'D':
		case 'd':
			resetpinC(led1);
		break;
// if we REC. letter D or d the led1 one will be turn OFF 
	}
}
int main(void)
{
	init_spi_slave(); // init. SPI (slave mood) 
	sei(); //set globale interrupt 
	Data_dir_pin_C(output,led0); // set direction data of pin 2(led0) in port C output    
	Data_dir_pin_C(output,led1); // set direction data of pin 7(led1) in port C output
    while (1) 
    {
    }
}

void init_spi_slave(){
	DDRB &=~(1<<MISO);                     // make MISO input 
	SPCR |=(1<<SPE)|(1<<DORD)|(1<<SPIF);  /* set pin SPE to enable SPI 
	                                         set pin DORD to make LSB of the data word is transmitted first
											 set pin SPIF to enable interrupt */
}
char rec_SPI(){               
	while(!(SPSR &(1<<SPIF)));     // bolling way used to REC. data coming  
	return SPDR;
}