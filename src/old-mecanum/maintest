#include <Arduino.h>
const int frontLeftPos = 4;
const int frontLeftNeg=5;
const int frontRightPos=2;
const int frontRightNeg=3;
const int rearLeftPos=8;
const int rearLeftNeg=9;
const int rearRightPos=7;
const int rearRightNeg=6;

const int buttonPin = 31;
int buttonState = 0;
const int delayTime = 2000;

void setup() {
  // put your setup code here, to run once:
  pinMode(frontLeftPos,OUTPUT); 
  pinMode(frontLeftNeg,OUTPUT); 
  pinMode(frontRightPos,OUTPUT); 
  pinMode(frontRightNeg,OUTPUT);
  pinMode(rearRightPos,OUTPUT); 
  pinMode(rearRightNeg,OUTPUT);
  pinMode(rearLeftPos,OUTPUT); 
  pinMode(rearLeftNeg,OUTPUT);
  pinMode(buttonPin,INPUT);
  Serial.begin(9600); // Starts the serial communication

  /*while (buttonState==LOW) {
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
      Serial.print("Button pressed");
      break;
    }
    //Serial.print(digitalRead(buttonPin));
  }*/
}

void loop() {
  digitalWrite(frontLeftPos,HIGH); 
  digitalWrite(frontRightPos,HIGH); 
  digitalWrite(rearRightPos,HIGH); 
  digitalWrite(rearLeftPos,HIGH); 
}
