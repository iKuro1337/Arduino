int i=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
Serial.println("Start");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(i);
  delay(500);
  ESP.deepSleep(600000,WAKE_RF_DEFAULT);
  i++;
}
