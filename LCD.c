#include<LPC17xx.h>
#define RS 0x01
#define RW 0x02
#define EN 0x04

void delay(unsigned long int x)
	{
		unsigned long int i=0;
		for(i=0;i<x;i++);
	}
void datawrt(unsigned char data);
void cmdwrt(unsigned char cmd);


int main(void)
{
	unsigned char i;
	unsigned char  cmd[]={0x35,0x0E,0x06,0x80,0x01};
	unsigned char  msg[]=" Welcome to PESU";
	SystemInit();
	LPC_GPIO2->FIOMASK0|=0x00;
	LPC_GPIO2->FIODIR0|=0xFF;
	LPC_GPIO1->FIOMASK1|=0xF8;
	LPC_GPIO1->FIODIR1|=0x07;
	
	LPC_GPIO1->FIOCLR1|=RW;
	
	LPC_GPIO1->FIOCLR1|=RS;
	for(i=0;i<5;i++)
	{
		LPC_GPIO2->FIOPIN0=cmd[i];
		LPC_GPIO1->FIOSET1=EN;
		delay(0x500);
		LPC_GPIO1->FIOCLR1=EN;
		delay(0x5000);
	}
	LPC_GPIO1->FIOSET1=RS;
	for(i=0;msg[i]!='\0';i++)
	{
		LPC_GPIO2->FIOPIN0=msg[i];
		LPC_GPIO1->FIOSET1=EN;
		delay(0x500);
		LPC_GPIO1->FIOCLR1=EN;
		delay(0x5000);
	}	
}