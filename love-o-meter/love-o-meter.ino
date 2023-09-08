#include "src/buildinfo.h"
#include "src/tmp36/tmp36.h"

// PINS
const int tmp36 = A0;
const int led_1 = 2;
const int led_2 = 3;
const int led_3 = 4;
// loop delay
const int dly_ms = 500;
// average temperature in celsius
const int avg_cel_cycles = 5;
float avg_cel = 0;
float del_1 = 3;
float del_2 = 4;
float del_3 = 5;

void setup() {
  Serial.begin(9600);

  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);

  // blink LEDs, and get starting temperature
  for (int i = 0; i < 5; i++) {
    Serial.print(" LOVE-O-METER INIT");
    // LED test
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
    delay(300);
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
    delay(300);

    int raw = analogRead(tmp36);
    float cel = tmp36Cel(raw);
    avg_cel += cel;
  }
  avg_cel /= (float)avg_cel_cycles;
}

void loop() {
  int raw = analogRead(tmp36);
  float vol = tmp36Vol(raw);
  float cel = tmp36Cel(raw);

  Serial.print("git-");
  Serial.print(BUILD_GIT_DIRTY);
  Serial.print(" TMP36(");
  Serial.print(raw);
  Serial.print(") ");
  Serial.print(vol);
  Serial.print("V ");
  Serial.print(cel);
  Serial.print("C (");
  Serial.print(cel-avg_cel);
  Serial.println(")");

  if (cel < avg_cel + del_1) {
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
  } else if (cel >= avg_cel + del_1 && cel < avg_cel + del_2) {
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
  } else if (cel >= avg_cel + del_2 && cel < avg_cel + del_3) {
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, LOW);
  } else if (cel >= avg_cel + del_3) {
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
  }
  
  delay(dly_ms);
}
