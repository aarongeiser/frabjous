#include <Wire.h>
#include <Centipede.h>
#include <DmxMaster.h>
#include <SoftwareSerial.h>

/** ****************************************************
********************************************************
*******************************************************/

// Frabjous Initialization
boolean frabjousState;

// Centipede Shield
Centipede CS; // create Centipede object
boolean touchStates[36]; // to keep track of the previous touch states
boolean disabledPin[36]; // to keep track of the previous touch states

// Set software serial pins that communicate with MIDI shield
#define rxPin 8
#define txPin 9
SoftwareSerial mySerial(rxPin,txPin); // RX, TX

/** ****************************************************
********************************************************
*******************************************************/

void setup() {
  
  //  Centipede Initialization
  Wire.begin(); // start I2C
  CS.initialize(); // set all registers to default 
  CS.portMode(0, 0b1111111111111111); // set all pins on chip 0 to input
  CS.portMode(2, 0b1111111111111111); // set all pins on chip 1 to input
  CS.portPullup(0, 0b1111111111111111); // 0 = no pullup, 1 = pullup
  CS.portPullup(2, 0b1111111111111111); // 0 = no pullup, 1 = pullup
  
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
 
  if (frabjousState == 0) {
    
      Serial.print("Initializing Frabjous...");
      initializeFrabjous();
      frabjousState = 1;
      Serial.print("Frabjous Initialized.");
      
  }

  
  readTouchInputs();
  
}

/** ****************************************************
********************************************************
*******************************************************/

boolean checkConnection(int pinNum){
  
  boolean result;
  
  if (CS.digitalRead(pinNum) == 1){
    disabledPin[pinNum] = 1;
    result = 1;
  } else {
    result = 0;
  }
  
  return result;
  
}

/** ****************************************************
********************************************************
*******************************************************/

void initializeFrabjous(){
  
  for (int i=0; i < 36; i++){  
    switch (i) {
      case 0:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 60, 100);
          DmxMaster.write(32, 128);
          DmxMaster.write(33, 128);
          DmxMaster.write(34, 128);
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");
        }
        break;
        
      case 1:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 61, 100);
          DmxMaster.write(35, 128);
          DmxMaster.write(36, 128);
          DmxMaster.write(37, 128);
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");        
        }
        break;
        
      case 2:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 62, 100);
          DmxMaster.write(38, 128);
          DmxMaster.write(39, 128);
          DmxMaster.write(40, 128);
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");        
        }
        break;
        
      case 3:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 63, 100);
          DmxMaster.write(41, 128);
          DmxMaster.write(42, 128);
          DmxMaster.write(43, 128);
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");        
        }
        break;
        
      case 4:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 64, 100);
          DmxMaster.write(44, 128);
          DmxMaster.write(45, 128);
          DmxMaster.write(46, 128);
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");        
        }
        break;
        
      case 5:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 65, 100);
          DmxMaster.write(47, 128);
          DmxMaster.write(48, 128);
          DmxMaster.write(49, 128);
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");        
        }
        break;
        
      case 6:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 66, 100);
          DmxMaster.write(50, 128);
          DmxMaster.write(51, 128);
          DmxMaster.write(52, 128);
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");        
        }
        break;
        
      case 7:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 67, 100);
          DmxMaster.write(53, 128);
          DmxMaster.write(54, 128);
          DmxMaster.write(55, 128);
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");        
        }
        break;
        
      case 8:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 68, 100);
          DmxMaster.write(56, 128);
          DmxMaster.write(57, 128);
          DmxMaster.write(58, 128);
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");        
        }
        break;
        
      case 9:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 69, 100);
          DmxMaster.write(64, 128);
          DmxMaster.write(65, 128);
          DmxMaster.write(66, 128);
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");        
        }
        break;
        
      case 10:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 70, 100);
          DmxMaster.write(67, 128);
          DmxMaster.write(68, 128);
          DmxMaster.write(69, 128);
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");        
        }
        break;
        
      case 11:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 71, 100);
          DmxMaster.write(70, 128);
          DmxMaster.write(71, 128);
          DmxMaster.write(72, 128);
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");        
        }
        break;
        
      case 12:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 72, 100);
          DmxMaster.write(73, 128);
          DmxMaster.write(74, 128);
          DmxMaster.write(75, 128);
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");        
        }
        break;
        
      case 13:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 73, 100);
          DmxMaster.write(76, 128);
          DmxMaster.write(77, 128);
          DmxMaster.write(78, 128);
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");        
        }
        break;
        
      case 14:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 74, 100);
          DmxMaster.write(79, 128);
          DmxMaster.write(80, 128);
          DmxMaster.write(81, 128);
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");        
        }
        break;
        
      case 15:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 75, 100);
          DmxMaster.write(82, 128);
          DmxMaster.write(83, 128);
          DmxMaster.write(84, 128);
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");        
        }
        break;
        
      case 32:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 76, 100);
          DmxMaster.write(85, 128);
          DmxMaster.write(86, 128);
          DmxMaster.write(87, 128);
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");        
        }
        break;
        
      case 33:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 77, 100);
          DmxMaster.write(88, 128);
          DmxMaster.write(89, 128);
          DmxMaster.write(90, 128);
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");        
        }
        break;
        
      case 34:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 78, 100);
          DmxMaster.write(85, 128);
          DmxMaster.write(86, 128);
          DmxMaster.write(87, 128);
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");        
        }
        break;
        
      case 35:
        delay(200);
        Serial.print("tip ");
        Serial.print(i);
        Serial.println(" check");
        if (checkConnection(i) == 0){
          midiSend(144, 79, 100);
          DmxMaster.write(88, 128);
          DmxMaster.write(89, 128);
          DmxMaster.write(90, 128);    
        } else {
          Serial.print("tip ");
          Serial.print(i);
          Serial.println(" not connected.  Disabled.");        
        }
        delay(1200);     
        
     }  
     
  touchStates[i] = 1;
    
  }

}

