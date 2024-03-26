// Define motor control pins
int enablePin = 9;    // PWM pin to control the motor speed
int motorPin1 = 2;    // Motor control pin 1
int motorPin2 = 3;    // Motor control pin 2

// Define LED control pin
int ledPin = 5;       // PWM pin to control the LED

// Define button pins
int buttonMotorPin = 7;    // Button to control motor
int buttonLedPin = 8;      // Button to control LED

// Variables to hold the state of the buttons
int buttonMotorState = 0;
int buttonLedState = 0;

// Variables to hold the motor and LED status
bool motorOn = false;
bool ledOn = false;

void setup() {
  // Set motor control pins as outputs
  pinMode(enablePin, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  // Set LED control pin as output
  pinMode(ledPin, OUTPUT);

  // Set button pins as inputs
  pinMode(buttonMotorPin, INPUT_PULLUP);
  pinMode(buttonLedPin, INPUT_PULLUP);
}

void loop() {
  // Read the state of the buttons
  buttonMotorState = digitalRead(buttonMotorPin);
  buttonLedState = digitalRead(buttonLedPin);

  // If the motor button is pressed, toggle the motor state
  if (buttonMotorState == LOW) {
    motorOn = !motorOn;
    delay(200); // Debounce delay
    while (digitalRead(buttonMotorPin) == LOW); // Wait for button release
  }

  // Control the motor based on motor state
  if (motorOn) {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    analogWrite(enablePin, 255); // Full speed
  } else {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    analogWrite(enablePin, 0); // Motor off
  }

  // If the LED button is pressed, toggle the LED state
  if (buttonLedState == LOW) {
    ledOn = !ledOn;
    delay(200); // Debounce delay
    while (digitalRead(buttonLedPin) == LOW); // Wait for button release
  }

  // Control the LED based on LED state
  if (ledOn) {
    analogWrite(ledPin, 255); // Full brightness
  } else {
    analogWrite(ledPin, 0); // LED off
  }
}
