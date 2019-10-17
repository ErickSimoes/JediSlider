#include <Keyboard.h>
#include <Ultrasonic.h> //Get this library here: https://github.com/ErickSimoes/Ultrasonic

Ultrasonic ultrasonic(12, 13);
unsigned short distance;

const short enableButton = 2;

const short range = 5;
const short distanceBack = 5;
const short distanceNext = 30;

void setup() {
  Keyboard.begin();
  pinMode(enableButton, INPUT_PULLUP);
}

void loop() {
  if (!digitalRead(enableButton)) {
    distance = ultrasonic.read();

    if (distance >= distanceNext - range && distance <= distanceNext + range) {
      Keyboard.press(KEY_RIGHT_ARROW);
      Keyboard.releaseAll();
      delay(1000);
    }

    if (distance >= distanceBack - range && distance <= distanceBack + range) {
      Keyboard.press(KEY_LEFT_ARROW);
      Keyboard.releaseAll();
      delay(1000);
    }
  }

  delay(100);
}
