//Game 1
//Primul joc testeaza reactia prin aprinderea pe rand a 5 led-uri, iar jucatorul trebuie sa apese
//butonul cand led-ul din mijloc este aprins. Viteza de aprindere a led-urilor creste cu fiecare
//apasare corecta.


const int buttonPin = 2;
const int LED1 = 7;
const int LED2 = 6;
const int LED3 = 5;
const int LED4 = 4;
const int LED5 = 3;

int counter = 0; //numarul led-ului aprins
long previousTime = millis();
long interval = 1000; //timpul de asteptare pana cand se schimba led-ul


void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

void loop() {
  long currentTime = millis();

  if (digitalRead(buttonPin) == HIGH) {
    // verifica daca e apasat cand e aprins becul verde
    if (counter == 3) {
      // indica ca este
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      delay(500);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      // reseteaza counter
      counter = 0;
      // speed up
      interval = interval / 1.8;
    } else {
      // indica ca nu e
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      delay(500);
      // inapoi la nivelul 1
      interval = 1000;
      // reset pentru counter.
      counter = 0;
    }
  }
  
  //aprinderea si stingerea led-urilor
  if (currentTime - previousTime >= interval) {
      previousTime = currentTime;
      if (counter == 0) {
        digitalWrite(LED5, LOW);
        digitalWrite(LED1, HIGH);
        counter++;
      } else if (counter == 1) {
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        counter++;
      } else if (counter == 2) {
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, HIGH);
        counter++;
      } else if (counter == 3) {
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, HIGH);
        counter++;
      } else if (counter == 4) {
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, HIGH);
        counter = 0;
      }
  }
}
