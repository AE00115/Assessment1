#include <avr/io.h>
#include <util/delay.h>
#include "Uart.h"

int main(void){
  init();

  while (1)
  {
    if((PINB & (1 << 3)))   // if switch not pressed
    {
      PORTB = PORTB & ~(1 << 5);    // Switch OFF lED
      _delay_ms(1000);
    }  
    else 
    {
      PORTB = PORTB | (1 << 5);      // Switch ON lED
      
      Uart_SendString("LED ON ");

      _delay_ms(1000);
    }
  }
  return 0; 
}

void init(){
  DDRB = DDRB | (1 << 5);     // Make PB13 output
Uart_Init();
  DDRB = DDRB & ~(1 << 3);    // Make PB11 input
  PORTB = PORTB | (1 << 3);   // Activate pull up resistance

}