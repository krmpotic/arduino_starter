#include "buildinfo.h"

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

float tmp36Vol(int r) {
  return (r/1024.0) * 5.0;
}

float tmp36Cel(int r) {
  float vol = tmp36Vol(r);
  return (vol - 0.5) * 100;
}

void tmp36Report(int raw, float vol, float cel) {
  Serial.print(BUILD_GIT_SHORT);
  Serial.print(" TMP36 raw: ");
  Serial.print(raw);
  Serial.print(", vol: ");
  Serial.print(vol);
  Serial.print(", degC: ");
  Serial.print(cel);
  Serial.println();
}

void ledLevel(int lvl) {
  int x1, x2, x3;
  x1 = x2 = x3 = LOW;

  if (lvl > 0)
    x1 = HIGH;
  if (lvl > 1)
    x2 = HIGH;
  if (lvl > 2)
    x3 = HIGH;

  digitalWrite(led_1, x1);
  digitalWrite(led_2, x2);
  digitalWrite(led_3, x3);
}

void setup() {
  Serial.begin(9600);

  for (int i = led_1; i <= led_3; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  int raw = analogRead(tmp36);
  float vol = tmp36Vol(raw);
  float cel = tmp36Cel(raw);
  tmp36Report(raw, vol, cel);

  if (cel < cel_0) {
    ledLevel(0);
  } else if (cel >= cel_0 && cel < cel_1) {
    ledLevel(1);
  } else if (cel >= cel_1 && cel < cel_2) {
    ledLevel(2);
  } else if (cel >= cel_2) {
    ledLevel(3);
  }
  
  delay(dly_ms);
}
