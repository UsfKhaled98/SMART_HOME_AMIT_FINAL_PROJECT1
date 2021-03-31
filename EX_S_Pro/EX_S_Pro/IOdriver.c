/*
 * IOdriver.c
 *
 * Created: 1/12/2021 4:59:17 PM
 *  Author: hp
 */ 

# define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "mydefines.h"
#include "IOdriver.h"

void Data_dir_pin_A(int state,int n){
	switch (state){
		case output:
		DDRA|=(1<<n);
		break;
		case input:
		DDRA &=~(1<<n);
		break;
		default:
		DDRA &=~(1<<n);
	}
}
void Data_dir_pin_B(int state,int n){
	switch (state){
		case output:
		DDRB|=(1<<n);
		break;
		case input:
		DDRB &=~(1<<n);
		break;
		default:
		DDRB &=~(1<<n);
	}
}
void Data_dir_pin_C(int state,int n){
	switch (state){
		case output:
		DDRC|=(1<<n);
		break;
		case input:
		DDRC &=~(1<<n);
		break;
		default:
		DDRC &=~(1<<n);
	}
}
void Data_dir_pin_D(int state,int n){
	switch (state){
		case output:
		DDRD|=(1<<n);
		break;
		case input:
		DDRD &=~(1<<n);
		break;
		default:
		DDRD &=~(1<<n);
	}
}


void Data_dir_portA(int state){
	switch (state){
		case outport:
		DDRA=0xFF;
		break;
		case inport:
		DDRA =0x00;
		break;
		default:
		DDRA =0x00;
	}
}

void Data_dir_portB(int state){
	switch (state){
		case outport:
		DDRB=0xFF;
		break;
		case inport:
		DDRB =0x00;
		break;
		default:
		DDRB =0x00;
	}
}

void Data_dir_portC(int state){
	switch (state){
		case outport:
		DDRC=0xFF;
		break;
		case inport:
		DDRC =0x00;
		break;
		default:
		DDRC =0x00;
	}
}

void Data_dir_portD(int state){
	switch (state){
		case outport:
		DDRD=0xFF;
		break;
		case inport:
		DDRD =0x00;
		break;
		default:
		DDRD =0x00;
	}
}

void setpinA(int n){
	PORTA |=(1<<n);
}
void setpinB(int n){
	PORTB |=(1<<n);
}
void setpinC(int n){
	PORTC |=(1<<n);
}
void setpinD(int n){
	PORTD |=(1<<n);
}

void resetpinA(int n){
	PORTA &=~(1<<n);
}
void resetpinB(int n){
	PORTB &=~(1<<n);
}
void resetpinC(int n){
	PORTC &=~(1<<n);
}
void resetpinD(int n){
	PORTD &=~(1<<n);
}

void togglepinA(int n){
	PORTA ^=(1<<n);
}
void togglepinB(int n){
	PORTB ^=(1<<n);
}
void togglepinC(int n){
	PORTC ^=(1<<n);
}
void togglepinD(int n){
	PORTD ^=(1<<n);
}



char pressA(int n){
	if(PINA&(1<<n))
	return 1 ;
	else
	return 0 ;
}
char pressB(int n){
	if(PINB&(1<<n))
	return 1 ;
	else
	return 0 ;
}
char pressC(int n){
	if(PINC&(1<<n))
	return 1 ;
	else
	return 0 ;
}
char pressD(int n){
	if(PIND&(1<<n))
	return 1 ;
	else
	return 0 ;
}
