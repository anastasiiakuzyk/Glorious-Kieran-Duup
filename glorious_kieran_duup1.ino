// Pin Definitions
const int RELAY_PIN = 13;        // Pin for the relay
const int PIR_SENSOR_PIN = 2;    // Pin for the PIR sensor
const int LDR_SENSOR_PIN = A0;   // Pin for the LDR sensor

// Threshold Values
const int LDR_THRESHOLD = 600;  // Threshold for the LDR sensor

// Timing Values
const int RELAY_ON_TIME = 5000; // Time that the relay is on when motion is detected
const int RELAY_OFF_TIME = 300; // Time that the relay is off when no motion is detected

void setup(){
  // Set pin modes
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(PIR_SENSOR_PIN, INPUT);
  pinMode(LDR_SENSOR_PIN, INPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop(){
  // Read sensor values
  int pirSensorValue = digitalRead(PIR_SENSOR_PIN);
  int ldrSensorValue = analogRead(LDR_SENSOR_PIN);

  // Check if the LDR sensor value is below the threshold
  if(ldrSensorValue < LDR_THRESHOLD) {
    // Check if motion is detected
    if(pirSensorValue == HIGH) {
      // Turn on the relay
      digitalWrite(RELAY_PIN, HIGH);
      Serial.println("Motion detected, turning on relay");
      delay(RELAY_ON_TIME);
    } else {
      // Turn off the relay
      digitalWrite(RELAY_PIN, LOW);
      Serial.println("No motion detected, turning off relay");
      delay(RELAY_OFF_TIME);
    }
  } else {
    // Turn off the relay and print the LDR sensor value for debugging
    digitalWrite(RELAY_PIN, LOW);
    Serial.print("LDR sensor value: ");
    Serial.println(ldrSensorValue);
    delay(500);
  }
}
