#ifndef MECANUM_H
#define MECANUM_H

#include <Arduino.h>

struct MotorPins {
    int forwardPin;
    int backwardPin;
};
struct SensorPins {
    int trigPin;
    int echoPin;
};

class Mecanum {
public:
    // Constructor
    Mecanum(const SensorPins& frontSensorPins, 
    const SensorPins& rearSensorPins, 
    const SensorPins& rightSensorPins, 
    const SensorPins& leftSensorPins, 
    const MotorPins& frontLeft, 
    const MotorPins& frontRight, 
    const MotorPins& rearLeft, 
    const MotorPins& rearRight);

    // Initialization
    void begin();

    // Movement functions (maybe)
    //void drive(float x, float y, float rotation); // x: strafing, y: forward/backward, rotation: turning
    void driveForward(float speed);
    void driveBackward(float speed);
    void driveLeft(float speed);
    void driveRight(float speed);


    // Stops all motors
    void stop(); 

    float distance;
    float dist;

    // Helper to constrain motor speed
    //float constrainSpeed(float speed);
    float getDistance(SensorPins sensorLocation);

private:
    // Private helper functions
    //void setMotorSpeed(const MotorPins& motor, float speed);

    // Motor pins
    MotorPins frontLeftMotor;
    MotorPins frontRightMotor;
    MotorPins rearLeftMotor;
    MotorPins rearRightMotor;
    // Sensor pins
    SensorPins frontSensorPins;
    SensorPins rearSensorPins;
    SensorPins rightSensorPins;
    SensorPins leftSensorPins;
};

#endif