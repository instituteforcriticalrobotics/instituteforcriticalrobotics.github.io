*Created 10th March, 2023*  
*Record of code being tested*  
**Markdown cheatsheet: https://www.markdownguide.org/cheat-sheet/**

# Code for PeopleBot
## April 7th, 2023 - wheels on the ground test
Things learned:
- It is very easy for a robot to be cute.
- if we see something on the side, when we turn back we need to turn back more than we did initially so we don’t run into the again
- turning is quicker than going straight because motors turning in opposite directions
- for some reason back up is also quicker.
- need to incorporate acceleration because robot wants to tip over when moving backward and stopping suddenly.
- annoying to turn with dc motors because it is dependent on speed. if speed is changed all the delays need to be adjusted. Need to make it easier to do this adjustment.
  - make a calibration code then make a table with values we can use i.e. at speed 100, it takes this many ms to turn 90 degrees.
- What is another way that you can make a robot turn???

Code: https://github.com/instituteforcriticalrobotics/instituteforcriticalrobotics.github.io/blob/main/src/obstacleAvoidance/README.md

## April 5th, 2023 - testing sensors
![image](https://user-images.githubusercontent.com/125130687/229997135-c3756e31-4fd6-4bf4-8f27-84ab392c261b.png)

used slightly modified code from *File > Examples > Basic > AnalogSerialReader* 

## April 5th, 2023 - testing an obstacle avoidance algorithm

For the following algorithm (moving forward and backing up and turning around when sensing a wall with the front sensor):

![image](https://user-images.githubusercontent.com/125130687/229988557-c569e050-9f9c-4436-b421-cefff37f29b8.png)

The following code worked:
````
const int FORWARD = 0;
const int REVERSE = 1;
const int LEFT = 0;
const int RIGHT = 1;

int debug = false;

int distanceA0 = 0;
int distanceA1 = 0;
int distanceA2 = 0;

#include <SoftwareSerial.h>

// Pin 4 is transmit data from Arduino to the
// motor controller. Pin 3 is unused at the
// moment.
SoftwareSerial mySerial(3, 4);  // RX, TX

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);

  Serial.println("Arduino reset");
  motorsStop();
}

void loop() {
  int distanceA0 = analogRead(A0);
  int distanceA1 = analogRead(A1);
  int distanceA2 = analogRead(A2);
  if (debug) Serial.println(distanceA0);
  
  //motorRun(LEFT, distanceA0 > 50 ? FORWARD : REVERSE, 100);
  
  //Go forward if space ahead, else back up
  if (distanceA1 >= 20) {
    goForward();
  } else {
    motorsStop();
    delay(500);

    //Back up until there is enough space
    while (distanceA1 < 30) {
    goBack(200);
    distanceA1 = analogRead(A1);
    }
    
    motorsStop();
    delay(500);

    //If backing up created enough space ahead, turn to the side which seems to have more space.
    distanceA0 = analogRead(A0);
    distanceA2 = analogRead(A2);
    
    if (distanceA2 > distanceA0) {
      turnRight(1000);
      motorsStop();
      delay(500);
    } else {
      turnLeft(1000);
      motorsStop();
      delay(500);
    }
  }
  delay(2);
}

/* run a motor. You get to choose
    which motor, which direction, and how fast

   int which = which motor (0 or 1)
   int direction = cw or ccw (0 or 1)
   int speed = Speed of motor which can be between 0-255
*/
void motorRun(int which, int direction, int speed) {
  speed = map(speed, 0, 255, 62, 1); // real speed is only 1-62
  speed = constrain( speed, 0, 62);
  if (direction) speed = speed + 64 ;
  which ? motorWrite(speed) : motorWrite(256 - speed);
}

void motorsStop() {
  // Values between 0-127 control M1
  // 0-63 in one direction,65-127 in the other direction
  // M1 stop = 64
  // 128-255 control M2
  // m2 stop = 256-64
  motorWrite(64);
  motorWrite(256 - 64);
}

