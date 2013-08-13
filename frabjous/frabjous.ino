#include <SPI.h>
#include <Wire.h>
#include "mpr121.h"
#include <DmxMaster.h>
#include <SoftwareSerial.h>

// Set software serial pins
#define rxPin 8
#define txPin 9
SoftwareSerial mySerial(rxPin,txPin); // RX, TX

// Touch Sensor Variables
int irqpin = 2;  // Digital 2
boolean touchStates[12]; //to keep track of the previous touch states
boolean touchStatesTwo[12]; //to keep track of the previous touch states

// Define thresholds for points
#define SHORT_POINT_ON 0x09
#define SHORT_POINT_OFF 0x05

#define MED_POINT_ON 0x03
#define MED_POINT_OFF 0x01

#define LONG_POINT_ON 0x04
#define LONG_POINT_OFF 0x01

/** ****************************************************
********************************************************
*******************************************************/

//  Initialization
void setup(void){
  
  // Touch Sensor
  pinMode(irqpin, INPUT);
  digitalWrite(irqpin, HIGH); //enable pullup resistor
  
  Wire.begin();
  // mpr121_setup();
  // mpr121_setupTwo();
  
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
  //readTouchInputs();
  
  //  #1
    DmxMaster.write(32, 128);
    DmxMaster.write(33, 128);
    DmxMaster.write(34, 128);
    
  //  #2
    DmxMaster.write(35, 128);
    DmxMaster.write(36, 128);
    DmxMaster.write(37, 128);
    
  //  #3
    DmxMaster.write(38, 128);
    DmxMaster.write(39, 128);
    DmxMaster.write(40, 128);
    
  //  #4
    DmxMaster.write(41, 128);
    DmxMaster.write(42, 128);
    DmxMaster.write(43, 128);
    
  //  #5
    DmxMaster.write(44, 128);
    DmxMaster.write(45, 128);
    DmxMaster.write(46, 128);
    
  //  #6
    DmxMaster.write(47, 128);
    DmxMaster.write(48, 128);
    DmxMaster.write(49, 128);
    
  //  #7
    DmxMaster.write(50, 128);
    DmxMaster.write(51, 128);
    DmxMaster.write(52, 128);
    
  //  #8
    DmxMaster.write(53, 128);
    DmxMaster.write(54, 128);
    DmxMaster.write(55, 128);
    
  //  #9
    DmxMaster.write(56, 128);
    DmxMaster.write(57, 128);
    DmxMaster.write(58, 128);
    
  //  #10
    DmxMaster.write(64, 128);
    DmxMaster.write(65, 128);
    DmxMaster.write(66, 128);
    
  //  #11
    DmxMaster.write(67, 128);
    DmxMaster.write(68, 128);
    DmxMaster.write(69, 128);
    
  //  #12
    DmxMaster.write(70, 128);
    DmxMaster.write(71, 128);
    DmxMaster.write(72, 128);
    
  //  #13
    DmxMaster.write(73, 128);
    DmxMaster.write(74, 128);
    DmxMaster.write(75, 128);
    
  //  #14
    DmxMaster.write(76, 128);
    DmxMaster.write(77, 128);
    DmxMaster.write(78, 128);
    
  //  #15
    DmxMaster.write(79, 128);
    DmxMaster.write(80, 128);
    DmxMaster.write(81, 128);

  //  #16
    DmxMaster.write(82, 128);
    DmxMaster.write(83, 128);
    DmxMaster.write(84, 128);
    
  //  #17
    DmxMaster.write(85, 128);
    DmxMaster.write(86, 128);
    DmxMaster.write(87, 128);
    
  //  #18
    DmxMaster.write(88, 128);
    DmxMaster.write(89, 128);
    DmxMaster.write(90, 128);
    
  //  #19
    DmxMaster.write(91, 128);
    DmxMaster.write(92, 128);
    DmxMaster.write(93, 128);
    
  //  #20
    DmxMaster.write(94, 128);
    DmxMaster.write(95, 128);
    DmxMaster.write(96, 128);
}

/** ****************************************************
********************************************************
*******************************************************/

