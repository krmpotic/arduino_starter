#include <Servo.h>

#define BAUD 9600
#define POT A0
#define DELAY_MS 20
#define SERVO 9

Servo sm;

int pot;
int ang;

void setup() {
	Serial.begin(BAUD);
	Serial.print("MOOD-CUE");
	Serial.print("\n");

	sm.attach(SERVO);
}

void loop() {
	pot = analogRead(POT);
	ang = map(pot, 0, 1023, 0, 179);
	Serial.print("pot: ");
	Serial.print(pot);
	Serial.print(", angle: ");
	Serial.print(ang);
	Serial.print("\n");

	sm.write(ang);
	delay(DELAY_MS);
}
