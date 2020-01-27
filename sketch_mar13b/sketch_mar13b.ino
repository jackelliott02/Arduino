int i;

void setup()
{
  Serial.begin(31250);
}

void loop()
{
  for(i=0; i<12; i++)
  {
    Serial.write(0x93); // TX0 Note On + Channel
    Serial.write(58+i); // TX0 Note Value 
    Serial.write(127); // TX0 Velocity
    
    delay(500);
    
    Serial.write(0x83); // TX0 Note Off + Channel
    Serial.write(58+i); // TX0 Note Value 
    Serial.write(0x00); // TX0 Velocity
    
    delay(500);
  }
}
