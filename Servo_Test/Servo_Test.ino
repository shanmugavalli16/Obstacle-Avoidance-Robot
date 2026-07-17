#include <Servo.h>
Servo sg90Servo;  
void setup() {
  sg90Servo.attach(9);  
}
void loop() {
  sg90Servo.write(0);// Move to 0 degrees
  delay(1000);
  sg90Servo.write(90); // Move to Center position
  delay(1000);
  sg90Servo.write(180); // Move to 180 degrees
  delay(1000);
}
