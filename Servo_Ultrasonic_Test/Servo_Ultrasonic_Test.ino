#include <Servo.h>

Servo myServo;

const int trigPin = 12;
const int echoPin = 10;

long duration;

int getDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  return duration * 0.034 / 2;
}

void setup() {

  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(8);
}

void loop() {

  myServo.write(30);
  delay(500);

  Serial.print("Right : ");
  Serial.println(getDistance());

  myServo.write(90);
  delay(500);

  Serial.print("Center : ");
  Serial.println(getDistance());

  myServo.write(150);
  delay(500);

  Serial.print("Left : ");
  Serial.println(getDistance());

  Serial.println("----------------");

  delay(1000);
}
