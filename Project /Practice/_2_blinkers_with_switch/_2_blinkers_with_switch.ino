/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */



  int delayTime;
  const int potPin = 0;
  const int switchPin = 11;

  int potValue;
  int switchState;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  Serial.begin(9600);
  const int potPin = 0;
  int potValue;
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  potValue = analogRead(potPin);
  delayTime = map(potValue, 0, 1023, 200, 700);
  switchState = digitalRead(8);

  if (switchState == 1) {
    
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(delayTime);
  
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(delayTime); 

    }
  else {
  digitalWrite(12, LOW);   
  digitalWrite(13, LOW);
  }
  
  Serial.println(potValue);
  Serial.println(delayTime);// wait for a second
  Serial.println(switchState);
  Serial.println();
}
