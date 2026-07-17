#include <Servo.h>

// Motor Driver Pins
const int IN1 = 3;  
const int IN2 = 2;   
const int ENA = 11; 

const int IN3 = 5;  
const int IN4 = 4;   
const int ENB = 6;  

//  Ultrasonic Sensor Pins 
const int trigPin = 12;  
const int echoPin = 10;

// Servo Pin
const int servoPin = 8;

Servo myServo;

long duration;
int distance;
int servoAngle = 90;

void setup() {
  Serial.begin(9600);
  Serial.println("Fixed Robot Starting...");

  // Motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Ultrasonic pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Servo setup
  myServo.attach(servoPin);
  myServo.write(90);
}

void loop() {
  distance = getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 20 && distance > 0) {
    stopMotors();
    delay(300);
    int leftDist = lookLeft();
    delay(300);
    int rightDist = lookRight();
    delay(300);
    myServo.write(90);

    if (leftDist > rightDist) {
      turnLeft();
      delay(700);
    } else {
      turnRight();
      delay(700);
    }
  } else {
    moveForward();
  }

  delay(100);
}

//  Motor Functions
void moveForward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 200);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 200);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 200);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 200);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

int lookLeft() {
  myServo.write(150);
  delay(400);
  int dist = getDistance();
  Serial.print("Left: ");
  Serial.println(dist);
  return dist;
}

int lookRight() {
  myServo.write(30);
  delay(400);
  int dist = getDistance();
  Serial.print("Right: ");
  Serial.println(dist);
  return dist;
}
