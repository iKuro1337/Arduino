//#include <user_config.h>
//#include <SmingCore/SmingCore.h>
#include <BH1750FVI.h>

/*
Set the Address pin state to change I2C address:
BH1750FVI_ADDRESS_LOW  "0x23" - usually by default
BH1750FVI_ADDRESS_HIGH  "0x5C"
*/
BH1750FVI LightSensor(BH1750FVI_ADDRESS_LOW);

//Timer procTimer;


void readLight()
{
  Serial.println("Reading");
  uint16_t lux = LightSensor.getLightIntensity();// Get Lux value
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lux");
}

void init()
{

  LightSensor.setMode(BH1750_Continuous_H_resolution_Mode);

}
