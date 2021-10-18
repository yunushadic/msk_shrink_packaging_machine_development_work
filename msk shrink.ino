#include<LiquidCrystal_I2C_Hangul.h>
#include<Wire.h>
#include<DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

LiquidCrystal_I2C_Hangul lcd(0x27,16,2); //LCD 클래스 초기화

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  
}

void loop() {
  float temp=0;
  
 temp=dht.readTemperature();
 int x=temp;
 
  int speedParameter=100+((x-20)*0.5);
  int timeParameter=100-((x-20)*0.5);
  lcd.print("   BASTURKCAM");
  lcd.setCursor(0,1);
  lcd.print("     SANAYI");
  delay(2500);
  lcd.clear();
  lcd.print(" Shrink cevresi");
  lcd.setCursor(0,1);
  lcd.print("   sicakligi:");
  delay(2500);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print(" ");
  lcd.print(x);
  lcd.print(" derece");
  delay(2500);
  lcd.clear();
  lcd.print("   speed : ");
  lcd.print(speedParameter);
  lcd.setCursor(0,1);
  lcd.print("    yapiniz");
  delay(2500);
  lcd.clear();
  lcd.print("   time : ");
  lcd.print(timeParameter);
  lcd.setCursor(0,1);
  lcd.print("    yapiniz");
  delay(2500);
  lcd.clear();
  lcd.print("    made by");
  lcd.setCursor(0,1);
  lcd.print("  Yunus HADIC");
  delay(2500);
  lcd.clear();
 
  
  
  
  
  
}
