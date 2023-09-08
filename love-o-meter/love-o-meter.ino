#include "src/buildinfo.h"
#include "src/tmp36/tmp36.h"

// PINS
const int tmp36 = A0;
const int led_1 = 2;
const int led_2 = 3;
const int led_3 = 4;
// loop delay
const int dly_ms = 1000;
// thresholds in Celsius
const float cel_0 = 24.0;
const float cel_1 = 25.0;
const float cel_2 = 26.0;

void setup() {
  Serial.begin(9600);

  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);

  // LED test
  for (int i = 0; i < 5; i++) {
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
    delay(300);
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
    delay(300);
  }
}

void loop() {
  int raw = analogRead(tmp36);
  float vol = tmp36Vol(raw);
  float cel = tmp36Cel(raw);

  Serial.print(BUILD_GIT_SHORT);
  Serial.print(" TMP36 raw: ");
  Serial.print(raw);
  Serial.print(", vol: ");
  Serial.print(vol);
  Serial.print(", degC: ");
  Serial.print(cel);
  Serial.println();

  if (cel < cel_0) {
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
  } else if (cel >= cel_0 && cel < cel_1) {
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
  } else if (cel >= cel_1 && cel < cel_2) {
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, LOW);
  } else if (cel >= cel_2) {
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
  }
  
  delay(dly_ms);
}
