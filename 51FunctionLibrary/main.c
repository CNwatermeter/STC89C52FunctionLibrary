#include <reg52.h>
#include "51FunctionLibrary.h"
sbit LED1 = P2^0;
int main(void){ //Ö÷º¯Êý
  while(1){
    LED1 = 0; 
    delay(50000); 
    LED1 = 1; 
    delay(50000); 
	LED1 = 0;
	delayms(450,11);
	LED1 = 1;
	delayms(450,11);
  }
}