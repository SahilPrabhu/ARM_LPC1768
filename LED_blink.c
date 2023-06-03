#include <LPC17xx.H>

void delay(unsigned long int di);

int main()
{
SystemInit ();
LPC_SC->PCONP&=0X00000000;
LPC_GPIO2->FIOMASK|=0XFFFFF7FF;
LPC_GPIO2->FIODIR|=0X00000800;	
		
while(1)
{
LPC_GPIO2->FIOSET|=0X00000800;	
delay(0x200000);	

LPC_GPIO2->FIOCLR|=0X00000800;	
delay(0x200000);

}
}

void delay(unsigned long int di)
{
unsigned long int i=0;
 for(i=0;i<di;i++);	
}