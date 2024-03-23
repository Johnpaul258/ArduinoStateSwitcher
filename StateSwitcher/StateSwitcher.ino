#define redLED 2
#define greenLED 3
#define yellowLED 4
#define trigPin 9
#define echoPin 10
#define pirPin 12
#define relayPin 13
#define buttonPin 5
#define ledPin 7

#include <DHT11.h>

DHT11 dht11(8);  // Assuming the DHT sensor is connected to pin 8

int currentState = 0;
bool motionDetected = false;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Using internal pull-up resistor for the button
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    currentState++;
    if (currentState > 3) {
      currentState = 1;
    }
    delay(100);  // Debouncing delay
  }

  switch (currentState) {
    case 1:
      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);
      displayTemperatureAndHumidity();
      break;
    case 2:
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);
      digitalWrite(yellowLED, LOW);
      checkUltrasonicSensor();
      break;
    case 3:
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, HIGH);
      checkMotionSensor();
      break;
  }

  // Check if the button is pressed
  if (digitalRead(buttonPin) == HIGH) {
    // Turn on LED on pin 7 for 500ms
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
  }
}

void displayTemperatureAndHumidity() {


  int humidity = dht11.readHumidity();
  delay(500);
  int temperature = dht11.readTemperature();
  delay(500);

  Serial.print("Current humidity = ");
  Serial.print(humidity);
  Serial.print(" %, Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
}

void checkUltrasonicSensor() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.0343) / 2;

  if (distance < 4) {
    displayTemperatureAndHumidity();
  }
}

void checkMotionSensor() {


  if (digitalRead(pirPin) == HIGH) {
    motionDetected = true;
  }

  if (motionDetected) {
    digitalWrite(relayPin, HIGH);
    delay(5000);  // Relay on for 5 seconds
    digitalWrite(relayPin, LOW);
    motionDetected = false;  // Reset motion detection flag
  }
}
