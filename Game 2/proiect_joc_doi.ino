#include <LCD_I2C.h>                                            //I2C LCD Driver
LCD_I2C lcd(0x27, 16, 2);                                       //setup lcd at hex addy 0x27, 16 columns, 2 rows
 
#define tacswitch 2                                             //tacswitch =2
#define redled 3                                                //redled =8
#define yelled 4                                                //yelled =9
#define greled 5                                               //greled =10
 
  long starttime = millis();                                    //start counter
  float redrand = random(100, 2000);                            // red led on for random time up to 2 seconds
  float yelrand = random(100, 3000);                            // yel led on for random time up to 3 sec
 

void setup() {
 
  Serial.begin(115200);
 
  pinMode(redled, OUTPUT);
  pinMode(yelled, OUTPUT);
  pinMode(greled, OUTPUT);
  pinMode(tacswitch, INPUT_PULLUP);
  digitalWrite(redled, LOW);
  digitalWrite(yelled, LOW);
  digitalWrite(greled, LOW);
 
  lcd.begin();
  lcd.backlight();
  lcd.print("Reaction Time");
  lcd.setCursor(0,1);
  lcd.print("   Game by Tudor");
  delay(1000);
  lcd.clear();
  //lcd.noBacklight();
  
  digitalWrite(redled,HIGH);
  delay(redrand);
  digitalWrite(redled,LOW);
  
  digitalWrite(yelled,HIGH);
  delay(yelrand);
  digitalWrite(yelled,LOW);
}
 
void loop() {
  delay(100);
  digitalWrite(greled, HIGH);
 
  if (digitalRead(2) == 0){
    
  long stoptime = millis();
  long mytime = (stoptime - starttime-1100-redrand-yelrand);
  lcd.setCursor(0,0);
  lcd.print("Your time is:");
  lcd.setCursor(0,1);
  lcd.print(mytime);
  lcd.print(" mSec:");
 
 
Serial.print("start - ");
Serial.println(starttime);
Serial.print("stop - ");
Serial.println(stoptime);
Serial.print("mytime - ");
Serial.print(mytime);
  }
}
