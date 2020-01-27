  //TIDI: WEARABLE MIDI CONTROLLER FOR DJ APPLICATIONS
  //
  //ARDUINO SOURCE CODE
  //BY JACK ELLIOTT
  //
  //April 2016

  //Analogue in pin values
  const int leftPlayPin = 0;
  const int leftFilterPin = 1;
  const int leftFxPin = 2;
  const int leftFxWetPin = 3;

  const int rightPlayPin = 4;
  const int rightFilterPin = 5;
  const int rightFxPin = 6;
  const int rightFxWetPin = 7;
  
  //Analogue Read values
  int leftPlayPinVal;
  int leftFilterPinVal;
  int leftFxPinVal;
  int leftFxWetPinVal;

  int rightPlayPinVal;
  int rightFilterPinVal;
  int rightFxPinVal;
  int rightFxWetPinVal;

  //MIDI Map Values
  int leftFilterMidiVal;
  int leftFxMidiVal;

  int rightFilterMidiVal;
  int rightFxMidiVal;

  //Value Memory Buffers
  int leftFilterBuffer = 0;
  int leftFxWetBuffer = 0;

  int rightFilterBuffer = 0;
  int rightFxWetBuffer = 0;

void setup() {
  Serial.begin(31250);
  //Serial.begin(9600); //(Un-comment this line to view
  //serial write messages in the serial monitor.
}

void loop() {
  //READ INPUTS
  //LEFT CIRCUIT
  leftPlayPinVal = analogRead(leftPlayPin);
  leftFilterPinVal = analogRead(leftFilterPin);
  leftFxPinVal = analogRead(leftFxPin);
  leftFxWetPinVal = analogRead(leftFxWetPin);
  
  
  //RIGHT CIRCUIT
  rightPlayPinVal = analogRead(rightPlayPin);
  rightFilterPinVal = analogRead(rightFilterPin);
  rightFxPinVal = analogRead(rightFxPin);
  rightFxWetPinVal = analogRead(rightFxWetPin);
  
  //LEFT CONTROLLER MESSAGES
  
  //                PLAY/PAUSE
  if (leftPlayPinVal == 1023){
    Serial.write(0x9D); // Note On (14) + Channel  
    Serial.write(69); // Pitch
    Serial.write(64); // Velocity

    //Delay is used to stop double presses.
    delay(500); //Increase if 'double presses' occur too often from slow button release.
  }
  
  //              FILTER
  // Uses control change message rather than note on/off
    leftFilterMidiVal = map(leftFilterPinVal, 0, 1024, 0, 127);

    if (leftFilterMidiVal != leftFilterBuffer){ //If new value is different, 
                                                //transmit new value in MIDI message. 
      Serial.write(0xB0); // Control Message  
      Serial.write(16); // Controller Number
      Serial.write(leftFilterMidiVal); // Value

      leftFilterBuffer = leftFilterMidiVal; //Update buffer value.
      
      delay(100); //Short Delay to reduce MIDI traffic.
    }


  //                FX1 ON
  if (leftFxPinVal == 1023){
   // Serial.println("Left Play is on");
    Serial.write(0x9D); // Note On (14) + Channel  
    Serial.write(70); // Pitch
    Serial.write(64); // Velocity

    //Delay is used to alleviate issue of button press time causing the deck to immediately pause again
    delay(500);
  }

  //              FX 1 WET/DRY
  // Uses control change message rather than note on/off
    leftFxMidiVal = map(leftFxWetPinVal, 0, 1024, 0, 127);

    if (leftFxMidiVal != leftFxWetBuffer){
    Serial.write(0xB0); // Note On (14) + Channel  
    Serial.write(17); // Controller Number
    Serial.write(leftFxMidiVal); // Velocity

    leftFxWetBuffer = leftFxMidiVal;
    delay(100);
    }  
   
  //          RIGHT CONTROLLER
  //
  
  //                PLAY/PAUSE
  if (rightPlayPinVal == 1023){
    //Serial.println("Right Play is on");
    Serial.write(0x9D); // Note On (14) + Channel  
    Serial.write(71); // Pitch
    Serial.write(64); // Velocity

    //Delay is used to alleviate issue of button press time causing the deck to immediately pause again
    delay(500);
  }
  
  //              FILTER
  // Uses control change message rather than note on/off
    rightFilterMidiVal = map(rightFilterPinVal, 0, 1024, 0, 127);

    if (rightFilterMidiVal != rightFilterBuffer){
      Serial.write(0xB0); // Note On (14) + Channel  
      Serial.write(18); // Controller Number
      Serial.write(rightFilterMidiVal); // Velocity

      rightFilterBuffer = rightFilterMidiVal;
      
      delay(100);
    }

  //                FX1 ON
  if (rightFxPinVal == 1023){
    Serial.write(0x9D); // Note On (14) + Channel  
    Serial.write(72); // Pitch
    Serial.write(64); // Velocity

    //Delay is used to alleviate issue of button press time causing the deck to immediately pause again
    delay(500);
  }

  //              FX 1 WET/DRY
  // Uses control change message rather than note on/off
    rightFxMidiVal = map(rightFxWetPinVal, 0, 1024, 0, 127);

    if (rightFxMidiVal != rightFxWetBuffer){
    Serial.write(0xB0); // Note On (14) + Channel  
    Serial.write(19); // Controller Number
    Serial.write(rightFxMidiVal); // Velocity

    rightFxWetBuffer = rightFxMidiVal;
    delay(100);
    }
    
}
