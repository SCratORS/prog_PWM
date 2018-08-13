#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
void fCOM2B1 (uint8_t val) {DDRD |= 0x08; if (val == 0x00) {cbi(TCCR2A, COM2B1); PORTD &= ~0x08;} else if (val == 0xFF) {cbi(TCCR2A, COM2B1); PORTD |= 0x08;} else {sbi(TCCR2A, COM2B1); OCR2B = val;}}//D3
void fCOM0A1 (uint8_t val) {DDRD |= 0x20; if (val == 0x00) {cbi(TCCR0A, COM0A1); PORTD &= ~0x20;} else if (val == 0xFF) {cbi(TCCR0A, COM0A1); PORTD |= 0x20;} else {sbi(TCCR0A, COM0A1); OCR0A = val;}}//D5
void fCOM0B1 (uint8_t val) {DDRD |= 0x40; if (val == 0x00) {cbi(TCCR0A, COM0B1); PORTD &= ~0x40;} else if (val == 0xFF) {cbi(TCCR0A, COM0B1); PORTD |= 0x40;} else {sbi(TCCR0A, COM0B1); OCR0B = val;}}//D6
void fCOM1A1 (uint8_t val) {DDRB |= 0x02; if (val == 0x00) {cbi(TCCR1A, COM1A1); PORTB &= ~0x02;} else if (val == 0xFF) {cbi(TCCR1A, COM1A1); PORTB |= 0x02;} else {sbi(TCCR1A, COM1A1); OCR1A = val;}}//D9
void fCOM1B1 (uint8_t val) {DDRB |= 0x04; if (val == 0x00) {cbi(TCCR1A, COM1B1); PORTB &= ~0x04;} else if (val == 0xFF) {cbi(TCCR1A, COM1B1); PORTB |= 0x04;} else {sbi(TCCR1A, COM1B1); OCR1B = val;}}//D10
void fCOM2A1 (uint8_t val) {DDRB |= 0x08; if (val == 0x00) {cbi(TCCR2A, COM2A1); PORTB &= ~0x08;} else if (val == 0xFF) {cbi(TCCR2A, COM2A1); PORTB |= 0x08;} else {sbi(TCCR2A, COM2A1); OCR2A = val;}}//D11
void (*analogFastWrite[])(uint8_t) = {&fCOM2B1,&fCOM0A1,&fCOM0B1,&fCOM1A1,&fCOM1B1,&fCOM2A1};

void setup() {
  // put your setup code here, to run once:
}

void loop() {
analogFastWrite[1](128);
}
