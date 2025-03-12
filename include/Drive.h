#ifndef DRIVE_H
#define DRIVE_H
#include <Arduino.h>

struct MotorPins {
    int forwardPin;
    int backwardPin;
    int pwmPin;
};
struct SensorPins {
    int trigPin;
    int echoPin;
};

class Drive {
public:
    Drive(const SensorPins& frontSensorPins, 
    const SensorPins& rearSensorPins, 
    const SensorPins& rightSensorPins, 
    const SensorPins& leftSensorPins, 
    const MotorPins& leftMotor,
    const MotorPins& rightMotor);

    void begin();
    void stop();

    void driveForward(float speed);
    void turnRight(float speed);
    void turnLeft(float speed);

    float distance;
    float getDistance(SensorPins sensorLocation);

private:

    SensorPins frontSensorPins;
    SensorPins rearSensorPins;
    SensorPins rightSensorPins;
    SensorPins leftSensorPins;

    MotorPins leftMotor;
    MotorPins rightMotor;
};
#endif
