/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */


int greenled = 13;
int redled = 12;
const int potPin = A0;
int potValue;
int delayTime;
int switchState;
const int switchPin = 8;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(greenled, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(switchPin, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  potValue = analogRead(potPin);
  //delayTime = map(potValue, 0, 1023, 25, 750);
  delayTime = 250;
  switchState = digitalRead(switchPin);
  
  digitalWrite(greenled, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(redled, LOW); 
  
  while (switchState)
  {
    digitalWrite(greenled, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(redled, LOW); 
    delay(delayTime);     // wait for a second
    digitalWrite(greenled, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(redled, HIGH); 
    delay(delayTime);    // wait for a second
    switchState = digitalRead(switchPin);
  }  
}
