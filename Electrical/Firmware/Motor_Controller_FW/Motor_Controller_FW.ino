/* Motor Controller Version 1 Firmware
 *  
 *  Code written for Arduino Nano Clone (Driver Auto Installed by Windows)
 *  
 *  UART 0 - Serial - For debugging
 *  UART 1 - uart1 - UART to low level controller
 *  
 *  This code receives and decodes joystick data and then drives the motors accordingly
 *
 *  Written By Karthik Raj 
 */

#include <SoftwareSerial.h>
#include <roverV1.h>

#define uartRx 9
#define uartTx 10

//Global Vars
int xAxisReq;
int yAxisReq;

//Define UART port for comms with LLC
SoftwareSerial uart1(uartRx, uartTx); //RX,TX
  
void setup() {
  Serial.begin(230400);
  uart1.begin(38400);

  pinMode(uartRx, INPUT);
  pinMode(uartTx, OUTPUT);
}

void loop() {
  //--- Receive and decode movement data ---
  rxMovementData(); //Updates xAxisReq andyAxisReq

  //Only for debugging
  Serial.print("Rx: ");
  Serial.print("(");
  Serial.print(xAxisReq);
  Serial.print(",");
  Serial.print(yAxisReq);
  Serial.print(")");
  Serial.print(" ");

  String motorStatus = driveMotors();
  
  //Only for debugging
  Serial.print("MotorStatus: ");
  Serial.print(motorStatus);
  Serial.print(" ");
  Serial.println();
}

/* Receive Movement Data
    If data is avaialble from LLC...
    Receive data
    Decode data
    Update reqSpeedMultiplier and reqAbsHeading
*/
void rxMovementData() {
  //if data available...
  if (uart1.available() > 0) {
    //"(" is the start byte
    if (uart1.read() == '(') {
      String _mConInString = uart1.readStringUntil(')'); //")" is the end byte
      //Serial.print(mConInString); //Only for debugging

      //Convert received mConInString to char array for further processing
      char _mConInCharArray[_mConInString.length() + 1]; //+1 to leave space for the null terminator
      _mConInString.toCharArray(_mConInCharArray, _mConInString.length() + 1);

      int _splitCharElmNum; //Element number of the '<' that splits the speed from the heading
      for (int i = 0; i < sizeof(_mConInString); i++) {
        if (_mConInString[i] == ',') {
          _splitCharElmNum = i;
        }
      }
      //Splitting the mConInCharArray into its native components - x and y
      //Decoding speed x
      char _xArray[_splitCharElmNum + 1];
      for (int i = 0; i < _splitCharElmNum; i++) {
        _xArray[i] = _mConInCharArray[i];
      }
      int _xAxis = atoi(_xArray);

      //Decoding y
      char _yArray[_splitCharElmNum + 1];
      for (int i = 0; i < (sizeof(_mConInCharArray) - 1 - _splitCharElmNum); i++) {
        _yArray[i] = _mConInCharArray[_splitCharElmNum + 1 + i];
      }
      int _yAxis = atoi(_yArray);
      
      //Pass the local vals to the global vars for use in other functions
      xAxisReq = _xAxis;
      yAxisReq = _yAxis;
    } else {
      //Serial.println("Rx'ing garbage data"); //THIS IS NOT THE RIGHT WAY TO DETECT GARBAGE DATA
    }
  }
  //if no data available...
  else {
    //Serial.print("No Data Rx'ed");
  }
}

String driveMotors() {
  String currStatus = "Init"; //Init Status
  if(digitalRead(eStop) == HIGH) {
    if(xAxisReq > 300 && xAxisReq < 800 && yAxisReq > 800) {
      //Forward-Maintain
      roverV1().moveForward();
      currStatus = "Forward-Maintain";
    } else if(xAxisReq > 300 && xAxisReq < 800 && yAxisReq < 300) {
      //Backward-Maintain
      roverV1().moveBackward();
      currStatus = "Backward-Maintain";
    } else if(xAxisReq < 300) {
      //Left
      roverV1().spinLeft();
      currStatus = "SpinLeft";
    } else if(xAxisReq > 800) {
      //Right
      roverV1().spinRight();
      currStatus = "SpinRight";
     }
  } else {
    currStatus = "Brake";
    roverV1().engageBrakes();
  }

  return currStatus;
}
