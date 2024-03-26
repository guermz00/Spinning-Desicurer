int ledPin = 5; // PWM pin connected to the PWM input of LD24AJTA

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Turn on the LED to full brightness
  analogWrite(ledPin, 255);
  delay(1000); // Wait for 1 second

  // Gradually dim the LED to off
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness);
    delay(10); // Wait for 10ms between brightness changes for a smooth transition
  }

  // Wait for 1 second before repeating the loop
  delay(1000);
}
