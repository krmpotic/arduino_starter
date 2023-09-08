const int sensorPin = A0;
const int led_1 = 2;
const int led_2 = 3;
const int led_3 = 4;
const int dly_ms = 1000;
const float baselineTemp = 22.0;


void setup() {
  Serial.begin(9600);

  for (int i = 2; i < 5; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

float tempSensorVol(int a) {
  return (sensorVal/1024.0) * 5.0;
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  float voltage = tempSensorVol(sensorVal);

  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  float temperature = (voltage - 0.5) * 100;
  Serial.print(temperature);

  if (temperature < baselineTemp) {
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
  } else if (temperature >= baselineTemp+2 && temperature < baselineTemp + 4) {
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
  } else if (temperature >= baselineTemp+4 && temperature < baselineTemp + 6) {
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, LOW);
  } else if (temperature >= baselineTemp + 6) {
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
  }

  Serial.print("\n");
  
  delay(dly_ms);
}