/** ****************************************************
********************************************************
*******************************************************/

void readTouchInputs(){
  
   for (int i=0; i < 36; i++){
       if ((touchStates[i]) == (CS.digitalRead(i))) {
         // Do nothing (still being touched)
       } else {
         
         if (touchStates[i] == 0){
            switch (i) {
              case 0:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 60, 100);
                  DmxMaster.write(32, 128);
                  DmxMaster.write(33, 128);
                  DmxMaster.write(34, 128);
                }
                break;
                
              case 1:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 61, 100);
                  DmxMaster.write(35, 128);
                  DmxMaster.write(36, 128);
                  DmxMaster.write(37, 128);
                }
                break;
                
              case 2:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 62, 100);
                  DmxMaster.write(38, 128);
                  DmxMaster.write(39, 128);
                  DmxMaster.write(40, 128);
                }
                break;
                
              case 3:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 63, 100);
                  DmxMaster.write(41, 128);
                  DmxMaster.write(42, 128);
                  DmxMaster.write(43, 128);
                }
                break;
                
              case 4:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 64, 100);
                  DmxMaster.write(44, 128);
                  DmxMaster.write(45, 128);
                  DmxMaster.write(46, 128);
                }
                break;
                
              case 5:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 65, 100);
                  DmxMaster.write(47, 128);
                  DmxMaster.write(48, 128);
                  DmxMaster.write(49, 128);
                }
                break;
                
              case 6:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 66, 100);
                  DmxMaster.write(50, 128);
                  DmxMaster.write(51, 128);
                  DmxMaster.write(52, 128);
                }
                break;
                
              case 7:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 67, 100);
                  DmxMaster.write(53, 128);
                  DmxMaster.write(54, 128);
                  DmxMaster.write(55, 128);
                }
                break;
                
              case 8:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 68, 100);
                  DmxMaster.write(56, 128);
                  DmxMaster.write(57, 128);
                  DmxMaster.write(58, 128);
                }
                break;
                
              case 9:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 69, 100);
                  DmxMaster.write(64, 128);
                  DmxMaster.write(65, 128);
                  DmxMaster.write(66, 128);
                }
                break;
                
              case 10:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 70, 100);
                  DmxMaster.write(67, 128);
                  DmxMaster.write(68, 128);
                  DmxMaster.write(69, 128);
                }
                break;
                
              case 11:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 71, 100);
                  DmxMaster.write(70, 128);
                  DmxMaster.write(71, 128);
                  DmxMaster.write(72, 128);
                }
                break;
                
              case 12:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 72, 100);
                  DmxMaster.write(73, 128);
                  DmxMaster.write(74, 128);
                  DmxMaster.write(75, 128);
                }
                break;
                
              case 13:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 73, 100);
                  DmxMaster.write(76, 128);
                  DmxMaster.write(77, 128);
                  DmxMaster.write(78, 128);
                }
                break;
                
              case 14:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 74, 100);
                  DmxMaster.write(79, 128);
                  DmxMaster.write(80, 128);
                  DmxMaster.write(81, 128);
                }
                break;
                
              case 15:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 75, 100);
                  DmxMaster.write(82, 128);
                  DmxMaster.write(83, 128);
                  DmxMaster.write(84, 128);
                }
                break;
                
              case 32:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 76, 100);
                  DmxMaster.write(85, 128);
                  DmxMaster.write(86, 128);
                  DmxMaster.write(87, 128);
                }
                break;
                
              case 33:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 77, 100);
                  DmxMaster.write(88, 128);
                  DmxMaster.write(89, 128);
                  DmxMaster.write(90, 128);
                }
                break;
                
              case 34:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 78, 100);
                  DmxMaster.write(85, 128);
                  DmxMaster.write(86, 128);
                  DmxMaster.write(87, 128);
                }
                break;
                
              case 35:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is being touched");
                  midiSend(144, 79, 100);
                  DmxMaster.write(88, 128);
                  DmxMaster.write(89, 128);
                  DmxMaster.write(90, 128);    
                }     
                
             }  
           
             touchStates[i] = 1;
         
         } else if(touchStates[i] == 1){
         
            switch (i) {
              case 0:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 60, 100);
                  DmxMaster.write(32, 128);
                  DmxMaster.write(33, 128);
                  DmxMaster.write(34, 128);
                }
                break;
                
              case 1:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 61, 100);
                  DmxMaster.write(35, 128);
                  DmxMaster.write(36, 128);
                  DmxMaster.write(37, 128);
                }
                break;
                
              case 2:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 62, 100);
                  DmxMaster.write(38, 128);
                  DmxMaster.write(39, 128);
                  DmxMaster.write(40, 128);
                }
                break;
                
              case 3:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 63, 100);
                  DmxMaster.write(41, 128);
                  DmxMaster.write(42, 128);
                  DmxMaster.write(43, 128);
                }
                break;
                
              case 4:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 64, 100);
                  DmxMaster.write(44, 128);
                  DmxMaster.write(45, 128);
                  DmxMaster.write(46, 128);
                }
                break;
                
              case 5:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 65, 100);
                  DmxMaster.write(47, 128);
                  DmxMaster.write(48, 128);
                  DmxMaster.write(49, 128);
                }
                break;
                
              case 6:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 66, 100);
                  DmxMaster.write(50, 128);
                  DmxMaster.write(51, 128);
                  DmxMaster.write(52, 128);
                }
                break;
                
              case 7:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 67, 100);
                  DmxMaster.write(53, 128);
                  DmxMaster.write(54, 128);
                  DmxMaster.write(55, 128);
                }
                break;
                
              case 8:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 68, 100);
                  DmxMaster.write(56, 128);
                  DmxMaster.write(57, 128);
                  DmxMaster.write(58, 128);
                }
                break;
                
              case 9:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 69, 100);
                  DmxMaster.write(64, 128);
                  DmxMaster.write(65, 128);
                  DmxMaster.write(66, 128);
                }
                break;
                
              case 10:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 70, 100);
                  DmxMaster.write(67, 128);
                  DmxMaster.write(68, 128);
                  DmxMaster.write(69, 128);
                }
                break;
                
              case 11:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 71, 100);
                  DmxMaster.write(70, 128);
                  DmxMaster.write(71, 128);
                  DmxMaster.write(72, 128);
                }
                break;
                
              case 12:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 72, 100);
                  DmxMaster.write(73, 128);
                  DmxMaster.write(74, 128);
                  DmxMaster.write(75, 128);
                }
                break;
                
              case 13:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 73, 100);
                  DmxMaster.write(76, 128);
                  DmxMaster.write(77, 128);
                  DmxMaster.write(78, 128);
                }
                break;
                
              case 14:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 74, 100);
                  DmxMaster.write(79, 128);
                  DmxMaster.write(80, 128);
                  DmxMaster.write(81, 128);
                }
                break;
                
              case 15:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 75, 100);
                  DmxMaster.write(82, 128);
                  DmxMaster.write(83, 128);
                  DmxMaster.write(84, 128);
                }
                break;
                
              case 32:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 76, 100);
                  DmxMaster.write(85, 128);
                  DmxMaster.write(86, 128);
                  DmxMaster.write(87, 128);
                }
                break;
                
              case 33:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 77, 100);
                  DmxMaster.write(88, 128);
                  DmxMaster.write(89, 128);
                  DmxMaster.write(90, 128);
                }
                break;
                
              case 34:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 78, 100);
                  DmxMaster.write(85, 128);
                  DmxMaster.write(86, 128);
                  DmxMaster.write(87, 128);
                }
                break;
                
              case 35:
                if (disabledPin[i] == 1) {
                  // Do Nothing
                } else {
                  delay(10);
                  Serial.print("pin ");
                  Serial.print(i);
                  Serial.println(" is no longer being touched");
                  midiSend(128, 79, 100);
                  DmxMaster.write(88, 128);
                  DmxMaster.write(89, 128);
                  DmxMaster.write(90, 128);
                }
  
             }  
           
             touchStates[i] = 0;
         
         }   
         
       } // end if touchStates == checkStates   
   } // end for
  
}

//  plays a MIDI note.  Doesn't check to see that
//  cmd is greater than 127, or that data values are  less than 127:
//  Uses softSerial on pins 10 and 11
void midiSend(int cmd, int pitch, int velocity) {
  mySerial.write(cmd);
  mySerial.write(pitch);
  mySerial.write(velocity);
}
