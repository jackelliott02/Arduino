
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

  //Other Pin Values
  int pin8val;
  int pin9val;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
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

  //Other Pins
  pin8val = analogRead(8);
  pin9val = analogRead(9);
  
delay(1000);

//Serial.println("hi");
//Serial.println("left play pin val");
//Serial.println(leftPlayPinVal);

Serial.println("RIGHT play pin val");
Serial.println(rightPlayPinVal);

Serial.println("RIGHT filter pin val");
Serial.println(rightFilterPinVal);

Serial.println("right fx pin val");
Serial.println(rightFxPinVal);

Serial.println("right fx wet val");
Serial.println(rightFxWetPinVal);

Serial.println("pin 8 val");
Serial.println(pin8val);

Serial.println("pin 9 val");
Serial.println(pin9val);



Serial.println("-------------");
Serial.println("-------------");



  
  // put your main code here, to run repeatedly:

}
