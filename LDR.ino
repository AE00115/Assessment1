#include <avr/io.h>
#include <util/delay.h>
#include "Adc.h"
#include "Uart.h"
//#include "Dio.h"


int main (void) {
  init();
  unsigned char buffer [4];




while (1) {
// int reading = Uart_ReadData();
  int a = Adc_ReadChannel(0);
  
  itoa(a, buffer, 10);
  Uart_SendString(buffer);
   Uart_SendString("  ");
   _delay_ms(500);
    Uart_SendChar('\r');
   Uart_SendChar('\n');

  if(a > 300){
     PORTB = PORTB  &!(1 << 0);
     Uart_SendString("Outside Light is OFF  light reading: ");
      }

  else{
     PORTB = PORTB | (1 << 0);
     Uart_SendString("Outside Light is ON  light reading: ");
  }
  

  }
  }

void init (){

  Adc_Init();
Uart_Init();
  // direction led1, switch
  DDRC &= ~(1 << 0); // make it input
  DDRB = DDRB | (1 << 0); // make it output

  // activate pull up resistace
  PORTB = PORTB | (1 << 3);
}
