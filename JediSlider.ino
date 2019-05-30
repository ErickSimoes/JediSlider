#include <Ultrasonic.h>

Ultrasonic ultrasonic(12, 13);
unsigned short distance;

const short enableButton = 2;

const short range = 5;
const short distanceBack = 5;
const short distanceNext = 30;

void setup() {
  Serial.begin(9600);
  pinMode(enableButton, INPUT_PULLUP);
}

void loop() {
  if (!digitalRead(enableButton)) {
    distance = ultrasonic.read();

    if (distance >= distanceNext - range && distance <= distanceNext + range) {
      Serial.println("Next slide");
    }

    if (distance >= distanceBack - range && distance <= distanceBack + range) {
      Serial.println("Back slide");
    }
  }

  delay(100);
}
