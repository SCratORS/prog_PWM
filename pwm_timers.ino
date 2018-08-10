/*
 *     128  64  32  16   8   4   2   1
 * __________________________________
 * B   --- --- D13 D12 D11 D10 D09 D08 | PORT B (D8..D13)
 * DDR   0   0   0   0   1   1   1   0 | 14  (0-INPUT, 1-OUTPUT)
 * PORT  0   0   0   0   0   0   0   0 | 0   (0 - LOW, 1 -HIGH)
 * __________________________________
 * C   A07 A06 A05 A04 A03 A02 A01 A00 | PORT C (A0..A7)
 * DDR   0   0   1   1   1   1   1   1 | 63  (0-INPUT, 1-OUTPUT)
 * PORT  0   0   0   0   0   0   1   1 | 3   (0 - LOW, 1 -HIGH)  
 * __________________________________
 * D   D07 D06 D05 D04 D03 D02 D01 D00 | PORT D (D0..D7)
 * DDR   0   1   1   0   1   0   0   0 | 104 (0-INPUT, 1-OUTPUT)
 * PORT  0   0   0   0   0   0   0   0 | 0   (0 - LOW, 1 -HIGH)
 * 
 */

byte bit = 8; //D13
boolean clocl = true; //Флаг Увеличения или уменьшения яркости        
byte value = 0; //Текущее значение яркости  

ISR (TIMER2_OVF_vect){
  if (OCR2B>1) PORTD |= bit;
}
ISR (TIMER2_COMPB_vect){
  PORTD &= ~bit;
}

void setup() {
  OCR2B  = 0x10;
  DDRD   |= bit;
  TIMSK2 |= (1<<OCIE2B)|(1<<TOIE2);
}

void loop() {
  clocl?value++:value--;      //Смотрим в какую сторону надо крутить яркость и крутим
  if (value==0x00) clocl = true;  //Если докрутили до минимума, то дальше будем крутить в плюс
  if (value==0xFF) clocl = false; //Если докрутили до максимума,то дальше будем крутить в минус
  OCR2B = value;
  delay(1);
  // put your main code here, to run repeatedly:
}
