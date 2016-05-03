//#include "AudioDriver.h"

volatile int toggle;

void inline handler (void){
  toggle = (toggle == 1) ? 0 : 1;
  digitalWrite(2, toggle);
  timer0_write(ESP.getCycleCount() + 41660000);
}
 
void setup() {
  pinMode(2, OUTPUT);
  pinMode(14, OUTPUT);

  noInterrupts();
  timer0_isr_init();
  timer0_attachInterrupt(handler);
  timer0_write(ESP.getCycleCount() + 41660000);
  interrupts();
}

void loop() {
  delay(100);
  digitalWrite(14, HIGH);
  delay(100);
  digitalWrite(14, LOW);
}
