/*
 * LCD_8Bits.h
 *
 * Created: 1/19/2021 1:38:04 PM
 *  Author: hp
 */ 


#ifndef LCD_8BITS_H_
#define LCD_8BITS_H_


//prototype of functions used in LCD_8bits

void init_LCD8(void);
void commond_LCD8(char CMD);
void Data_LCD8(char DATA);
void Enable_LCD8(void);
void clr_LCD8(void);
void str_LCD8(char * str);
void Number_LCD8(int number);



#endif /* LCD_8BITS_H_ */