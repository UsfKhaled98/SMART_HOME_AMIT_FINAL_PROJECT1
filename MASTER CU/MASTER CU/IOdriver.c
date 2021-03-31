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

void Data_dir_pin_A(int state,int n){    //set 0r reset data direction of certain pin in port A
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
void Data_dir_pin_B(int state,int n){   //set 0r reset data direction of certain pin in port B
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
void Data_dir_pin_C(int state,int n){  //set 0r reset data direction of certain pin in port C
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
void Data_dir_pin_D(int state,int n){  //set 0r reset data direction of certain pin in port D
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


void Data_dir_portA(int state){  //set data direction of all port A
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

void Data_dir_portB(int state){  //set data direction of all port B
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

void Data_dir_portC(int state){  //set data direction of all port C
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

void Data_dir_portD(int state){  //set data direction of all port D
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

void setpinA(int n){   //set port A of certain pin n
	PORTA |=(1<<n);
}
void setpinB(int n){   //set port B of certain pin n
	PORTB |=(1<<n);
}
void setpinC(int n){  //set port C of certain pin n
	PORTC |=(1<<n);
}
void setpinD(int n){  //set port D of certain pin n
	PORTD |=(1<<n);
}

void resetpinA(int n){  //reset port A of certain pin n
	PORTA &=~(1<<n);
}
void resetpinB(int n){  //reset port B of certain pin n
	PORTB &=~(1<<n);
}
void resetpinC(int n){  //reset port C of certain pin n
	PORTC &=~(1<<n);
}
void resetpinD(int n){  //reset port D of certain pin n
	PORTD &=~(1<<n);
}

void togglepinA(int n){  //toggle port A of certain pin n
	PORTA ^=(1<<n);
}
void togglepinB(int n){  //toggle port B of certain pin n
	PORTB ^=(1<<n);
}
void togglepinC(int n){  //toggle port C of certain pin n
	PORTC ^=(1<<n);
}
void togglepinD(int n){  //toggle port D of certain pin n
	PORTD ^=(1<<n);
}



char pressA(int n){  //to write data on port A of certain pin n
	if(PINA&(1<<n))
	return 1 ;
	else
	return 0 ;
}
char pressB(int n){   //to write data on port B of certain pin n
	if(PINB&(1<<n))
	return 1 ;
	else
	return 0 ;
}
char pressC(int n){  //to write data on port C of certain pin n
	if(PINC&(1<<n))
	return 1 ;
	else
	return 0 ;
}
char pressD(int n){  //to write data on port D of certain pin n
	if(PIND&(1<<n))
	return 1 ;
	else
	return 0 ;
}
