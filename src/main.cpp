#include <Arduino.h>
#include <Drive.h>

#define BUTTON_PIN 13

SensorPins frontSensorPins = {52,53};
SensorPins rearSensorPins = {48,49};
SensorPins rightSensorPins = {50,51};
SensorPins leftSensorPins = {46,47};
MotorPins leftMotor = {5,6,7};
MotorPins rightMotor = {9,10,11};


Drive drivetrain(frontSensorPins, 
    rearSensorPins, 
    rightSensorPins, 
    leftSensorPins, 
    leftMotor, 
    rightMotor
    );

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    drivetrain.begin();
    Serial.begin(9600);
}
void loop() {
    if (digitalRead(BUTTON_PIN) == LOW) {
        delay(500);
        drivetrain.driveForward(100);
        drivetrain.turnLeft(100);
        drivetrain.turnRight(100);

    }
}