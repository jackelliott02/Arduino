int lightPin = 0;  // Analog pin 
int lightLevel, maxLevel, minLevel;
int adjustedLightLevel; // mapped photo resistor value

void setup()
{
    Serial.begin(31250); // MIDI
}

void loop()
{
   maxLevel=analogRead(lightPin);
   minLevel=300;
   while(1)
  { 
    lightLevel=analogRead(lightPin); // Read the value of the photoresistor
    adjustedLightLevel = map(lightLevel, minLevel, maxLevel, 0, 127);
    
    Serial.write(0x93); // TX0 Note On + Channel
    Serial.write(adjustedLightLevel); // TX0 Note Value 
    Serial.write(127); // TX0 Velocity
    
    delay(200); //short delay for faster response to light.
  }
}
