/*
 * IOdriver.h
 *
 * Created: 1/12/2021 4:58:59 PM
 *  Author: hp
 */ 


#ifndef IODRIVER_H_
#define IODRIVER_H_

void Data_dir_pin_A(int state,int n);
void Data_dir_pin_B(int state,int n);
void Data_dir_pin_C(int state,int n);
void Data_dir_pin_D(int state,int n);

void Data_dir_portA(int state);
void Data_dir_portB(int state);
void Data_dir_portC(int state);
void Data_dir_portD(int state);

void setpinA(int n);
void setpinB(int n);
void setpinC(int n);
void setpinD(int n);

void resetpinA(int n);
void resetpinB(int n);
void resetpinC(int n);
void resetpinD(int n);

void togglepinA(int n);
void togglepinB(int n);
void togglepinC(int n);
void togglepinD(int n);

char pressA(int n);
char pressB(int n);
char pressC(int n);
char pressD(int n);


#endif /* IODRIVER_H_ */