// Define motor control pins
int enablePin = 9;    // PWM pin to control the motor speed
int motorPin1 = 2;    // Motor control pin 1
int motorPin2 = 3;    // Motor control pin 2

void setup() {
  // Set motor control pins as outputs
  pinMode(enablePin, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void loop() {
  // Rotate motor in one direction
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  analogWrite(enablePin, 255); // Full speed
  delay(50000); // Run for 5 seconds


}
