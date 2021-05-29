#include <STC15F2K60S2.H>
#include "intrins.h"
typedef unsigned char u8;
typedef unsigned int u16;

#define ADC_POWER 0x80 
#define ADC_FLAG 0x10 
#define ADC_START 0x08 
#define ADC_SPEEDLL 0x00 
#define ADC_SPEEDL 0x20 
#define ADC_SPEEDH 0x40 
#define ADC_SPEEDHH 0x60 



void UartInit()			
{	IE2 |=0x04;   		
	REN=1;
	SCON = 0x50;		
	AUXR |= 0x01;		
	AUXR &= 0xFB;		
	T2L = 0xE8;		
	T2H = 0xFF;		
	AUXR |= 0x10;		

}
void Delay(u16 n)
{
u16 x;
while (n--)
{
x = 5000;
while (x--);
}
}
void Delay100ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 5;
	j = 52;
	k = 195;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void send(u8 dat)
{
  //while (!TI);  
  TI = 0; 
  SBUF = dat; 
}
void InitADC()
{
P1ASF = 0xff; 
ADC_RES = 0; 

  ADC_CONTR = ADC_POWER | ADC_SPEEDHH;
Delay(2); 
}


u8 GetADCResult(u8 ch)
{
  ADC_CONTR = ADC_POWER | ADC_SPEEDHH | ch | ADC_START;
  _nop_(); 
  _nop_();
  _nop_();
  _nop_();
  while (!(ADC_CONTR & ADC_FLAG)); 
    ADC_CONTR &= ~ADC_FLAG; //Close ADC
  return ADC_RES; 
}
void ShowResult(u8 ch)
{
  send(ch); //􁱮􂽪􄙊􄚃􀨧
  Delay100ms();
  send(GetADCResult(ch)); //􁱮􂽪ADC􅄈8􀕽􃔃􁷌
 //send(ADC_RESL); //􁱮􂽪􀕾2􀕽􃔃􁷌
}