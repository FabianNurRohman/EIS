#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2);

int valorsensorgas;
int LED=7;

void setup() 
{ 
  
  pinMode(LED, OUTPUT);
  lcd.init(); // no mover
  lcd.backlight(); // no mover
  Serial.begin(9600);

}

void loop() 
{
  valorsensorgas = analogRead(A1);
  delay(100);
  lcd.clear();
  lcd.print("sensor_gas:");
  lcd.print(valorsensorgas,1); 
  Serial.print(valorsensorgas);
  Serial.println();
}
