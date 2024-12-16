#include <Arduino.h>
#include <Mecanum.h>

MotorPins frontLeft = {};
MotorPins frontRight = {};
MotorPins rearLeft = {4,5};
MotorPins rearRight = {2,3};

Mecanum drivetrain(frontLeft, frontRight, rearLeft, rearRight);

void setup() {
    drivetrain.begin();
}