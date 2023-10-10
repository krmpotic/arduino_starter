#define CALIB_MS 5000
#define PITCH_LOW 50
#define PITCH_HIGH 4000
#define TONE_MS 20
#define LOOP_MS 10

#define PIN_PHOTO A0
#define PIN_PIEZO 8
#define PIN_LED 13

int sensor;
int sensor_low = 1023;
int sensor_high = 0;

void setup() {
	Serial.begin(SERIAL_BAUD);
	Serial.print("LIGHT-THEREMIN - ");
	Serial.print(BUILD_GIT_DIRTY);
	Serial.print("\n");

	pinMode(PIN_LED, OUTPUT);

	// calibrate the sensor
	digitalWrite(PIN_LED, HIGH);
	while (millis() < CALIB_MS) {
		sensor = analogRead(PIN_PHOTO);
		if (sensor > sensor_high)
			sensor_high = sensor;
		if (sensor < sensor_low)
			sensor_low = sensor;
	}
	digitalWrite(PIN_LED, LOW);
}

void loop() {
	sensor = analogRead(PIN_PHOTO);
	Serial.print("sensor: ");
	Serial.print(sensor);
	Serial.print("\n");

	int pitch = map(sensor, sensor_low, sensor_high, PITCH_LOW, PITCH_HIGH);
	tone(PIN_PIEZO, pitch, TONE_MS);
	delay(LOOP_MS);
}
