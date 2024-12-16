#ifndef MECANUM_H
#define MECANUM_H

#include <Arduino.h>

struct MotorPins {
    int forwardPin;
    int backwardPin;
};
struct sensorPins {
    int trigPin;
    int echoPin;
};

class Mecanum {
public:
    // Constructor
    Mecanum(const MotorPins& frontLeft, const MotorPins& frontRight, const MotorPins& rearLeft, const MotorPins& rearRight);

    // Initialization
    void begin();

    // Movement functions (maybe)
    //void drive(float x, float y, float rotation); // x: strafing, y: forward/backward, rotation: turning
    void driveForward();
    void driveBackward();
    void driveLeft();
    void driveRight();


    // Stops all motors
    void stop(); 

private:
    // Private helper functions
    void setMotorSpeed(const MotorPins& motor, float speed);

    // Motor pins
    MotorPins frontLeftMotor;
    MotorPins frontRightMotor;
    MotorPins rearLeftMotor;
    MotorPins rearRightMotor;

    // Helper to constrain motor speed
    float constrainSpeed(float speed);
};

#endif