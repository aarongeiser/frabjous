#include <SPI.h>
#include <Wire.h>
#include "mpr121.h"

// Touch Sensor Variables
int irqpin = 3;  // Digital 2
int irqpinTwo = 4;  // Digital 3 - Sensor 2
boolean touchStates[12]; //to keep track of the previous touch states
boolean touchStatesTwo[12]; //to keep track of the previous touch states



//  Initialization
void setup(void){
  
  // Touch Sensor
  pinMode(irqpin, INPUT);
  digitalWrite(irqpin, HIGH); //enable pullup resistor
  
  pinMode(irqpinTwo, INPUT);
  digitalWrite(irqpinTwo, HIGH); //enable pullup resistor
  
  Wire.begin();
  mpr121_setup();
  mpr121_setupTwo();
  
  Serial.begin(31250);
  
}

void loop(void){
  readTouchInputs();
}

//  First Capacitive Touch Sensor

void readTouchInputs(){
  if(!checkInterrupt()){
    
    //read the touch state from the MPR121
    Wire.requestFrom(0x5A,3); 
    
    byte LSB = Wire.read();
    byte MSB = Wire.read();
    
    uint16_t touched = ((MSB << 8) | LSB); //16bits that make up the touch states

    
    for (int i=0; i < 12; i++){  // Check what electrodes were pressed
      if(touched & (1<<i)){
      
        if(touchStates[i] == 0){
          switch (i) {
            case 0:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 60, 100);
        
              break;
            case 1:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 61, 100);
        
              break; 
            case 2:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 62, 100);
              
              break;
            case 3:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 63, 100);
        
              break; 
            case 4:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 64, 100);
              
              break;
            case 5:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 65, 100);
        
              break; 
            case 6:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 66, 100);
              
              break;
            case 7:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 67, 100);
        
              break; 
            case 8:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 68, 100);
              
              break;
            case 9:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 69, 100);
        
              break; 
            case 10:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 70, 100);
              
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
              Serial.println(" is being touched");
              midiSend(128, 60, 100);
        
              break;
            case 1:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(128, 61, 100);
        
              break; 
            case 2:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(128, 62, 100);
              
              break;
            case 3:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(128, 63, 100);
        
              break; 
            case 4:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(128, 64, 100);
              
              break;
            case 5:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(128, 65, 100);
        
              break; 
            case 6:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(128, 66, 100);
              
              break;
            case 7:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(128, 67, 100);
        
              break; 
            case 8:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(128, 68, 100);
              
              break;
            case 9:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(128, 69, 100);
        
              break; 
            case 10:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(128, 70, 100);
              
              break;
            case 11:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(128, 71, 100);
        
           }
       }
        
        touchStates[i] = 0;
      }
    
    }
    
  }
  
  
  //  Second Touch Sensor
  if(!checkInterruptTwo()){
    
    //read the touch state from the MPR121
    Wire.requestFrom(0x5D,4); 
    
    byte LSB = Wire.read();
    byte MSB = Wire.read();
    
    uint16_t touched = ((MSB << 8) | LSB); //16bits that make up the touch states

    
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
        
              break;
            case 1:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(144, 73, 100);
        
              break; 
            case 2:
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
              Serial.println(" is being touched");
              midiSend(128, 72, 100);
        
              break;
            case 1:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
              midiSend(128, 73, 100);
        
              break; 
            case 2:
              delay(10);
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
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
  set_register(0x5A, ELE0_T, TOU_THRESH);
  set_register(0x5A, ELE0_R, REL_THRESH);
 
  set_register(0x5A, ELE1_T, TOU_THRESH);
  set_register(0x5A, ELE1_R, REL_THRESH);
  
  set_register(0x5A, ELE2_T, TOU_THRESH);
  set_register(0x5A, ELE2_R, REL_THRESH);
  
  set_register(0x5A, ELE3_T, TOU_THRESH);
  set_register(0x5A, ELE3_R, REL_THRESH);
  
  set_register(0x5A, ELE4_T, TOU_THRESH);
  set_register(0x5A, ELE4_R, REL_THRESH);
  
  set_register(0x5A, ELE5_T, TOU_THRESH);
  set_register(0x5A, ELE5_R, REL_THRESH);
  
  set_register(0x5A, ELE6_T, TOU_THRESH);
  set_register(0x5A, ELE6_R, REL_THRESH);
  
  set_register(0x5A, ELE7_T, TOU_THRESH);
  set_register(0x5A, ELE7_R, REL_THRESH);
  
  set_register(0x5A, ELE8_T, TOU_THRESH);
  set_register(0x5A, ELE8_R, REL_THRESH);
  
  set_register(0x5A, ELE9_T, TOU_THRESH);
  set_register(0x5A, ELE9_R, REL_THRESH);
  
  set_register(0x5A, ELE10_T, TOU_THRESH);
  set_register(0x5A, ELE10_R, REL_THRESH);
  
  set_register(0x5A, ELE11_T, TOU_THRESH);
  set_register(0x5A, ELE11_R, REL_THRESH);
  
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
  /*set_register(0x5A, ATO_CFG0, 0x0B);
  set_register(0x5A, ATO_CFGU, 0xC9);  // USL = (Vdd-0.7)/vdd*256 = 0xC9 @3.3V   set_register(0x5A, ATO_CFGL, 0x82);  // LSL = 0.65*USL = 0x82 @3.3V
  set_register(0x5A, ATO_CFGT, 0xB5);*/  // Target = 0.9*USL = 0xB5 @3.3V
  
  set_register(0x5A, ELE_CFG, 0x0C);
  
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
  set_register(0x5D, ELE0_T, TOU_THRESH);
  set_register(0x5D, ELE0_R, REL_THRESH);
 
  set_register(0x5D, ELE1_T, TOU_THRESH);
  set_register(0x5D, ELE1_R, REL_THRESH);
  
  set_register(0x5D, ELE2_T, 0x72);
  set_register(0x5D, ELE2_R, 0x6A);
  
  set_register(0x5D, ELE3_T, TOU_THRESH);
  set_register(0x5D, ELE3_R, REL_THRESH);
  
  set_register(0x5D, ELE4_T, TOU_THRESH);
  set_register(0x5D, ELE4_R, REL_THRESH);
  
  set_register(0x5D, ELE5_T, TOU_THRESH);
  set_register(0x5D, ELE5_R, REL_THRESH);

  set_register(0x5D, ELE6_T, TOU_THRESH);
  set_register(0x5D, ELE6_R, REL_THRESH);
  
  set_register(0x5D, ELE7_T, TOU_THRESH);
  set_register(0x5D, ELE7_R, REL_THRESH);
  
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
  /*set_register(0x5A, ATO_CFG0, 0x0B);
  set_register(0x5A, ATO_CFGU, 0xC9);  // USL = (Vdd-0.7)/vdd*256 = 0xC9 @3.3V   set_register(0x5A, ATO_CFGL, 0x82);  // LSL = 0.65*USL = 0x82 @3.3V
  set_register(0x5A, ATO_CFGT, 0xB5);*/  // Target = 0.9*USL = 0xB5 @3.3V
  
  set_register(0x5D, ELE_CFG, 0x0C);
  
}


boolean checkInterrupt(void){
  return digitalRead(irqpin);
}

boolean checkInterruptTwo(void){
  return digitalRead(irqpinTwo);
}


void set_register(int address, unsigned char r, unsigned char v){
    Wire.beginTransmission(address);
    Wire.write(r);
    Wire.write(v);
    Wire.endTransmission();
}

//  plays a MIDI note.  Doesn't check to see that
//  cmd is greater than 127, or that data values are  less than 127:
void midiSend(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