void motorWrite(int value) {
  if (debug) {
    Serial.print("sending ");
    Serial.println(value);
  }
  mySerial.write(value);
}

void goForward() { //go forward until further notice

  motorRun(RIGHT, 0, 100);
  motorRun(LEFT, 0, 100);

}

//duration = 999 for indefinite 
void goBack(int duration) { //back up for some time
  motorRun(RIGHT, 1, 100);
  motorRun(LEFT, 1, 100);

  if (duration != 999) {
    delay(duration);
    motorsStop();
  }

}

//duration = 999 for indefinite 
void turnRight(int duration) { //rotate clockwise for some time

  motorRun(RIGHT, 1, 100);
  motorRun(LEFT, 0, 100);
  
  if (duration != 999) {
    delay(duration);
    motorsStop();
  }

}

//duration = 999 for indefinite 
void turnLeft(int duration) { //rotate anti clockwise for some time

  motorRun(RIGHT, 0, 100);
  motorRun(LEFT, 1, 100);
  
  if (duration != 999) {
    delay(duration);
    motorsStop();
  }

}

````

Things to be improved:
Incorporate side sensors into obstacle sensing. 
- Take some readings and come up with values for minimum distance from each sesnor before the robot needs to react. 
- Make movement a little more natural by introducing some randomness. 
- Test out motor acceleration to improve battery performance. 
- How could the robot be made to be more welcoming so that people feel comfortable to interact with it?

## March 31st, 2023 - Michael Shiloh
I'm not sure why Jesper's code below wasn't working, but this works in that the motors do the right thing based on the A2 distance measuring sensor. However there is still something weird going on in that upon reset the motors twitch a bit. By turning on debugging it seems that sometimes the motor 
controller is sent different values prior to being reset, and then the Arduino resets again (as evidenced by the message in `setup() `

````

const int FORWARD = 0;
const int REVERSE = 1;
const int LEFT = 0;
const int RIGHT = 1;

int debug = false;

#include <SoftwareSerial.h>

// Pin 4 is transmit data from Arduino to the
// motor controller. Pin 3 is unused at the
// moment.
SoftwareSerial mySerial(3, 4);  // RX, TX

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);

  Serial.println("Arduino reset");
  motorsStop();
}

/* run a motor. You get to choose
    which motor, which direction, and how fast

   int which = which motor (0 or 1)
   int direction = cw or ccw (0 or 1)
   int speed = Speed of motor which can be between 0-255
*/
void motorRun(int which, int direction, int speed) {
  speed = map(speed, 0, 255, 62, 1); // real speed is only 1-62
  speed = constrain( speed, 0, 62);
  if (direction) speed = speed + 64 ;
  which ? motorWrite(speed) : motorWrite(256 - speed);
}

void motorsStop() {
  // Values between 0-127 control M1
  // 0-63 in one direction,65-127 in the other direction
  // M1 stop = 64
  // 128-255 control M2
  // m2 stop = 256-64
  motorWrite(64);
  motorWrite(256 - 64);
}

void motorWrite(int value) {
  if (debug) {
    Serial.print("sending ");
    Serial.println(value);
  }
  mySerial.write(value);
}

void loop() {
  int forwardDistance = analogRead(A2);
  if (debug) Serial.println(forwardDistance);
  motorRun(LEFT, forwardDistance > 50 ? FORWARD : REVERSE, 100);
  delay(2);
}
````

## March 31st, 2023 - Simple MC with ultrasonic sensors
What we did:  
- Tested sensors together with motors

What we learned:  
- For some reason the wheels won't turn when the command to turn on motors is in an IF statement (something might be wrong with my code).
- When the motors receive a number in mySerial.write the speed is different depending if the number is a float, int or double. FLOAT SHOULD BE USED.
- When initializing the program, the wheels jerk randomly.

Next steps:
- Get motors moving in response to sensor data.
- Figure out how to stop wheel jerk. There are libraries for accelerating wheels (AccelStepper) rather than going to a specific speed suddenly - might come in handly later.

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

