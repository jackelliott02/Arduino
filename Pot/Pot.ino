const int potPin = A0;
int i;
int potValue;
int delayTime;

void setup()
{
  Serial.begin(31250);
}





void loop()
{
  potValue = analogRead(potPin);
  delayTime=map(potValue,0,1023,50,1000);
  for(i=0; i<12; i++)
  {
    Serial.write(0x93); // TX0 Note On + Channel
    Serial.write(58+i); // TX0 Note Value 
    Serial.write(127); // TX0 Velocity
    
    delay(delayTime);
    
    Serial.write(0x83); // TX0 Note Off + Channel
    Serial.write(58+i); // TX0 Note Value 
    Serial.write(0x00); // TX0 Velocity
    
    delay(500);
  }
}
