/*
 * UART.c
 *
 * Created: 1/27/2021 3:38:04 PM
 *  Author: hp
 */ 
#include <stdlib.h>
# define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>


void UART_BaudRate(unsigned int Baud){  //to adj. the baud_rate we will use 
	int x = (F_CPU/(16.0*Baud))-1;
	UBRRL = (char)x;
	UBRRH = (x>>8);
}


void init_UART(unsigned int BaudRate){  //init. of UART
	UART_BaudRate(BaudRate);
	UCSRB|= (1<<RXEN)|(1<<TXEN)|(1<<RXCIE);
}

char rescive_char_UART(){  //Bolling way to RES. char 
	while(!(UCSRA & (1<< UDRE )));
	return UDR;
}

void send_char_UART(char data){  //Bolling way to send char 
	while(!(UCSRA & (1<< UDRE )));
	UDR=data;
}


void send_str_UART(char* str){  //used if we want to send string of char
	for(int i=0 ; str[i] != '\0'; i++){
		send_char_UART(str[i]);
	}
}


void send_number_UART(int number){  //used to send integer 
	char arr[11];
	itoa(number,arr,10);
	send_str_UART(arr);
}

void NEWLINE_UART(){ //to make new line 
	send_char_UART('\r');
}
