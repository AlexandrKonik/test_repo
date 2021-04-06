#include <avr/io.h> 
#include <avr/sleep.h>

#include <avr/interrupt.h> 
void setup()
{
  cli();
  DDRB |= (1<<5); 
  TCCR1A = 0; 
  TCCR1B = 0; 
  OCR1A = 15624; 
  TCCR1B |= (1 << 2);
  TCCR1B |= (1 << 3);
  TCCR1B |= ((1<<0)|(1<<2)| (1<<3));
  TIMSK1 = (1<<1); 
  sei();
  PORTB=0;
}

void loop()
{
  while(1)
  {
  }
}

ISR(TIMER1_OVF_vect)  
{
  PORTB = (~PINB&(1<<1));
}


ISR(TIMER1_COMPA_vect) 
{ 
  PORTB = (~PINB&(1<<5));
}
