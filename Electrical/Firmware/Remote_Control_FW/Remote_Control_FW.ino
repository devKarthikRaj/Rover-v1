//Read joystick values > convert to heading in complex 2d system > tx over bt link
//read sensor data     > make sense of sensor data               > tx 

#include <Coordinates.h> //Complex num operations... This lib operates in radians from 0 to 2PI
#include <SoftwareSerial.h>

#define joystickRx A1
#define joystickRy A0
#define btTx 2
#define btRx 3

#define toDeg 57.2957795131 //Multiply by this to convert from rad to deg

//Adjust these vals for calibration (if rover moves when joystick not touched)
float joystickCtrX = 511; //Center Rx value
float joystickCtrY = 493; //Center Ry value 

//Define vectors
Coordinates joystickCtr = Coordinates(); //Joystick center vector
Coordinates joystickReadVal = Coordinates(); //Latest joystick vals vector
Coordinates distVec = Coordinates(); //Distance moved from center vector 

//Define second pair of tx and rx (for Arduino Uno only)
SoftwareSerial hc05(btRx, btTx); // RX, TX


void setup() {
  pinMode(joystickRx, INPUT);
  pinMode(joystickRy, INPUT);
  pinMode(btTx, OUTPUT);
  pinMode(btRx, INPUT);

  //Set the joystick center points (points of no movement)
  joystickCtr.fromCartesian(joystickCtrX, joystickCtrY); 

  Serial.begin(9600);
  hc05.begin(38400);
}

void loop() {
  //Read from joystick and store vals in joystickReadVal vector
  long avgJoystickRxSum = 0;
  long avgJoystickRySum = 0;
  
  for(int i = 0; i < 100; i++) {
    avgJoystickRxSum += analogRead(joystickRx);
    avgJoystickRySum += analogRead(joystickRy);
  }
  int avgJoystickRx = round(avgJoystickRxSum/100);
  int avgJoystickRy = round(avgJoystickRySum/100);

  //Form the motor controller input string to be sent over the bt link
  String mConIn = "("+String(avgJoystickRx)+","+String(avgJoystickRy)+")";

  Serial.println(mConIn);
  hc05.print(mConIn);
}
