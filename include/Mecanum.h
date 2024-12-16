#ifndef MECANUM_H
#define MECANUM_H

#include <Arduino.h>

struct MotorPins {
    int forwardPin;
    int backwardPin;
    // Mecanum drivetrain class
class MecanumDrivetrain {
public:
    // Constructor
    MecanumDrivetrain(const MotorPins& frontLeft, const MotorPins& frontRight, 
                      const MotorPins& rearLeft, const MotorPins& rearRight);

    // Initialization
    void begin();

    // Movement functions
    void drive(float x, float y, float rotation); // x: strafing, y: forward/backward, rotation: turning
    void stop(); // Stops all motors

private:
    // Private helper functions
    void setMotorSpeed(const MotorPins& motor, float speed);

    // Motor pins
    /*MotorPins frontLeftMotor;
    MotorPins frontRightMotor;
    MotorPins rearLeftMotor;
    MotorPins rearRightMotor;*/

    // Helper to constrain motor speed
    float constrainSpeed(float speed);
    };
}

#endif