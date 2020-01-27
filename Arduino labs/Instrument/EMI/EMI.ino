// Lab3Ex1_2
// nunchuckWireRead
// Read and print data from I2C connected nunchuck
// DMH Feb 2015
#include <Wire.h>
#define kNunDev 0x52
int count = 0;
uint8_t outbuf[6];  // array to store nunchuck data
int joy_x_axis, joy_y_axis;
int accel_x_axis, accel_y_axis, accel_z_axis;
int z_button, c_button;
int joy_x_axis_Mapped, joy_y_axis_Mapped; 
int accel_x_axis_Mapped, accel_y_axis_Mapped; 
int z_button_Mapped, c_button_Mapped;
const int potPin = A7;
int potValue;
int potValueMapped;
int lightPin = A0; // Anolog Pin 0
int lightLevel;
int maxLightLevel;
void setup() {
  Serial.begin(31250); // MIDI
  
  // Connect nunchuck
  Wire.begin();    // Join I2C bus
  nunchuck_init(); // initialise nunchuck
  maxLightLevel=analogRead(lightPin); // read light level in the room
}
void nunchuck_init () {
  Wire.beginTransmission (kNunDev); // transmit to device
  Wire.write (0x40);		    // send memory address
  Wire.write (0x00);		    // send a zero.  
  Wire.endTransmission ();	    // stop transmitting
}
void sendZero () {
  Wire.beginTransmission (kNunDev); // transmit to device 0x52
  Wire.write (0x00);		    // sends one byte
  Wire.endTransmission ();	    // stop transmitting
}
// Believed to be Nintendo's attempt to be 'obscure'.
// A data byte must be XOR'd with 0x17, and then have 0x17 added.
char nunchuck_decode_byte (char x) {
  x = (x ^ 0x17) + 0x17;
  return x;
}
void organiseData() {
  joy_x_axis = outbuf[0];
  joy_y_axis = outbuf[1];
  // accelerometer is 10-bit data so shift by 2 bits (*4)
  accel_x_axis = outbuf[2] * 4; 
  accel_y_axis = outbuf[3] * 4;
  accel_z_axis = outbuf[4] * 4;
  z_button = 1;
  c_button = 1;
 // byte outbuf[5] contains bits for z and c buttons
 // it also contains the least significant bits for the accelerometer data
 // so we have to check each bit of byte outbuf[5]
  if ((outbuf[5] >> 0) & 1)
      c_button = 0;
  if ((outbuf[5] >> 1) & 1)
      z_button = 0;
  if ((outbuf[5] >> 2) & 1)
      accel_x_axis += 2;
  if ((outbuf[5] >> 3) & 1)
      accel_x_axis += 1;
  if ((outbuf[5] >> 4) & 1)
      accel_y_axis += 2;
  if ((outbuf[5] >> 5) & 1)
      accel_y_axis += 1;
  if ((outbuf[5] >> 6) & 1)
      accel_z_axis += 2;
  if ((outbuf[5] >> 7) & 1)
      accel_z_axis += 1;
}
void mapDataToMIDI(){
 joy_x_axis_Mapped=map(joy_x_axis,37,228,0,127);
 joy_y_axis_Mapped=map(joy_y_axis,34,221,0,127);
 accel_x_axis_Mapped=map(accel_x_axis,335,742,0,127);
 accel_y_axis_Mapped=map(accel_y_axis,300,725,0,127);
 z_button_Mapped=map(z_button,0,1,0,127);
 c_button_Mapped=map(c_button,0,1,0,127);
}
void nunchuck_print_data() {
  Serial.write(0x90); 
  Serial.write(joy_x_axis_Mapped); // TX0 Note Value 
  Serial.write(127); // TX0 Velocity
  
  Serial.write (0x91); 
  Serial.write(joy_y_axis_Mapped); // TX0 Note Value 
  Serial.write(127); // TX0 Velocity
  
  Serial.write (0x92); 
  Serial.write(accel_x_axis_Mapped); // TX0 Note Value 
  Serial.write(127); // TX0 Velocity
  
  Serial.write (0x93); 
  Serial.write(accel_y_axis_Mapped); // TX0 Note Value 
  Serial.write(127); // TX0 Velocity
  
  Serial.write (0x94); 
  Serial.write(z_button_Mapped); // TX0 Note Value 
  Serial.write(127); // TX0 Velocity
  
  Serial.write (0x95); 
  Serial.write(c_button_Mapped); // TX0 Note Value 
  Serial.write(127); // TX0 Velocity
  
  // POT
  Serial.write(0xB6); // Control Message, channel
  Serial.write(0x07); // Main Volume 
  Serial.write(potValueMapped); // Value
}
void readAndMapPot(){
  potValue = analogRead(potPin);
  potValueMapped=map(potValue,0,1023,127,0);
}
void loop() {
  Wire.requestFrom (kNunDev, 6);	// request data from nunchuck
  while (Wire.available ()) {
    outbuf[count] = nunchuck_decode_byte (Wire.read ()); // get byte
    count++;
  }
  // Check we have recieved 6 bytes, if so, process them
  if (count >= 5)
      organiseData ();
      
  // Map data to MIDI
  mapDataToMIDI();  
  
  // Read and map potentiometer data 
  readAndMapPot();
  
  // Print data
  nunchuck_print_data();
  count = 0;
  sendZero (); // send the request for next bytes
  delay (100); 
}
