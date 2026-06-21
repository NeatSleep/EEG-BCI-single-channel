void setup() {
  Serial.begin(115200);   // Start serial communication
  delay(1000);            // Give time for Serial Monitor to open
}

void loop() {
  int val = analogRead(34);  // Read analog value from GPIO 34 (0–4095)
  Serial.println(val);       // Print value to Serial Monitor
  delay(10);    // for easier debugging
}
