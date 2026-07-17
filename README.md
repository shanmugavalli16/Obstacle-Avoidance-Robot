#  Obstacle Avoiding Robot using Arduino Uno

An autonomous obstacle-avoiding robot built using **Arduino Uno**, **HC-SR04 Ultrasonic Sensor**, **SG90 Servo Motor**, and **L298N Motor Driver**. The robot detects obstacles, scans the left and right directions, and automatically chooses the safest path for navigation.

---

##  Project Description

This project demonstrates autonomous navigation using an ultrasonic sensor mounted on a servo motor. The Arduino continuously measures the distance in front of the robot. If an obstacle is detected within 20 cm, the robot stops, scans both left and right directions, compares the available space, and turns toward the direction with the greater clearance before continuing forward.

---

# 🛠 Components Used

| Component | Quantity |
|------------|----------|
| Arduino Uno | 1 |
| L298N Motor Driver | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| SG90 Servo Motor | 1 |
| DC Geared Motors | 2 |
| Robot Chassis | 1 |
| Wheels | 2 |
| Caster Wheel | 1 |
| Battery Pack | 1 |

---

# Final Pin Connections

## L298N Motor Driver

| L298N | Arduino |
|--------|----------|
| IN1 | D3 |
| IN2 | D2 |
| IN3 | D5 |
| IN4 | D4 |
| ENA | D11 (PWM) |
| ENB | D6 (PWM) |
| GND | Arduino GND |
| 12V | Battery Positive |

---

## HC-SR04 Ultrasonic Sensor

| HC-SR04 | Arduino |
|----------|----------|
| VCC | 5V |
| GND | GND |
| TRIG | D12 |
| ECHO | D10 |

---

## SG90 Servo

| Servo | Arduino |
|--------|----------|
| Signal | D8 |
| VCC | 5V |
| GND | GND |

---

#  Module Testing

## 1️.Motor Driver Test

### Objective

Verify that both motors rotate correctly.

### Connections

| L298N | Arduino |
|--------|----------|
| IN1 | D2 |
| IN2 | D3 |
| IN3 | D4 |
| IN4 | D5 |
| ENA | D9 |
| ENB | D10 |

---

## 2️. Ultrasonic Sensor Test

### Connections

| HC-SR04 | Arduino |
|----------|----------|
| VCC | 5V |
| GND | GND |
| TRIG | D9 |
| ECHO | D10 |

## 3️.Servo Motor Test

### Connections

| Servo | Arduino |
|--------|----------|
| Signal | D9 |
| VCC | 5V |
| GND | GND |



## 4️.Servo + Ultrasonic Test

### Purpose

Verify that the servo scans left, center, and right while measuring the distance.

### Final Connections

| Component | Pin |
|------------|-----|
| Servo | D8 |
| Trigger | D12 |
| Echo | D10 |


# Final Obstacle Avoidance

### Working Principle

1. Robot moves forward.
2. Continuously measures distance.
3. If obstacle < 20 cm
   - Stop motors
   - Scan left
   - Scan right
   - Compare distances
   - Turn toward the larger distance
4. Continue moving.

---

## Final Arduino Pin Mapping

| Component | Arduino Pin |
|------------|-------------|
| IN1 | D3 |
| IN2 | D2 |
| IN3 | D5 |
| IN4 | D4 |
| ENA | D11 |
| ENB | D6 |
| Servo | D8 |
| Trigger | D12 |
| Echo | D10 |

---

# 🚀 Future Improvements

- Bluetooth Control
- Wi-Fi Control (ESP32)
- Camera-based Object Detection
- Voice Control
- AI-based Path Planning

---
