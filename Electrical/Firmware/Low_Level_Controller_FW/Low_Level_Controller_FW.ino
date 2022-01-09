/* Rover Version 1 Mark I Low Level Controller Firmware
 *  
 *  Receive encoded movement data from master over Bluetooth link.
 *  Send encoded movement data to motor controller over UART link.
 *  
 *  Code written for Arduino Mega Clone (Driver Auto Installed by Windows)
 *  
 *  UART 0 - Serial - For debugging
 *  UART 1 - Serial1 - Bluetooth link (wireless UART)
 *  UART 2 - Serial2 - UART to motor controller
 *  
 *  The low level controller acts as a middleman between the remote and the motor controller
 *  This code receives joystick data over Bluetooth and sends it to motor controller over UART
 *  
 *  Written By Karthik Raj
 */

#define hc05_state 7

void setup() {
  Serial.begin(38400);
  Serial1.begin(38400); //HC05 chips are configured to exchange data at 38400 baud
  Serial2.begin(38400);

  pinMode(hc05_state, INPUT);
}

void loop() {
  //stuff
  if(digitalRead(hc05_state) == HIGH) {
    //If data available...
    if(Serial1.available()>0) {
      char i = Serial1.read(); //Read the movement data from master over the Bluetooth link and store it in a char
      Serial2.print(i); //Send the stored movement data to the motor controller over UART
      Serial.print(i); //For debugging only
    }
    //if no data available... 
    else {
      //Serial.println("No data received from master"); //Only for debugging
    }
  } else {
    Serial2.print("(512,512)");
    Serial.print("BT Connection Lost"); //For debugging only
  }
}
