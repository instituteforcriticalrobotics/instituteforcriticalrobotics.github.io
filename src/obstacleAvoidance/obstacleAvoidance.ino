/*
  obstacle avoidance using ultrasonic distance measuring
  sensors and the Dimension motor controller

  ## April 7th, 2023 - wheels on the ground test
*/

const int FORWARD = 0;
const int REVERSE = 1;
const int LEFT = 0;
const int RIGHT = 1;
const int fspeed = 60; //forward speed
const int tspeed = fspeed / 2; //turn speed since two wheels in opposite directions move faster
const int bspeed = fspeed / 6; //backward speed different since we might not expect the robot to move backward


const int smallTurn = 1500;
const int bigTurn = 2000;
const int thinkTime = 1000;

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
  if (distanceA1 >= 40) {
    Serial.println("Going straight");
    goForward();
  } else {
    Serial.println("Something is ahead");
    motorsStop();
    delay(thinkTime);

    Serial.println("What could it be?");
    delay(thinkTime);

    int distanceA0 = analogRead(A0);
    int distanceA1 = analogRead(A1);
    int distanceA2 = analogRead(A2);

    if (distanceA0 > 170 && distanceA2 > 170) {
      Serial.println("hUmAN!?");
      delay(10000);
    }
    //Back up until there is enough space
    while (distanceA1 < 50) {
      Serial.println("Backing up");
      goBack(999);
      distanceA1 = analogRead(A1);
    }

    motorsStop();
    delay(500);

    //If backing up created enough space ahead, turn to the side which seems to have more space.
    distanceA0 = analogRead(A0);
    distanceA2 = analogRead(A2);

    if (distanceA2 > distanceA0) {
      Serial.println("Turning right");
      delay(1000);
      turnRight(bigTurn);
      motorsStop();
      delay(500);
    } else {
      Serial.println("Turning left");
      delay(1000);
      turnLeft(bigTurn);
      motorsStop();
      delay(500);
    }
  }
  //If something dedected closeby on the right, stop and turn to face it.
  if (distanceA2 < 40) {
    Serial.println("Something on the right");
    delay(1000);
    motorsStop();
    turnRight(smallTurn); //turn to face the obstacle

    //take new readings
    int distanceA0 = analogRead(A0);
    int distanceA1 = analogRead(A1);
    int distanceA2 = analogRead(A2);
    Serial.println("What could it be?");
    delay(1000);

    if (distanceA2 < 170) { //if there is a wall, turn left again and ignore
      Serial.println("It's nothing");
      delay(1000);
      turnLeft(bigTurn);
    } else {  //if no wall, stay there for 10 seconds
      Serial.println("hUmAN!?");
      delay(10000);
      Serial.println("OK bye!");
      delay(1000);
      turnLeft(bigTurn);
    }
  }
  //If something dedected closeby on the left, stop and turn to face it.
  if (distanceA0 < 40) {
    Serial.println("Something on the left");
    delay(1000);
    motorsStop();
    turnLeft(smallTurn); //turn to face the obstacle

    //take new readings
    int distanceA0 = analogRead(A0);
    int distanceA1 = analogRead(A1);
    int distanceA2 = analogRead(A2);
    Serial.println("What could it be?");
    delay(1000);

    if (distanceA0 < 150) { //if there is a wall, turn right again and ignore
      Serial.println("It's nothing");
      delay(1000);
      turnRight(bigTurn);
    } else {  //if no wall, stay there for 10 seconds
      Serial.println("hUmAN!?");
      delay(10000);
      Serial.println("OK bye!");
      delay(1000);
      turnRight(bigTurn);
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
  delay(300);
}

void motorWrite(int value) {
  if (debug) {
    Serial.print("sending ");
    Serial.println(value);
  }
  mySerial.write(value);
}

void goForward() { //go forward until further notice

  motorRun(RIGHT, 0, fspeed);
  motorRun(LEFT, 0, fspeed);

}

//duration = 999 for indefinite
void goBack(int duration) { //back up for some time
  motorRun(RIGHT, 1, bspeed);
  motorRun(LEFT, 1, bspeed);

  if (duration != 999) {
    delay(duration);
    motorsStop();
  }

}

//duration = 999 for indefinite
void turnRight(int duration) { //rotate clockwise for some time

  motorRun(RIGHT, 1, tspeed);
  motorRun(LEFT, 0, tspeed);

  if (duration != 999) {
    delay(duration);
    motorsStop();
  }

}

//duration = 999 for indefinite
void turnLeft(int duration) { //rotate anti clockwise for some time

  motorRun(RIGHT, 0, tspeed);
  motorRun(LEFT, 1, tspeed);

  if (duration != 999) {
    delay(duration);
    motorsStop();
  }

}
