#include <BH1750.h>

#include <Wire.h>   // standardowa biblioteka Arduino
#include <LiquidCrystal_I2C.h> // dolaczenie pobranej biblioteki I2C dla LCD

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu ukladu na 0x27
BH1750 czujnikSwiatla;

int x;
char buffer[10];

void setup() {
  // put your setup code here, to run once:
  pinMode(12,OUTPUT);
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
int value,value_max=0, value_min=10; 
uint16_t lux;

void loop() {
  lux = czujnikSwiatla.readLightLevel();
  // put your main code here, to run repeatedly:
  //digitalWrite(14,HIGH);
  //lcd.backlight();
  //delay(500);
  //digitalWrite(14,LOW);
  //lcd.noBacklight();
  something = x/1000.0;
  value = 127.9 + 128.0 * cos( something * 2.0 * PI  );
  if (value > value_max){
    value_max = value;
  }
  if (value < value_min){
    value_min = value;
  }
  analogWrite(12,value);
  sprintf(buffer, "%05d", x);
  lcd.setCursor(0,3); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
  lcd.print(buffer);
  sprintf(buffer, "val: %03d", value);
  lcd.setCursor(0,2); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
  lcd.print(buffer);
  sprintf(buffer, "max: %03d", value_max);
  lcd.setCursor(10,2); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
  lcd.print(buffer);
  sprintf(buffer, "min: %03d", value_min);
  lcd.setCursor(10,3); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
  lcd.print(buffer);
  sprintf(buffer, "lux: %03d", lux);
  lcd.setCursor(0,0); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
  lcd.print(buffer);
  x++;
}
