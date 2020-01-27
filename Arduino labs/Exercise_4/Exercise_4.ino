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


int greenled1 = 13;
int redled1 = 12;
int greenled2 = 11;
int redled2 = 10;
int switchState1;
int switchState2;
const int switchPin1 = 8;
const int switchPin2 = 7;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(greenled1, OUTPUT);
  pinMode(redled1, OUTPUT);
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(redled2, HIGH);
  digitalWrite(greenled2, HIGH); 
  digitalWrite(greenled1, HIGH);
  digitalWrite(redled1, HIGH); 
/*
  switchState1 = digitalRead(switchPin1);
  switchState2 = digitalRead(switchPin2);
  if (switchState1)
  {
    if (switchState2)
    {
       digitalWrite(redled2, HIGH);   // turn the LED on (HIGH is the voltage level)
       digitalWrite(redled1, LOW); 
       digitalWrite(greenled1, LOW); 
       digitalWrite(greenled2, LOW); 
    }
    else
    {
       digitalWrite(redled2, LOW);  
       digitalWrite(redled1, LOW); 
       digitalWrite(greenled1, HIGH); 
       digitalWrite(greenled2, LOW); 
    }
   }
   else
   {
     if (switchState2)
    {
       digitalWrite(redled2, LOW);   
       digitalWrite(redled1, LOW); 
       digitalWrite(greenled1, LOW); 
       digitalWrite(greenled2, HIGH); 
    }
    else
    {
       digitalWrite(redled2, LOW);  
       digitalWrite(redled1, HIGH); 
       digitalWrite(greenled1, LOW); 
       digitalWrite(greenled2, LOW);
    }
   }
*/
}
