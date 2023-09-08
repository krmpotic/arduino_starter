#define DELAY 250
#define PUSH 2
#define GREEN 3
#define RED1 4
#define RED2 5

int switchState = 0;

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(RED1, OUTPUT);
  pinMode(RED2, OUTPUT);
  pinMode(PUSH, INPUT);
}

void loop() {
  switchState = digitalRead(PUSH);

  if (switchState == LOW) {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED1, LOW);
    digitalWrite(RED2, LOW);
  } else {
    digitalWrite(GREEN, LOW);

    digitalWrite(RED1, LOW);
    digitalWrite(RED2, HIGH);
    delay(DELAY);
    digitalWrite(RED1, HIGH);
    digitalWrite(RED2, LOW);
    delay(DELAY);
  }
}
