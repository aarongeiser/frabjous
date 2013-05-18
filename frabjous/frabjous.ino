#include <MIDI.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <SPI.h>
#include <Wire.h>
#include "mpr121.h"
#include <RAS.h>

/////////////////////////
// WiFi Shield Variables
/////////////////////////
char ssid[] = "pterodactyl"; //  your network SSID (name) 
char pass[] = "5kM3Ywpf2";    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key Index number (needed only for WEP)
int status = WL_IDLE_STATUS; // status of the wifi connection

// initialize the library instance:
WiFiClient client;

/////////////////////////
// Touch Sensor Variables
/////////////////////////
int irqpin = 2;  // Digital 2
boolean touchStates[12]; //to keep track of the previous touch states

/////////////////////////
// Rugged Audio Shield Variables
/////////////////////////
// RAS RAS;
// int lastVolume;

////////////////////////////////////////////////////////////////////////////
//  Initialization
////////////////////////////////////////////////////////////////////////////
void setup(void){
  
  ///////////////////////////////
  // WiFi Connect
  ///////////////////////////////
  
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present"); 
    // don't continue:
    while(true);
  } 
  
  // attempt to connect to Wifi network:
  while ( status != WL_CONNECTED) { 
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:    
    status = WiFi.begin(ssid, pass);  
 
    // wait 10 seconds for connection:
    delay(10000);
  } 
  // you're connected now, so print out the status:
  printWifiStatus();
  
  ////////////////////////////////
  // Touch Sensor
  ///////////////////////////////
  
  pinMode(irqpin, INPUT);
  digitalWrite(irqpin, HIGH); //enable pullup resistor
  
  Serial.begin(9600);
  Wire.begin();

  mpr121_setup();
  
  ///////////////////////////////
  // Rugged Audio
  ///////////////////////////////
  
  // Rugged Audio Shield
  // RAS.begin();
  // RAS.InitSD();
  // delay(100);
  // RAS.OutputEnable();
  
}

////////////////////////////////////////////////////////////////////////////
// Do Things Good
////////////////////////////////////////////////////////////////////////////
void loop(void){
  //delay(1000);
  //RAS.PlayWAV("test1.wav");
  //delay(1000);
  //RAS.PlayWAV("test2.wav");
  //delay(1000);
  //RAS.PlayWAV("test3.wav");
  readTouchInputs();
}

////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////

void readTouchInputs(){
  if(!checkInterrupt()){
    
    //read the touch state from the MPR121
    Wire.requestFrom(0x5A,2); 
    
    byte LSB = Wire.read();
    byte MSB = Wire.read();
    
    uint16_t touched = ((MSB << 8) | LSB); //16bits that make up the touch states

    
    for (int i=0; i < 12; i++){  // Check what electrodes were pressed
      if(touched & (1<<i)){
      
        if(touchStates[i] == 0){
          switch (i) {
            case 0:
            
              // Rugged Audio Shield (unused)
              // delay(100);
              // RAS.PlayWAV("test1.wav");
              
              // Test Printing
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
        
              break;
            case 1:
            
              // Rugged Audio Shield (unused)
              // delay(100);
              // RAS.PlayWAV("test2.wav");
              
              // Test Printing
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
        
              break; 
            case 2:
            
              // Rugged Audio Shield (unused)
              // delay(100);
              // RAS.PlayWAV("test3.wav");
              
              // Test Printing
              Serial.print("pin ");
              Serial.print(i);
              Serial.println(" is being touched");
           }
        
        }else if(touchStates[i] == 1){
         // is still being touched        
        }  
      
        touchStates[i] = 1;      
      }else{
        if(touchStates[i] == 1){
          
          // Test Printing
          Serial.print("pin ");
          Serial.print(i);
          Serial.println(" is no longer being touched");
          
          //pin i is no longer being touched
       }
        
        touchStates[i] = 0;
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


boolean checkInterrupt(void){
  return digitalRead(irqpin);
}


void set_register(int address, unsigned char r, unsigned char v){
    Wire.beginTransmission(address);
    Wire.write(r);
    Wire.write(v);
    Wire.endTransmission();
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
