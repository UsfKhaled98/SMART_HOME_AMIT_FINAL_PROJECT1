/*
 * LCD_8Bits.c
 *
 * Created: 1/19/2021 1:38:16 PM
 *  Author: hp
 */ 
# define F_CPU 8000000UL
#include "IOdriver.h"
#include "mydefines.h"
#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h>

void init_LCD8(void){               //init. of the LCD 8_bits
	DDRA = 0xFF;
	DDRB|=(1<<RS)|(1<<RW)|(1<<EN);
	clr_LCD8();
	commond_LCD8(0x38);
	commond_LCD8(0x0C);
	_delay_ms(1);
}
void commond_LCD8(char CMD){         //send command to LCD
	PORTA = CMD;
	resetpinB(RS);
	resetpinB(RW);
	Enable_LCD8();
}
void Data_LCD8(char DATA){          //send char to LCD  
	PORTA=DATA;
	setpinB(RS);
	resetpinB(RW);
	Enable_LCD8();
}
void Enable_LCD8(void){            //enable LCD to start working
	setpinB(EN);
	_delay_ms(1);
	resetpinB(EN);
	_delay_ms(1);
}
void clr_LCD8(void){               //clear screen command 
	commond_LCD8(0x01);
}
void str_LCD8(char * str){         //send string of char to LCD
	for(int i=0 ; str[i] != '\0'; i++ ){
		Data_LCD8(str[i]);
	}
}
void Number_LCD8(int number){        //send array of integer to LCD
	char arr[11];
	while (1)
	{
	itoa(number,arr,10);
	str_LCD8(arr);
	clr_LCD8();
	number++;
	}
}