#include<LiquidCrystal.h> 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
 
const int lm35Pin = A0; 
 
void setup() { 
  lcd.begin(16, 2); 
  lcd.print("Temp Sensor Ready"); 
  delay(1500); 
  lcd.clear(); 
} 
 
void loop() { 
  int rawValue = analogRead(lm35Pin); 
  float voltage = rawValue * (5.0 / 1023.0);    
  float temperatureC = voltage * 100.0;         
 
  lcd.setCursor(0, 0); 
  lcd.print("Temp: "); 
  lcd.print(temperatureC, 1);  
  lcd.print((char)223);  
  lcd.print("C"); 
 
  delay(1000); 
}