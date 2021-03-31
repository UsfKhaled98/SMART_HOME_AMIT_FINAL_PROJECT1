/*
 * SPI.h
 *
 * Created: 2/13/2021 7:18:32 PM
 *  Author: hp
 */ 


#ifndef SPI_H_
#define SPI_H_

//clock select 
#define SPI_freq_4         0
#define SPI_freq_16        1
#define SPI_freq_64        2
#define SPI_freq_128       3



//MASTER OR SELAVE 
#define Master  0
#define Slave   1

//Order select
#define  LSB  0
#define  MSB  1

//PIN SELECT
#define SS      4
#define MOSI    5
#define MISO    6
#define SCK     7


//disable clkx2
#define disable   0
#define enable    1


// prototype of function used in SPI in general MASTER and SLAVE 
void SPI_CLK(int);
void SPI_CLKX2(int);
void SPI_Enable_M_OR_S(int);
void SPI_DORD(int);
void SPI_int_MASTER(int,int);
void SPI_send(char);
char SPI_read(void);
void SPI_INTR(int );



#endif /* SPI_H_ */