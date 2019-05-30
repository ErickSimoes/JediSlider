#include <Ultrasonic.h>

Ultrasonic ultrasonic(12, 13);
unsigned short distance;

const short range = 5;
const short distanceBack = 5;
const short distanceNext = 30;

void setup() {
  Serial.begin(9600);
}

void loop() {
  distance = ultrasonic.read();

  if(distance >= distanceNext - range && distance <= distanceNext + range) {
    Serial.println("Next slide");
  }

  if(distance >= distanceBack - range && distance <= distanceBack + range) {
    Serial.println("Back slide");
  }
  
  delay(100);
}
