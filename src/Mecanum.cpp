#include <Mecanum.h>

Mecanum::Mecanum(const SensorPins& frontSensorPins, 
const SensorPins& rearSensorPins, 
const SensorPins& rightSensorPins, 
const SensorPins& leftSensorPins, 
const MotorPins& frontLeft, 
const MotorPins& frontRight, 
const MotorPins& rearLeft, 
const MotorPins& rearRight)
    : frontSensorPins(frontSensorPins), 
    rearSensorPins(rearSensorPins), 
    rightSensorPins(rightSensorPins), 
    leftSensorPins(leftSensorPins), 
    frontLeftMotor(frontLeft), 
    frontRightMotor(frontRight), 
    rearLeftMotor(rearLeft), 
    rearRightMotor(rearRight) {}
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

    pinMode(frontSensorPins.trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(frontSensorPins.echoPin, INPUT); // Sets the echoPin as an Input

    pinMode(rearSensorPins.trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(rearSensorPins.echoPin, INPUT); // Sets the echoPin as an Input

    pinMode(rightSensorPins.trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(rightSensorPins.echoPin, INPUT); // Sets the echoPin as an Input

    pinMode(leftSensorPins.trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(leftSensorPins.echoPin, INPUT); // Sets the echoPin as an Input
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

// Drive in each direction
void Mecanum::driveForward(float speed) {
    int counter = 0;

    analogWrite(frontLeftMotor.forwardPin,speed);
    analogWrite(frontRightMotor.forwardPin,speed);
    analogWrite(rearLeftMotor.forwardPin,speed);
    analogWrite(rearRightMotor.forwardPin,speed);
    Serial.println("Driving forward");
    Serial.println("Motor speeds:");
    Serial.println(speed);
    while (true) {
        float dist = Mecanum::getDistance(frontSensorPins);
        if (dist <= 6) {
            counter++;
            if (counter >= 5) {
                Mecanum::stop();
                break;
            }
        } 
    }
}
void Mecanum::driveBackward(float speed) {
    int counter = 0;

    analogWrite(frontLeftMotor.backwardPin,speed);
    analogWrite(frontRightMotor.backwardPin,speed);
    analogWrite(rearLeftMotor.backwardPin,speed);
    analogWrite(rearRightMotor.backwardPin,speed);
    Serial.println("Driving backward");
    while (true) {
        float dist = Mecanum::getDistance(rearSensorPins);
        if (dist <= 6) {
            counter++;
            if (counter >= 5) {
                Mecanum::stop();
                break;
            }
        } 
    }
}
void Mecanum::driveLeft(float speed) {
    int counter = 0;

    analogWrite(frontLeftMotor.backwardPin,speed);
    analogWrite(frontRightMotor.forwardPin,speed);
    analogWrite(rearLeftMotor.forwardPin,speed);
    analogWrite(rearRightMotor.backwardPin,speed);
    Serial.println("Driving left");

    while (true) {
        float dist = Mecanum::getDistance(leftSensorPins);
        if (dist <= 6) {
            counter++;
            if (counter >= 5) {
                Mecanum::stop();
                break;
            }
        } 
    }
}
void Mecanum::driveRight(float speed) {
    int counter = 0;

    analogWrite(frontLeftMotor.forwardPin,speed);
    analogWrite(frontRightMotor.backwardPin,speed);
    analogWrite(rearLeftMotor.backwardPin,speed);
    analogWrite(rearRightMotor.forwardPin,speed);
    Serial.println("Driving right");
    while (true) {
        float dist = Mecanum::getDistance(rightSensorPins);
        if (dist <= 6) {
            counter++;
            if (counter >= 5) {
                Mecanum::stop();
                break;
            }
        } 
    }
}

//Set all motor speed to 0 and distance far
void Mecanum::stop() {
    analogWrite(frontLeftMotor.forwardPin,0);
    analogWrite(frontRightMotor.forwardPin,0);
    analogWrite(rearLeftMotor.forwardPin,0);
    analogWrite(rearRightMotor.forwardPin,0);
    //distance = 100;
    //Serial.println("Motors stopped");
}

// Function to get distance from ultrasonic sensor
float Mecanum::getDistance(SensorPins sensorLocation) {
  // Send a 10-microsecond pulse to the trigger pin
  digitalWrite(sensorLocation.trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sensorLocation.trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorLocation.trigPin, LOW);

  // Measure the duration of the echo pulse
  long duration = pulseIn(sensorLocation.echoPin, HIGH);

  // Convert the duration to distance (cm)
  distance = duration * 0.034 / 2;
  //Serial.println(distance);
  return distance;
}