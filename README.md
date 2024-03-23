# ArduinoStateSwitcher
Press a button to select one of three states with a push button.

- State 1: When the button is pressed, the temperature and humidity readings from the DHT sensor should be shown concurrently along with the red LED glowing.
- State 2: The green LED ought to light if you press the button once more. In this condition, the temperature and humidity are shown if an item is four inches or less from the ultrasonic sensor.
- State 3: The yellow LED ought to light up if you press the button once more. Replay need to start in this state if the motion sensor detects movement.

Pressing the button once again ought to bring about state 1.

**Requirements:**
- Arduino UNO
- Arduino IDE
- Red LED
- Green LED
- Yellow LED
- Resistors
- Ultrasonic sensor
- Motion sensor
- DHT sensor
- Relay
- Push button
- Jumper wires


**Connections and Definitions:**
- VCC = 5V
- Red LED -> PIN 2
- Green LED -> PIN 3
- Yellow LED -> PIN 4
- Push button -> PIN 5
- Relay -> PIN 13
- Ultrasonic sensor trigger -> PIN 9
- Ultrasonic sensor trigger -> PIN 10
- Motion sensor -> PIN 12

**Notes:**
- I am using another LED (blue) to turn on for 500ms when the button is pressed, to verify (visually) that it has been pressed
