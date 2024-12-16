#include <Arduino.h>

const int forwardBackLeftPin = 9;
const int backwardBackLeftPin = 8;
const int forwardBackRightPin = 12; 
const int backwardBackRightPin = 13; 

const int trigPin = 7;
const int echoPin = 6;


const int delayTime = 2000;

void setup() {
  // put your setup code here, to run once:
  pinMode(forwardBackLeftPin,OUTPUT); // Set backleft motor FORWARD pin
  pinMode(backwardBackLeftPin,OUTPUT); // Set backleft motor BACKWARD pin
  pinMode(forwardBackRightPin,OUTPUT); // Set backright motor FORWARD pin
  pinMode(backwardBackRightPin,OUTPUT); // Set backright motor BACKWARD pin
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(forwardBackLeftPin,LOW);
  digitalWrite(backwardBackLeftPin,LOW);
  digitalWrite(forwardBackRightPin,LOW);
  digitalWrite(backwardBackRightPin,LOW);
  delay(delayTime);

  digitalWrite(forwardBackLeftPin,HIGH);
  digitalWrite(backwardBackLeftPin,LOW);
  digitalWrite(forwardBackRightPin,HIGH);
  digitalWrite(backwardBackRightPin,LOW);
  delay(delayTime);

  digitalWrite(forwardBackLeftPin,LOW);
  digitalWrite(backwardBackLeftPin,LOW);
  digitalWrite(forwardBackRightPin,LOW);
  digitalWrite(backwardBackRightPin,LOW);
  delay(delayTime);

  digitalWrite(forwardBackLeftPin,LOW);
  digitalWrite(backwardBackLeftPin,HIGH);
  digitalWrite(forwardBackRightPin,LOW);
  digitalWrite(backwardBackRightPin,HIGH);
  delay(delayTime);

}

// put function definitions here:

