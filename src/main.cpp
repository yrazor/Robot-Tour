#include <Arduino.h>
#include <Mecanum.h>

//Pins
MotorPins frontLeft = {4,5};
MotorPins frontRight = {2,3};
MotorPins rearLeft = {8,9};
MotorPins rearRight = {6,7};
SensorPins front = {52,53};
SensorPins rear = {1,1};
SensorPins right = {1,1};
SensorPins left = {1,1};

// Mecanum object
Mecanum drivetrain(front, rear, right, left, frontLeft, frontRight, rearLeft, rearRight);

void setup() { // Init
  drivetrain.begin();
  Serial.begin(9600);
  drivetrain.driveForward(200);
  drivetrain.driveBackward(200);
  drivetrain.driveRight(200);
  drivetrain.driveLeft(200);

}

void loop() { //Driving
  //drivetrain.driveBackward(200);
  /*drivetrain.driveLeft(200);
  drivetrain.driveRight(200);*/
}