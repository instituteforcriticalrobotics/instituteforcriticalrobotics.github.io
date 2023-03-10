**Created 10th March, 2023  
**Record of code being tested  

#Code for PeopleBot

## March 8th, 2023  
## Wheel test  

This code was used to test the motorcontroller:  

#include <SoftwareSerial.h>

// Pin 4 is transmit data from Arduino to the
// motor controller. Pin 3 is unused at the
// moment.
SoftwareSerial mySerial(3, 4);  // RX, TX

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  motorsStop();
}

void motorsStop() {
  // Values between 0-128 control M1
  // 0-63 in one direction, 55-127 in the other direction
  // M1 stop = 64
  // 128-255 control M2
  // m2 stop = 256-64
  mySerial.write(64);        // M1, forward, medium speed
  mySerial.write(256 - 64);  // M2, forward, medium speed
}

void loop() {
  // put your main code here, to run repeatedly:
}   

This is what we found out:  
- We are using software serial instead of a PWM port (~).  
- use #include <SoftwareSerial.h> to enable.  
- Values between 0-128 control M1 (0-63 forward, 64 stop, 65-127 backward).  
- Values between 128-255 control M2 (128-190 forward, 191 stop,192-255 backward).  
