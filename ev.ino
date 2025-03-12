// Define motor control pins
#define LEFT_MOTOR_IN1 10
#define LEFT_MOTOR_IN2 11
#define LEFT_MOTOR_ENABLE 12

#define LEFT_MOTOR_A 2
#define LEFT_MOTOR_B 3

#define RIGHT_MOTOR_IN1 5
#define RIGHT_MOTOR_IN2 6
#define RIGHT_MOTOR_ENABLE 7

#define RIGHT_MOTOR_A 8
#define RIGHT_MOTOR_B 9

#define BUTTON_PIN 13

volatile long pulseCount = 0;

#define PULSES_PER_REV 600
#define WHEEL_DIAMETER_INCHES 1.0
#define DISTANCE_TARGET_INCHES 10.0  // Desired travel distance
#define MOTOR_SPEED 250  // PWM value

bool motorRunning = false;

void countPulses() {
  pulseCount++;
}

float getDistanceTraveled() {
  float wheelCircumference = WHEEL_DIAMETER_INCHES * 3.14159;
  return (pulseCount / (float)PULSES_PER_REV) * wheelCircumference;
}

void stopMotors() {
  digitalWrite(LEFT_MOTOR_ENABLE, LOW);
  digitalWrite(RIGHT_MOTOR_ENABLE, LOW);
  digitalWrite(LEFT_MOTOR_IN1, LOW);
  digitalWrite(LEFT_MOTOR_IN2, LOW);
  digitalWrite(RIGHT_MOTOR_IN1, LOW);
  digitalWrite(RIGHT_MOTOR_IN2, LOW);
}

void setup() {
  pinMode(LEFT_MOTOR_IN1, OUTPUT);
  pinMode(LEFT_MOTOR_IN2, OUTPUT);
  pinMode(LEFT_MOTOR_ENABLE, OUTPUT);

  pinMode(RIGHT_MOTOR_IN1, OUTPUT);
  pinMode(RIGHT_MOTOR_IN2, OUTPUT);
  pinMode(RIGHT_MOTOR_ENABLE, OUTPUT);

  pinMode(LEFT_MOTOR_A, INPUT_PULLUP);
  pinMode(LEFT_MOTOR_B, INPUT_PULLUP);

  pinMode(RIGHT_MOTOR_A, INPUT_PULLUP);
  pinMode(RIGHT_MOTOR_B, INPUT_PULLUP);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(LEFT_MOTOR_A), countPulses, RISING);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW && !motorRunning) {
    delay(200); // Debounce
    pulseCount = 0; // Reset distance
    motorRunning = true;

    // Start motors forward
    digitalWrite(LEFT_MOTOR_IN1, HIGH);
    digitalWrite(LEFT_MOTOR_IN2, LOW);
    digitalWrite(RIGHT_MOTOR_IN1, HIGH);
    digitalWrite(RIGHT_MOTOR_IN2, LOW);
    analogWrite(LEFT_MOTOR_ENABLE, MOTOR_SPEED);
    analogWrite(RIGHT_MOTOR_ENABLE, MOTOR_SPEED);
  }

  if (motorRunning) {
    float distance = getDistanceTraveled();
    Serial.print("Distance Traveled: ");
    Serial.print(distance);
    Serial.println(" inches");

    if (distance >= DISTANCE_TARGET_INCHES) {
      stopMotors();
      motorRunning = false;
      Serial.println("Target distance reached. Motors stopped.");
    }
  }
}
