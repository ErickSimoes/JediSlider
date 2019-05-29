#include <Ultrasonic.h>

Ultrasonic ultrasonic(12, 13);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(ultrasonic.read());
  delay(1000);
}