//********************  FIRST Capacitive Touch Sensor
/*
void readTouchInputs(){
  
  if(!checkInterrupt()){
    
    //read the touch state from the MPR121
    Wire.requestFrom(0x5A,3);  
    byte LSB = Wire.read();
    byte MSB = Wire.read();  
    uint16_t touched = ((MSB << 8) | LSB); //16bits that make up the touch states
  
    for (int i=0; i < 12; i++){  // Check which electrodes were pressed
    
      if(touched & (1<<i)){
      
        if(touchStates[i] == 0){
          switch (i) {
            case 0:
              delay(5);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 60, 100);
              DmxMaster.write(32, 128);
              DmxMaster.write(33, 128);
              DmxMaster.write(34, 128);
        
              break;
            case 1:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 61, 100);
              DmxMaster.write(35, 128);
              DmxMaster.write(36, 128);
              DmxMaster.write(37, 128);
        
              break; 
            case 2:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 62, 100);
              DmxMaster.write(38, 128);
              DmxMaster.write(39, 128);
              DmxMaster.write(40, 128);

              
              break;
            case 3:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 63, 100);
              DmxMaster.write(41, 128);
              DmxMaster.write(42, 128);
              DmxMaster.write(43, 128);
        
              break; 
            case 4:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 64, 100);
              DmxMaster.write(44, 128);
              DmxMaster.write(45, 128);
              DmxMaster.write(46, 128);
              
              break;
            case 5:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 65, 100);
              DmxMaster.write(47, 128);
              DmxMaster.write(48, 128);
              DmxMaster.write(49, 128);
        
              break; 
            case 6:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 66, 100);
              DmxMaster.write(50, 128);
              DmxMaster.write(51, 128);
              DmxMaster.write(52, 128);
              
              break;
            case 7:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 67, 100);
              DmxMaster.write(53, 128);
              DmxMaster.write(54, 128);
              DmxMaster.write(55, 128);
        
              break; 
            case 8:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 68, 100);
              DmxMaster.write(56, 128);
              DmxMaster.write(57, 128);
              DmxMaster.write(58, 128);
              
              break;
            case 9:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 69, 100);
              DmxMaster.write(64, 128);
              DmxMaster.write(65, 128);
              DmxMaster.write(66, 128);
        
              break; 
            case 10:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 70, 100);
              DmxMaster.write(67, 128);
              DmxMaster.write(68, 128);
              DmxMaster.write(69, 128);
              
              break;
            case 11:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 71, 100);
        
           }
        
        }else if(touchStates[i] == 1){
         // is still being touched        
        }  
      
        touchStates[i] = 1;      
      }else{
        if(touchStates[i] == 1){
          switch (i) {
            case 0:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is no longer being touched");
              midiSend(128, 60, 100);
              DmxMaster.write(32, 0);
              DmxMaster.write(33, 0);
              DmxMaster.write(34, 0);
        
              break;
            case 1:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is no longer being touched");
              midiSend(128, 61, 100);
              DmxMaster.write(35, 0);
              DmxMaster.write(36, 0);
              DmxMaster.write(37, 0);
        
              break; 
            case 2:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is no longer being touched");
              midiSend(128, 62, 100);
              DmxMaster.write(38, 0);
              DmxMaster.write(39, 0);
              DmxMaster.write(40, 0);
              
              break;
            case 3:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is no longer being touched");
              midiSend(128, 63, 100);
              DmxMaster.write(41, 0);
              DmxMaster.write(42, 0);
              DmxMaster.write(43, 0);
        
              break; 
            case 4:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is no longer being touched");
              midiSend(128, 64, 100);
              DmxMaster.write(44, 0);
              DmxMaster.write(45, 0);
              DmxMaster.write(46, 0);
              
              break;
            case 5:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is no longer being touched");
              midiSend(128, 65, 100);
              DmxMaster.write(47, 0);
              DmxMaster.write(48, 0);
              DmxMaster.write(49, 0);
        
              break; 
            case 6:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is no longer being touched");
              midiSend(128, 66, 100);
              DmxMaster.write(50, 0);
              DmxMaster.write(51, 0);
              DmxMaster.write(52, 0);
              
              break;
            case 7:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is no longer being touched");
              midiSend(128, 67, 100);
              DmxMaster.write(53, 0);
              DmxMaster.write(54, 0);
              DmxMaster.write(55, 0);
        
              break; 
            case 8:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is no longer being touched");
              midiSend(128, 68, 100);
              DmxMaster.write(56, 0);
              DmxMaster.write(57, 0);
              DmxMaster.write(58, 0);
              
              break;
            case 9:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is no longer being touched");
              midiSend(128, 69, 100);
              DmxMaster.write(64, 0);
              DmxMaster.write(65, 0);
              DmxMaster.write(66, 0);
        
              break; 
            case 10:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is no longer being touched");
              midiSend(128, 70, 100);
              DmxMaster.write(67, 0);
              DmxMaster.write(68, 0);
              DmxMaster.write(69, 0);
              
              break;
            case 11:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is no longer being touched");
              midiSend(128, 71, 100);
        
           }
       }
        
        touchStates[i] = 0;
      }
    
    }
    
  }
  
  
//********************  SECOND Capacitive Touch Sensor
  if(!checkInterruptTwo()){
    
    // read the touch state from the MPR121
    Wire.requestFrom(0x5D,4); 
    
    byte LSB = Wire.read();
    byte MSB = Wire.read();
    
    uint16_t touched = ((MSB << 8) | LSB); // 16bits that make up the touch states
  
    for (int i=0; i < 12; i++){  // Check what electrodes were pressed
    
      if(touched & (1<<i)){
      
        if(touchStatesTwo[i] == 0){
          switch (i) {
            case 0:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 72, 100);
              DmxMaster.write(32, 128);
              DmxMaster.write(33, 128);
              DmxMaster.write(34, 128);
        
              break;
            case 1:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 73, 100);
        
              break; 
            case 3:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 74, 100);
           }
        
        }else if(touchStatesTwo[i] == 1){
         // is still being touched        
        }  
      
        touchStatesTwo[i] = 1;      
      }else{
        if(touchStatesTwo[i] == 1){
          switch (i) {
            case 0:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is no longer being touched");
              midiSend(128, 72, 100);              
              DmxMaster.write(32, 0);
              DmxMaster.write(33, 0);
              DmxMaster.write(34, 0);
        
              break;
            case 1:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is no longer being touched");
              midiSend(128, 73, 100);
        
              break; 
            case 3:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is no longer being touched");
              midiSend(128, 74, 100);
           }
       }
        
        touchStatesTwo[i] = 0;
      }
    
    }
    
  }
  
}


void mpr121_setup(void){

  set_register(0x5A, ELE_CFG, 0x00); 
  
  // Section A - Controls filtering when data is > baseline.
  set_register(0x5A, MHD_R, 0x01);
  set_register(0x5A, NHD_R, 0x01);
  set_register(0x5A, NCL_R, 0x00);
  set_register(0x5A, FDL_R, 0x00);

  // Section B - Controls filtering when data is < baseline.
  set_register(0x5A, MHD_F, 0x01);
  set_register(0x5A, NHD_F, 0x01);
  set_register(0x5A, NCL_F, 0xFF);
  set_register(0x5A, FDL_F, 0x02);
  
  // Section C - Sets touch and release thresholds for each electrode
  set_register(0x5A, ELE0_T, SHORT_POINT_ON);
  set_register(0x5A, ELE0_R, SHORT_POINT_OFF);
 
  set_register(0x5A, ELE1_T, SHORT_POINT_ON);
  set_register(0x5A, ELE1_R, SHORT_POINT_OFF);
  
  set_register(0x5A, ELE2_T, SHORT_POINT_ON);
  set_register(0x5A, ELE2_R, SHORT_POINT_OFF);
  
  set_register(0x5A, ELE3_T, SHORT_POINT_ON);
  set_register(0x5A, ELE3_R, SHORT_POINT_OFF);
  
  set_register(0x5A, ELE4_T, SHORT_POINT_ON);
  set_register(0x5A, ELE4_R, SHORT_POINT_OFF);
  
  set_register(0x5A, ELE5_T, LONG_POINT_ON);
  set_register(0x5A, ELE5_R, LONG_POINT_OFF);
  
  set_register(0x5A, ELE6_T, MED_POINT_ON);
  set_register(0x5A, ELE6_R, MED_POINT_OFF);
  
  set_register(0x5A, ELE7_T, LONG_POINT_ON);
  set_register(0x5A, ELE7_R, LONG_POINT_OFF);
  
  set_register(0x5A, ELE8_T, MED_POINT_ON);
  set_register(0x5A, ELE8_R, MED_POINT_OFF);
  
  set_register(0x5A, ELE9_T, LONG_POINT_ON);
  set_register(0x5A, ELE9_R, LONG_POINT_OFF);
  
  set_register(0x5A, ELE10_T, 0x01);
  set_register(0x5A, ELE10_R, 0x00);
  
  set_register(0x5A, ELE11_T, LONG_POINT_ON);
  set_register(0x5A, ELE11_R, LONG_POINT_OFF);
  
  // Section D
  // Set the Filter Configuration
  // Set ESI2
  set_register(0x5A, FIL_CFG, 0x04);
  
  // Section E
  // Electrode Configuration
  // Set ELE_CFG to 0x00 to return to standby mode
  set_register(0x5A, ELE_CFG, 0x0C);  // Enables all 12 Electrodes
  
  
  // Section F
  // Enable Auto Config and auto Reconfig
  set_register(0x5A, ATO_CFG0, 0x0B);
  set_register(0x5A, ATO_CFGU, 0x0F);  // USL = (Vdd-0.7)/vdd*256 = 0xC9 @3.3V    set_register(0x5A, ATO_CFGU, 0xC9);   
  set_register(0x5A, ATO_CFGL, 0x01);  // LSL = 0.65*USL = 0x82 @3.3V             set_register(0x5A, ATO_CFGL, 0x82);
  set_register(0x5A, ATO_CFGT, 0x08);  // Target = 0.9*USL = 0xB5 @3.3V
  
  //set_register(0x5A, ELE_CFG, 0x0C);
  
}

void mpr121_setupTwo(void){

  set_register(0x5D, ELE_CFG, 0x00); 
  
  // Section A - Controls filtering when data is > baseline.
  set_register(0x5D, MHD_R, 0x01);
  set_register(0x5D, NHD_R, 0x01);
  set_register(0x5D, NCL_R, 0x00);
  set_register(0x5D, FDL_R, 0x00);

  // Section B - Controls filtering when data is < baseline.
  set_register(0x5D, MHD_F, 0x01);
  set_register(0x5D, NHD_F, 0x01);
  set_register(0x5D, NCL_F, 0xFF);
  set_register(0x5D, FDL_F, 0x02);
  
  // Section C - Sets touch and release thresholds for each electrode
  set_register(0x5D, ELE0_T, MED_POINT_ON);
  set_register(0x5D, ELE0_R, MED_POINT_OFF);
 
  set_register(0x5D, ELE1_T, LONG_POINT_ON);
  set_register(0x5D, ELE1_R, LONG_POINT_OFF);
  
  set_register(0x5D, ELE2_T, MED_POINT_ON);
  set_register(0x5D, ELE2_R, MED_POINT_OFF);
  
  set_register(0x5D, ELE3_T, MED_POINT_ON);
  set_register(0x5D, ELE3_R, MED_POINT_OFF);
  
  set_register(0x5D, ELE4_T, MED_POINT_ON);
  set_register(0x5D, ELE4_R, MED_POINT_OFF);
  
  set_register(0x5D, ELE5_T, MED_POINT_ON);
  set_register(0x5D, ELE5_R, MED_POINT_OFF);

  set_register(0x5D, ELE6_T, MED_POINT_ON);
  set_register(0x5D, ELE6_R, MED_POINT_OFF);
  
  set_register(0x5D, ELE7_T, MED_POINT_ON);
  set_register(0x5D, ELE7_R, MED_POINT_OFF);
  
  set_register(0x5D, ELE8_T, TOU_THRESH);
  set_register(0x5D, ELE8_R, REL_THRESH);
  
  set_register(0x5D, ELE9_T, TOU_THRESH);
  set_register(0x5D, ELE9_R, REL_THRESH);
  
  set_register(0x5D, ELE10_T, TOU_THRESH);
  set_register(0x5D, ELE10_R, REL_THRESH);
  
  set_register(0x5D, ELE11_T, TOU_THRESH);
  set_register(0x5D, ELE11_R, REL_THRESH);
  
  // Section D
  // Set the Filter Configuration
  // Set ESI2
  set_register(0x5D, FIL_CFG, 0x04);
  
  // Section E
  // Electrode Configuration
  // Set ELE_CFG to 0x00 to return to standby mode
  set_register(0x5D, ELE_CFG, 0x0C);  // Enables all 12 Electrodes
  
  
  // Section F
  // Enable Auto Config and auto Reconfig
  set_register(0x5D, ATO_CFG0, 0x0B);
  set_register(0x5D, ATO_CFGU, 220);  // USL = (Vdd-0.7)/vdd*256 = 0xC9 @3.3V    set_register(0x5A, ATO_CFGU, 0xC9);   
  set_register(0x5D, ATO_CFGL, 101);  // LSL = 0.65*USL = 0x82 @3.3V             set_register(0x5A, ATO_CFGL, 0x82);
  set_register(0x5D, ATO_CFGT, 160);  // Target = 0.9*USL = 0xB5 @3.3V
  
  //set_register(0x5D, ELE_CFG, 0x0C);
  
}

*/

boolean checkInterrupt(void){
  return digitalRead(irqpin);
}

boolean checkInterruptTwo(void){
  return digitalRead(irqpin);
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
