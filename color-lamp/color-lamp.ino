#include "src/buildinfo.h"

#define SERIAL_BAUD 9600

// pins
#define LED_RED 11
#define LED_GREEN 9
#define LED_BLUE 10
#define SENS_RED A0
#define SENS_GREEN A1
#define SENS_BLUE A2

int red = 0;
int green = 0;
int blue = 0;
int sens_red = 0;
int sens_green = 0;
int sens_blue = 0;

void setup() {
	Serial.begin(SERIAL_BAUD);

	pinMode(LED_RED, OUTPUT);
	pinMode(LED_GREEN, OUTPUT);
	pinMode(LED_BLUE, OUTPUT);

	// LED test
	for (int i = 0; i < 3; i++) {
		digitalWrite(LED_RED, HIGH);
		digitalWrite(LED_GREEN, HIGH);
		digitalWrite(LED_BLUE, HIGH);
		delay(200);
		digitalWrite(LED_RED, LOW);
		digitalWrite(LED_GREEN, LOW);
		digitalWrite(LED_BLUE, LOW);
		delay(200);

		// header
		Serial.print("COLOR-LAMP - ");
		Serial.println(BUILD_GIT_DIRTY);
	}
}

void loop() {
	sens_red = analogRead(SENS_RED);
	delay(5);
	sens_green = analogRead(SENS_GREEN);
	delay(5);
	sens_blue = analogRead(SENS_BLUE);
	delay(5);

	red = sens_red/4;
	green = sens_green/4;
	blue = sens_blue/4;

	analogWrite(LED_RED, red);
	analogWrite(LED_GREEN, green);
	analogWrite(LED_BLUE, blue);

	Serial.print(BUILD_GIT_SHORT);
	Serial.print(" R-");
	Serial.print(red);
	Serial.print(" G-");
	Serial.print(green);
	Serial.print(" B-");
	Serial.print(blue);
	Serial.println();
}
