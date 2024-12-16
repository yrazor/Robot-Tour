#include <Mecanum.h>

Mecanum::Mecanum(const SensorPins& sensorPins, const MotorPins& frontLeft, const MotorPins& frontRight, const MotorPins& rearLeft, const MotorPins& rearRight)
    : sensorPins(sensorPins), frontLeftMotor(frontLeft), frontRightMotor(frontRight), rearLeftMotor(rearLeft), rearRightMotor(rearRight) {}
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

    pinMode(sensorPins.trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(sensorPins.echoPin, INPUT); // Sets the echoPin as an Input
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
void Mecanum::driveForward(float speed) {
    
}
// Function to get distance from ultrasonic sensor
float getDistance() {
  // Send a 10-microsecond pulse to the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse
  long duration = pulseIn(echoPin, HIGH);

  // Convert the duration to distance (cm)
  float distance = duration * 0.034 / 2;

  return distance;
}