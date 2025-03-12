#include <Drive.h>

Drive::Drive(const SensorPins& frontSensorPins, 
    const SensorPins& rearSensorPins, 
    const SensorPins& rightSensorPins, 
    const SensorPins& leftSensorPins, 
    const MotorPins& leftMotor,
    const MotorPins& rightMotor)
        : frontSensorPins(frontSensorPins), 
        rearSensorPins(rearSensorPins), 
        rightSensorPins(rightSensorPins), 
        leftSensorPins(leftSensorPins), 
        leftMotor(leftMotor),
        rightMotor(rightMotor) {} 


void Drive::begin() {
    pinMode(frontSensorPins.trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(frontSensorPins.echoPin, INPUT); // Sets the echoPin as an Input

    pinMode(rearSensorPins.trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(rearSensorPins.echoPin, INPUT); // Sets the echoPin as an Input

    pinMode(rightSensorPins.trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(rightSensorPins.echoPin, INPUT); // Sets the echoPin as an Input

    pinMode(leftSensorPins.trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(leftSensorPins.echoPin, INPUT); // Sets the echoPin as an Input

    pinMode(leftMotor.forwardPin, OUTPUT);
    pinMode(leftMotor.backwardPin, OUTPUT);
    pinMode(rightMotor.forwardPin, OUTPUT);
    pinMode(rightMotor.backwardPin, OUTPUT);
}

void Drive::stop() {
    analogWrite(leftMotor.forwardPin, 0);
    analogWrite(leftMotor.backwardPin, 0);
    analogWrite(rightMotor.forwardPin, 0);
    analogWrite(rightMotor.backwardPin, 0);
}

void Drive::driveForward(float speed) {
    int counter = 0;
    analogWrite(leftMotor.forwardPin, speed);
    analogWrite(rightMotor.forwardPin, speed);
    while(true) {
        float dist = Drive::getDistance(frontSensorPins);
        if (dist <= 6) {
            counter++;
            if (counter >= 5) {
                Drive::stop();
                break;
            }
        } 
    }
}

void Drive::turnRight(float speed) {
    analogWrite(leftMotor.forwardPin, speed);
    analogWrite(rightMotor.forwardPin, 0);
    delay(5000);
    analogWrite(leftMotor.forwardPin, 0);
}

void Drive::turnLeft(float speed) {
    analogWrite(rightMotor.forwardPin, speed);
    analogWrite(leftMotor.forwardPin, 0);
    delay(5000);
    analogWrite(rightMotor.forwardPin, 0);

}

float Drive::getDistance(SensorPins sensorLocation) {
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
