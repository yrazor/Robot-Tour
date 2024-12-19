#include <Arduino.h>
#include <Mecanum.h>

//Pins
MotorPins frontLeft = {4,5};
MotorPins frontRight = {2,3};
MotorPins rearLeft = {8,9};
MotorPins rearRight = {6,7};
SensorPins front = {52,53};
SensorPins rear = {28,27};
SensorPins right = {47,48};
SensorPins left = {36,37};

// Mecanum object
Mecanum drivetrain(front, rear, right, left, frontLeft, frontRight, rearLeft, rearRight);

void setup() { // Init
  drivetrain.begin();
  Serial.begin(9600);
  Serial.println("Driving forward");
  drivetrain.driveForward(200);
  Serial.println("Driving backward");
  drivetrain.driveBackward(200);
  Serial.println("Driving right");
  drivetrain.driveRight(200);
  Serial.println("Driving left");
  drivetrain.driveLeft(200);

}

void loop() { //Driving
  //drivetrain.driveBackward(200);
  /*drivetrain.driveLeft(200);
  drivetrain.driveRight(200);*/
}