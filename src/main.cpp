#include <Arduino.h>
#include <Mecanum.h>

MotorPins frontLeft = {4,5};
MotorPins frontRight = {2,3};
MotorPins rearLeft = {8,9};
MotorPins rearRight = {6,7};
SensorPins front = {52,53};
SensorPins rear = {1,1};
SensorPins right = {1,1};
SensorPins left = {1,1};


Mecanum drivetrain(front, rear, right, left, frontLeft, frontRight, rearLeft, rearRight);

void setup() {
  drivetrain.begin();
  Serial.begin(9600);
}

void loop() {
  drivetrain.driveForward(100);
}