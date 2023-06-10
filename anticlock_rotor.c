#include "LPC17xx.h"

void delay(unsigned long int x);

int main(){
	unsigned char arr1[]= {0x88,0x44,0x22,0x11},i; 
	LPC_GPIO1 -> FIOMASK = 0xFFFC3FFF;
	LPC_GPIO1 -> FIODIR = 0x0003C000;
	while(1){
		for(i=0;i<4;i++){                          
		   LPC_GPIO1->FIOPIN = arr1[i]<<14;
		   delay(0x50000);
		}
	}
}

void delay(unsigned long int x)
{
	unsigned long int i=0;
	for(i=0;i<x;i++);
}