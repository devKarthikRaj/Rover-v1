/*  Remote Control Firmware
 *    Code written for Arduino Nano Clone (Driver Auto Installed by Windows)
 *    
 *    This code reads the joystick, smooths out the input by averaging and sends the averged data over Bluetooth 
 *    
 *    Written By Karthik Raj
 */
#include <SoftwareSerial.h>

#define joystickRx A1
#define joystickRy A0
#define btTx 7
#define btRx 6

//Define second pair of tx and rx (for Arduino Uno only)
SoftwareSerial hc05(btRx, btTx); // RX, TX

void setup() {
  pinMode(joystickRx, INPUT);
  pinMode(joystickRy, INPUT);
  pinMode(btTx, OUTPUT);
  pinMode(btRx, INPUT);

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
