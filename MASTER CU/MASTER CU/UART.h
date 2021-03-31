/*
 * UART.h
 *
 * Created: 1/27/2021 3:38:17 PM
 *  Author: hp
 */ 


#ifndef UART_H_
#define UART_H_

//prototypes of functions used in UART

void init_UART(unsigned int BaudRate);
void UART_BaudRate(unsigned int Baud);
void send_char_UART(char data);
void send_str_UART(char*str);
void send_number_UART(int number);
void NEWLINE_UART(void);
char rescive_char_UART(void);

#endif /* UART_H_ */