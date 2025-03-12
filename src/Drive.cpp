#include <Drive.h>

// Constructor: Initializes the Drive object with sensor and motor pin configurations
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

// Sets pin modes for all sensors and motors
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
    pinMode(leftMotor.pwmPin, OUTPUT);

    pinMode(rightMotor.forwardPin, OUTPUT);
    pinMode(rightMotor.backwardPin, OUTPUT);
    pinMode(rightMotor.pwmPin, OUTPUT);
}

// Stops both motors immediately by writing zero PWM to all control pins
void Drive::stop() {
    analogWrite(leftMotor.forwardPin, 0);
    analogWrite(leftMotor.backwardPin, 0);
    analogWrite(leftMotor.pwmPin, 0);

    analogWrite(rightMotor.forwardPin, 0);
    analogWrite(rightMotor.backwardPin, 0);
    analogWrite(rightMotor.pwmPin, 0);
}

// Drives the robot forward at a given speed until an obstacle is within 6 cm distance
void Drive::driveForward(float speed) {
    int counter = 0;
    analogWrite(leftMotor.forwardPin, speed);
    analogWrite(rightMotor.forwardPin, speed);
    Serial.print("Driving forward");
    // Continuously check front sensor distance
    while(true) {
        float dist = Drive::getDistance(frontSensorPins);
        Serial.print(dist);
        if (dist <= 6) {
            counter++;
            if (counter >= 5) {
                Drive::stop();
                break;
            }
        } 
    }
}

// Turns the robot right by running only the left motor forward for a set time
void Drive::turnRight(float speed) {
    analogWrite(leftMotor.forwardPin, speed);
    analogWrite(rightMotor.forwardPin, 0);
    delay(5000);
    analogWrite(leftMotor.forwardPin, 0);
}

// Turns the robot left by running only the right motor forward for a set time
void Drive::turnLeft(float speed) {
    analogWrite(rightMotor.forwardPin, speed);
    analogWrite(leftMotor.forwardPin, 0);
    delay(5000);
    analogWrite(rightMotor.forwardPin, 0);

}

// Measures and returns the distance from a specific ultrasonic sensor
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
