const byte PWM_pins[] = {A0, 13};
#define PWM_count sizeof(PWM_pins)
volatile byte pwm_value[PWM_count];
const byte pin_to_port[] = {4,4,4,4,4,4,4,4,2,2,2,2,2,2,3,3,3,3,3,3};
const byte pin_to_mask[] = { _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5), _BV(6), _BV(7),
_BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5), _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5)};
const unsigned int port_to_output[] = {0, 0, (unsigned int) &PORTB,
(unsigned int) &PORTC, (unsigned int) &PORTD};
byte pwm_counter;
boolean clocl = true;
byte value = 0;

void portWrite(byte pin, byte val)
{
  byte bit = pin_to_mask[pin];
  volatile byte *out;
  out = port_to_output[pin_to_port[pin]];
  byte oldSREG = SREG;
  cli();
  val==LOW?*out &= ~bit:*out |= bit;
  SREG = oldSREG;
}

ISR (TIMER2_COMPB_vect){
  pwm_counter++;
  for (byte i = 0; i < PWM_count; i++)
  pwm_counter > pwm_value[i] ? portWrite(PWM_pins[i],LOW):portWrite(PWM_pins[i],HIGH);
}


void setup() {
  TCCR2B = 0x00;
  TCCR2B = 1<<WGM21|1<<CS20;
  TCCR2B &= ~((1<<CS22)|(1<<CS21)); 
  OCR2B = 1;
  TIMSK2 |= (1<<OCIE2B);
}

void loop() {
  clocl?value++:value--;
  if (value==0) clocl = true;
  if (value==255) clocl = false;
  pwm_value[0] =255-value;
  pwm_value[1] =value;
  delayMicroseconds(500); 
}
