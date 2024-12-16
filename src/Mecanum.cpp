#include <Mecanum.h>

Mecanum::Mecanum(const MotorPins& frontLeft, const MotorPins& frontRight, const MotorPins& rearLeft, const MotorPins& rearRight)
    : frontLeftMotor(frontLeft), frontRightMotor(frontRight), rearLeftMotor(rearLeft), rearRightMotor(rearRight) {}
//Begin method
void Mecanum::begin() {
    pinMode(frontLeftMotor.forwardPin,OUTPUT);
    pinMode(frontLeftMotor.backwardPin,OUTPUT);

    pinMode(frontRightMotor.forwardPin,OUTPUT);
    pinMode(frontRightMotor.backwardPin,OUTPUT);

    pinMode(rearLeftMotor.forwardPin,OUTPUT);
    pinMode(rearLeftMotor.backwardPin,OUTPUT);

    pinMode(rearRightMotor.forwardPin,OUTPUT);
    pinMode(rearRightMotor.backwardPin,OUTPUT);
}
// Drive method based on coordinates x and y
/*void Mecanum::drive(float x, float y, float rotation) {
    // Calculate motor speeds based on x, y, and rotation
    float frontLeftSpeed = y + x + rotation;
    float frontRightSpeed = y - x - rotation;
    float rearLeftSpeed = y - x + rotation;
    float rearRightSpeed = y + x - rotation;

    // Constrain speeds to valid range
    frontLeftSpeed = constrainSpeed(frontLeftSpeed);
    frontRightSpeed = constrainSpeed(frontRightSpeed);
    rearLeftSpeed = constrainSpeed(rearLeftSpeed);
    rearRightSpeed = constrainSpeed(rearRightSpeed);

    // Set motor speeds
    setMotorSpeed(frontLeftMotor, frontLeftSpeed);
    setMotorSpeed(frontRightMotor, frontRightSpeed);
    setMotorSpeed(rearLeftMotor, rearLeftSpeed);
    setMotorSpeed(rearRightMotor, rearRightSpeed);
}*/
void Mecanum::driveForward() {
    
}