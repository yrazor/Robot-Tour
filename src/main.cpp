#include <Arduino.h>
#include <Drive.h>

#define BUTTON_PIN 13

SensorPins frontSensorPins = {};
SensorPins rearSensorPins = {};
SensorPins rightSensorPins = {};
SensorPins leftSensorPins = {};
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