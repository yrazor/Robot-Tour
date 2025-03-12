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

bool motorRunning = false; // Motor state
volatile long pulseCount = 0;  // Count encoder pulses
#define PULSES_PER_REV 600  // Number of pulses per wheel revolution
#define WHEEL_DIAMETER_INCHES 1.0  // Wheel diameter in inches

void  countPulses() {
    pulseCount++;
}
void distanceCalculate() {
    // Calculate distance traveled
    float wheelCircumference = WHEEL_DIAMETER_INCHES * 3.14159;  // π * diameter
    float distanceTraveled = (pulseCount / (float)PULSES_PER_REV) * wheelCircumference;
    Serial.print("Distance Traveled: ");
    Serial.print(distanceTraveled);
    Serial.println(" inches");

    delay(500);  // Update every 500ms
}

void setup() {
    pinMode(LEFT_MOTOR_IN1, OUTPUT);
    pinMode(LEFT_MOTOR_IN2, OUTPUT);
    pinMode(LEFT_MOTOR_ENABLE, OUTPUT);

    pinMode(LEFT_MOTOR_A, INPUT_PULLUP);
    pinMode(LEFT_MOTOR_B, INPUT_PULLUP);

    pinMode(RIGHT_MOTOR_IN1, OUTPUT);
    pinMode(RIGHT_MOTOR_IN2, OUTPUT);
    pinMode(RIGHT_MOTOR_ENABLE, OUTPUT);

    pinMode(RIGHT_MOTOR_A, INPUT_PULLUP);
    pinMode(RIGHT_MOTOR_B, INPUT_PULLUP);

    pinMode(BUTTON_PIN, INPUT_PULLUP); // Use internal pull-up resistor

    attachInterrupt(digitalPinToInterrupt(LEFT_MOTOR_A), countPulses, RISING);
    Serial.begin(9600);
}



void loop() {
    if (digitalRead(BUTTON_PIN) == LOW) { // Button pressed
        delay(200); 
        Serial.print("Started");
        digitalWrite(LEFT_MOTOR_IN1, HIGH);
        digitalWrite(LEFT_MOTOR_IN2, LOW);
        digitalWrite(RIGHT_MOTOR_IN1, HIGH);
        digitalWrite(RIGHT_MOTOR_IN2, LOW);
        analogWrite(LEFT_MOTOR_ENABLE, 250); 
        analogWrite(RIGHT_MOTOR_ENABLE, 250); 
        while (digitalRead(BUTTON_PIN) == HIGH) {
          distanceCalculate();
        }
    }

}
