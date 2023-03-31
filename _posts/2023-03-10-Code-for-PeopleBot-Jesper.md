*Created 10th March, 2023*  
*Record of code being tested*  
**Markdown cheatsheet: https://www.markdownguide.org/cheat-sheet/**

# Code for PeopleBot
## March 31st, 2023 - Simple MC with ultrasonic sensors
What we did:  
- Tested sensors together with motors

What we learned:  
- For some reason the wheels won't turn when the command to turn on motors is in an IF statement (something might be wrong with my code).
- When the motors receive a number in mySerial.write the speed is different depending if the number is a float, int or double. FLOAT SHOULD BE USED.
- When initializing the program, the wheels jerk randomly.

Next steps:
- Get motors moving in response to sensor data.
- Figure out how to stop wheel jerk

Code:
````
//This code makes the wheels turn when the distance to the A0 sensor is more than 50. Otherwise the wheels should be still.

#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 4);  // RX, TX but currently only using pin 4 since not data received

float avg0 = 0; //This variable holds the average of 10 readings from A0 sensor
float speed = 30; //0-63 speed 
float minD = 50; //min distance for wheels to turn

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // Values between 0-128 control M1
  // 0 to 63 forward, 64 is stop, 65 to 127 backward
  // Values between 128 to 255 control M2 
  // 128 to 191 forward, 192 is stop, 193 to 255 backward
  mySerial.write(64);   // M1, forward, medium speed
  mySerial.write(192);  // M2, forward, medium speed
}

void loop() {
  // read first 10 inputs to A0 and take average
  for ( int i = 0; i < 10; ++i ) 
  { 
    avg0 += 0.1 * analogRead(A0) ; //average of first 10 readings
  }
  
  //Serial.println(avg0); //use this to see if the average is averaging

  if (avg0 < minD) 
  {
    //make wheels stop
    Serial.println("Not enough space :(");
    mySerial.write(64); //M1 stop
    mySerial.write(256 - 64); //M2 stop
  }
  else 
  { 
    //make wheels go
    Serial.println("Let's gooo!");
    mySerial.write(64 + speed); //M1 forward
    mySerial.write(192 + speed); //M2 forward
  }
  avg0 = 0;
  delay(1000);
}

````


## March 28th, 2023 - Ultrasonic sensor test
What we did:  
- Tested sensors

What we learned:  
- Use running average or just every 10 values take the average to decide how to move.
- Compare side sensors and which ever is larger, turn to that side.

Next steps:
- Get motors moving in response to sensor data.

Code:
Sensors work with simple code File > Examples > Basic > AnalogSerialReader

## March 8th, 2023  - Wheel test  
What we did:  
- Tested the motor controller (MC).

What we learned:  
- We are using software serial instead of a PWM pin (~).  
- use #include <SoftwareSerial.h> to enable software serial.  
- Values between 0-128 control M1 (0-63 forward, 64 stop, 65-127 backward).  
- Values between 128-255 control M2 (128-190 forward, 191 stop,192-255 backward).  

Next steps:
- Test ultrsonic sensors  

This code was used to test the MC:  
````
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
````

