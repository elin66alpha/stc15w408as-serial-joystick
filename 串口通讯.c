#include "ad.H"

sbit LED=P2^6;
sbit button=P2^5;
sbit joysw=P2^4;

void main ()
{
 LED=0;
  UartInit();
  InitADC();   
  while(1){  
    if(button==1)
    {LED=1;
      Delay100ms();
      ShowResult(0x00); 
      Delay100ms();
     ShowResult(0x01); 
      }
    else LED=0;  

  }

}

