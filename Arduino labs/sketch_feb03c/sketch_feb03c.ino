void setup() {
Serial.begin(31250);
}

void loop() {

  Serial.write(0x9D); // Note On (14) + Channel  
  Serial.write(69); // Pitch
  Serial.write(64); // Velocity
  delay(1000);

  Serial.write(0x9C); // Note On (13) + Channel  
  Serial.write(69); // Pitch
  Serial.write(64); // Velocity
  delay(1000);
}
