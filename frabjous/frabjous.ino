#include <SPI.h>
#include <Wire.h>
#include <Centipede.h>
#include <DmxMaster.h>
#include <SoftwareSerial.h>

// Set software serial pins
#define rxPin 8
#define txPin 9
SoftwareSerial mySerial(rxPin,txPin); // RX, TX

// create Centipede object
Centipede CS; 

const int sensor0 = 0;
int sensorState0 = 0;

/** ****************************************************
********************************************************
*******************************************************/

//  Initialization
void setup(void){
  
  // Touch Sensor
  Wire.begin(); // start I2C
  CS.initialize(); // set all registers to default
  CS.pinMode(sensor0, INPUT);
  CS.pinPullup(sensor0, HIGH);  
  
  /* The most common pin for DMX output is pin 3, which DmxMaster
** uses by default. If you need to change that, do it here. */
  DmxMaster.usePin(3);

  /* DMX devices typically need to receive a complete set of channels
** even if you only need to adjust the first channel. You can
** easily change the number of channels sent here. If you don't
** do this, DmxMaster will set the maximum channel number to the
** highest channel you DmxMaster.write() to. */
  DmxMaster.maxChannel(60);
  
  // Begin serial ports
  Serial.begin(9600);
  
  /*  set the data rate for the SoftwareSerial port  */
  mySerial.begin(31250);

}

/** ****************************************************
********************************************************
*******************************************************/

void loop(void){
  // readTouchInputs();
  touchSensors();
}

void touchSensors(){
  
  sensorState0 = CS.digitalRead(sensor0);
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (sensorState0 == HIGH) {     
    
    Serial.println(sensorState0);
    
  } 
  
}


void set_register(int address, unsigned char r, unsigned char v){
    Wire.beginTransmission(address);
    Wire.write(r);
    Wire.write(v);
    Wire.endTransmission();
}

//  plays a MIDI note.  Doesn't check to see that
//  cmd is greater than 127, or that data values are  less than 127:
//  Uses softSerial on pins 10 and 11
void midiSend(int cmd, int pitch, int velocity) {
  mySerial.write(cmd);
  mySerial.write(pitch);
  mySerial.write(velocity);
}
