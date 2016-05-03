#include <BH1750.h>
#include <Adafruit_NeoPixel.h>
#include <Wire.h>   // standardowa biblioteka Arduino
#include <LiquidCrystal_I2C.h> // dolaczenie pobranej biblioteki I2C dla LCD

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN           0

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      4

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu ukladu na 0x27
BH1750 czujnikSwiatla;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ400);

int x;
char buffer[10];

void setup() {
  //pinMode(12, OUTPUT);
  //pinMode(13, OUTPUT);
 
  TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
  TCCR1A|=(1<<WGM10)|(1<<WGM11)|(1<<COM1A1)|(1<<CS00);
  
  OCR0 = 0;  
  OCR1A = 0; 
  
  DDRB|=(1<<PB3);
  DDRD|=(1<<PD4);

  PORTB|=(1<<PB3);
  //TCCR1B|=(1<<WGM10)|(1<<WGM11)|(1<<COM1B1)|(1<<CS10);
  //OCR1B = 0; 
  //DDRD|=(1<<PD4);
  //TCCR1A = _BV(WGM12) | _BV(WGM11) | _BV(WGM10);
  //TCCR1A = _BV(COM1A0) | _BV(COM1B1) | _BV(WGM10);
  //TCCR1B = _BV(WGM12) | _BV(CS10);
  //OCR1A = 180;
  //OCR1B = 1;

  pixels.begin(); // This initializes the NeoPixel library.
  pixels.show(); // Initialize all pixels to 'off'
  
  czujnikSwiatla.configure(BH1750_CONTINUOUS_HIGH_RES_MODE);
  lcd.begin(20,4);   // Inicjalizacja LCD 2x16
  //lcd.autoscroll();
  lcd.backlight(); // zalaczenie podwietlenia 
  lcd.setCursor(0,0); // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna)
  lcd.print("Hello, world!");
  delay(500);
  lcd.setCursor(0,1); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
  lcd.print("BOTLAND.com.pl");
  delay(1000);
  lcd.clear();

}

float something;
float m;
int value;
uint16_t lux;
uint8_t pixel_R=0, pixel_G=0, pixel_B=0;
int flag=0;
//int val = 0;  

void loop() {
  //val = analogRead(0);
  something = x/1000.0;
  lux = czujnikSwiatla.readLightLevel();
  value = 127.9 + 128.0 * cos( something * 2.0 * PI  );
  OCR0 = x/4;
  OCR1B = x;
  delay(100);
  //analogWrite(12,value);
  sprintf(buffer, "%05d", x);
  lcd.setCursor(0,3);
  lcd.print(buffer);
  sprintf(buffer, "val: %03d", value);
  lcd.setCursor(0,2);
  lcd.print(buffer);
  sprintf(buffer, "lux: %03d", lux);
  lcd.setCursor(0,0);
  lcd.print(buffer); 
//  sprintf(buffer, "ana: %05d", val);
//  lcd.setCursor(10,0);
//  lcd.print(buffer);

//  // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
//  pixels.setPixelColor(0,pixel_R,pixel_G,pixel_B);
//  pixels.setPixelColor(1,pixel_R+5,pixel_G,pixel_B);
//  pixels.setPixelColor(2,pixel_R+10,pixel_G,pixel_B);
//  pixels.setPixelColor(3,pixel_R+15,pixel_G,pixel_B);
//  pixel_R=pixel_R+5;
//  if(pixel_R >= 255){
//    pixel_G=pixel_G+5;
//  }
//  if(pixel_G >=255){
//    pixel_B=pixel_B+5;
//  }
//  if(pixel_B>=255){
//    pixel_R=pixel_R-5;       
//  }
//  pixels.show();
//  
if (x>=1023){
  flag=1;
}
if (x==0){
  flag=0;
}
if(flag==0){
  x++;
}
if(flag==1){
  x--;
}
}
