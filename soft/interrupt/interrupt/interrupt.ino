volatile int toggle;

void setup()
{                
  //Serial.begin(115200);
  pinMode(12, INPUT_PULLUP);
  attachInterrupt(12, pinChanged, CHANGE); //NEED PROPER DEBOUNCING
  pinMode(14, OUTPUT);
}

void loop()                     
{
}

void pinChanged()
{
  toggle = (toggle == 1) ? 0 : 1;
  digitalWrite(14, toggle);
}
