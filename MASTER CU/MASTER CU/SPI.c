/*
 * SPI.c
 *
 * Created: 2/13/2021 7:18:18 PM
 *  Author: hp
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include "SPI.h"
#include "IOdriver.h"
#include "mydefines.h"

void SPI_CLK(int clk_select){  //used to select clk of Master which used  
	SPCR|= (SPCR & 0xFC);
	SPCR = clk_select;
}
void SPI_CLKX2(int state){ //enable and disable extra clk in SPI
	switch(state){
		case enable :
		SPSR |=  (1<<SPI2X);
		break;
		case disable :
		SPSR &= ~(1<<SPI2X);
		break;
	}
}
void SPI_INTR(int state){  //enable and disable the interrupt of SPI
	switch(state){
		case enable :
			SPSR|= (1<<SPIF);
		break;
		case disable :
			SPSR&=~(1<<SPIF);
		break;
}
}

void SPI_Enable_M_OR_S(int mode){  // choose the mood of SPI (MASTER or SLAVE)
	switch(mode){
		case Master :
			SPCR |= (1<<MSTR);
			Data_dir_pin_B(output,MOSI);
			Data_dir_pin_B(output,SS);
			Data_dir_pin_B(output,SCK);
			Data_dir_pin_B(input,MISO);
		break;
		case Slave :
			SPCR &=~(1<<MSTR);
			Data_dir_pin_B(input,MOSI);
			Data_dir_pin_B(input,SS);
			Data_dir_pin_B(input,SCK);
			Data_dir_pin_B(output,MISO);
		break;
	}
}
void SPI_DORD(int Order){  // Data order send or REC. way MSB or LSB
	switch(Order){
		case LSB :
		SPCR |= (1<<DORD);
		break;
		case MSB :
		SPCR &= ~(1<<DORD);
		break;
	}
}
char SPI_read(void){   //Bolling way to read (REC.) data 
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
} 

void SPI_send(char data){    //Bolling way to send data 
	SPDR=data;
	while(!(SPSR & (1<<SPIF)));
}
void SPI_int_MASTER(int clk_select,int Order){  //init. Master mood 
	SPI_CLK(clk_select);
	SPI_CLKX2(disable);
	SPI_Enable_M_OR_S(Master);
	SPI_DORD(Order);
	SPI_INTR(disable);
	SPCR|= (1<<SPE);
}