#include <avr/io.h>
#include <util/delay.h>
#include "Adc.h"
#include "Uart.h"



int main (void) {
  init();
  unsigned char buffer [4];

while (1) {
  int A = Adc_ReadChannel(0); //Set A as variable for signal from A0
  
  itoa(A, buffer, 10);
  Uart_SendString(buffer);
  Uart_SendString("  ");
  _delay_ms(1000);
  Uart_SendChar('\n');
///////////////////////////////////////////SWITCH
   
  if((PINB & (1 << 3)))   // Check switch status
  {
    PORTD = PORTD &~(1 << 7);    // Switch OFF LED
   
  }
  else{
    PORTD = PORTD | (1 << 7);      // Switch ON LED
   
    Uart_SendString(" Switch is ON");
  Uart_SendChar('\n');
  
  }
    
////////////////////////////////////////////////////////
  if(A > 250){
    PORTB = PORTB  &!(1 << 1);
    Uart_SendString("Outside Light is OFF  light reading: ");

    }

  else{
    PORTB = PORTB | (1 << 1);
    Uart_SendString("Outside Light is ON  light reading: ");

  }
  }
  }

void init (){
////////////////////////////////////////////////////SWITCH
  DDRD = DDRD | (1 << 7);     // Make PD7 output or Pin 7
//////////////////////////////////////////////////
  Adc_Init();
Uart_Init();
//////////////////////////////////////////////////////////LDR
  DDRC &= ~(1 << 1); // Set LDR LED input PB1 or Pin 9
  DDRB = DDRB | (1 << 1); // Give Output

  PORTB = PORTB | (1 << 3); // activate pull up resistace
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////SWITCH
  DDRB = DDRB & ~(1 << 3);    // Make PB11 input
  PORTB = PORTB | (1 << 3);   // Activate pull up resistance
/////////////////////////////////////////////////////////////
}