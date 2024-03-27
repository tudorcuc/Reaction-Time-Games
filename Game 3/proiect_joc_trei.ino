//Game 3
//Al treilea joc testeaza reactia prin aprinderea random, pe rand, a cate unui bec
//Fiecare bec este amplasat in dreptul unui buton. Cand un bec este aprins, jucatorul trebuie
//sa apese butonul cat mai repede. Daca reuseste, i se adauga 1 la scor, care va fi afisat pe lcd la final

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int numLEDs = 5;
const int ledPins[] = {2, 3, 4, 5, 6};
const int buttonPins[] = {7, 8, 9, 10, 11};

int activeLed;
int score = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);

  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  activeLed = random(0, numLEDs);
  digitalWrite(ledPins[activeLed], HIGH);
  delay(1000);

  digitalWrite(ledPins[activeLed], LOW);
  int buttonPressed = waitForButtonPress();
  if (buttonPressed == activeLed) {
    score++;
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Scor: ");
    lcd.print(score);
    score = 0;
  }
  
  delay(500);
}

int waitForButtonPress() {
  int buttonIndex = -1;
  
  while (buttonIndex == -1) {
    for (int i = 0; i < numLEDs; i++) {
      if (digitalRead(buttonPins[i]) == HIGH) {
        while (digitalRead(buttonPins[i]) == HIGH);
        buttonIndex = i;
        break;
       }
    }
  }
  return buttonIndex;
}
