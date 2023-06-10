#include <LPC17xx.H>
void delay(unsigned long int x);
int main()
{
	// ARRAY OF PIN VALUES IN HEXADECIMAL TO ROTATE CLOCKWISE
	unsigned char arr1[]={0x88,0x44,0x22,0x11},i;
	SystemInit();
	
	LPC_GPIO1->FIOMASK=0xFFFC3FFF; 
	LPC_GPIO1->FIODIR=0x0003C000;
	while(1)
	{
		for(i=0;i<4;i++)
			{		
				// LEFT SHIFTING BITS BY 14 TO GET THEM TO PIN 14,15,16,17 FROM LSB SIDE
				LPC_GPIO1->FIOPIN=arr1[i]<<14;
				delay(0x50000);
			};
	}
	
}

//DELAY FUNCTION
void delay(unsigned long int x) 
{
 	unsigned long int i=0;
 		for(i=0;i<x;i++);
}