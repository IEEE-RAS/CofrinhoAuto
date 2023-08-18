#include <LiquidCrystal.h>

// Definições das portas LCD
LiquidCrystal lcd(4, 5, 6, 7, 8, 9, 10);

// Definições das variáveis que irão guardar a quantidade de moedas
int contUm = 0;
int contDois = 0;
int contTres = 0;

// Variáveis que irão guardar o estado anterior dos sensores
int lastStateDez = LOW;
int lastStateCinquenta = LOW;
int lastStateCem = LOW;

// Constantes para os pinos dos sensores e LEDs
const int sensorDezPin = 13;
const int sensorCinquentaPin = 12;
const int sensorCemPin = 11;
const int ledUmPin = 1;
const int ledDoisPin = 2;
const int ledTresPin = 3;

// Debounce delay para evitar leituras falsas nos sensores
const unsigned long debounceDelay = 50;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("-0,10:");
  lcd.setCursor(8, 0);
  lcd.print("-0,50:");
  lcd.setCursor(0, 1);
  lcd.print("-1,00:");

  pinMode(sensorDezPin, INPUT);
  pinMode(sensorCinquentaPin, INPUT);
  pinMode(sensorCemPin, INPUT);
  pinMode(ledUmPin, OUTPUT);
  pinMode(ledDoisPin, OUTPUT);
  pinMode(ledTresPin, OUTPUT);
}

void loop() {
  int sensorDezState = digitalRead(sensorDezPin);
  int sensorCinquentaState = digitalRead(sensorCinquentaPin);
  int sensorCemState = digitalRead(sensorCemPin);

  // Debounce nos sensores
  if (sensorDezState != lastStateDez) {
    delay(debounceDelay);
    sensorDezState = digitalRead(sensorDezPin);
  }
  if (sensorCinquentaState != lastStateCinquenta) {
    delay(debounceDelay);
    sensorCinquentaState = digitalRead(sensorCinquentaPin);
  }
  if (sensorCemState != lastStateCem) {
    delay(debounceDelay);
    sensorCemState = digitalRead(sensorCemPin);
  }

  // Contagem das moedas
  if (sensorDezState == HIGH && lastStateDez == LOW) {
    digitalWrite(ledUmPin, HIGH);
    contUm++;
    lcd.setCursor(6, 0);
    lcd.print(contUm);
    delay(1000);
    digitalWrite(ledUmPin, LOW);
  }
  if (sensorCinquentaState == HIGH && lastStateCinquenta == LOW) {
    digitalWrite(ledDoisPin, HIGH);
    contDois++;
    lcd.setCursor(14, 0);
    lcd.print(contDois);
    delay(1000);
    digitalWrite(ledDoisPin, LOW);
  }
  if (sensorCemState == HIGH && lastStateCem == LOW) {
    digitalWrite(ledTresPin, HIGH);
    contTres++;
    lcd.setCursor(6, 1);
    lcd.print(contTres);
    delay(1000);
    digitalWrite(ledTresPin, LOW);
  }

  // Atualizar o estado anterior dos sensores
  lastStateDez = sensorDezState;
  lastStateCinquenta = sensorCinquentaState;
  lastStateCem = sensorCemState;
}
