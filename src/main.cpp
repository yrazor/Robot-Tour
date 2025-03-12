#include <Arduino.h>
#include <Drive.h>
//Define pins
#define BUTTON_PIN 13
SensorPins frontSensorPins = {52,53};
SensorPins rearSensorPins = {48,49};
SensorPins rightSensorPins = {50,51};
SensorPins leftSensorPins = {46,47};
MotorPins leftMotor = {6,5,7};
MotorPins rightMotor = {10,9,11};

//Drivetrain object
Drive drivetrain(frontSensorPins, 
    rearSensorPins, 
    rightSensorPins, 
    leftSensorPins, 
    leftMotor, 
    rightMotor
    );

//Initialization
void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    drivetrain.begin();
    Serial.begin(9600);
}

//Main loops
void loop() {
    //Start driving when the button is pressed
    if (digitalRead(BUTTON_PIN) == LOW) {
        delay(500);
        Serial.println("Button pressed");
        drivetrain.driveForward(250);
        drivetrain.turnLeft(250);
        drivetrain.turnRight(250);

    }
}