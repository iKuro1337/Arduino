#include <CapacitiveSensor.h>

/*
   CapitiveSense Library Demo Sketch
   Paul Badger 2008
   Uses a high value resistor e.g. 10M between send pin and receive pin
   Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
   Receive pin is the sensor pin - try different amounts of foil/metal on this pin
*/


CapacitiveSensor   cs_14_5 = CapacitiveSensor(14, 5);       // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_12_4 = CapacitiveSensor(12, 4);       // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil

void setup()
{
  cs_14_5.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  cs_12_4.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  Serial.begin(9600);
}

void loop()
{
  long start = millis();
  long total1 =  cs_14_5.capacitiveSensorRaw(10);
  long total2 =  cs_12_4.capacitiveSensorRaw(10);

  Serial.print(millis() - start);        // check on performance in milliseconds
  Serial.print("\t");                    // tab character for debug windown spacing

  Serial.print(total1);                  // print sensor output 1
  Serial.print("\t");
  Serial.print(total2);                  // print sensor output 2
  Serial.println("\t");

  delay(10);                             // arbitrary delay to limit data to serial port
}
