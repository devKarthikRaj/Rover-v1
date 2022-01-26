/*
 * roverV1.h - //Contains pin & IO definitions and movement methods for rover version 1.   
 * Created by Karthik Raj, November 22, 2021.
 * Released into the public domain.
 */

#include "roverV1.h"
#include "Arduino.h"

//Constructor
roverV1::roverV1() {
    //IO definitions
    pinMode(mdrv1EnA, OUTPUT);
    pinMode(mdrv1In1, OUTPUT);
    pinMode(mdrv1In2, OUTPUT);
    pinMode(mdrv1EnB, OUTPUT);
    pinMode(mdrv1In3, OUTPUT);
    pinMode(mdrv1In4, OUTPUT);
    pinMode(mdrv2EnA, OUTPUT);
    pinMode(mdrv2In1, OUTPUT);
    pinMode(mdrv2In2, OUTPUT);
    pinMode(mdrv2EnB, OUTPUT);
    pinMode(mdrv2In3, OUTPUT);
    pinMode(mdrv2In4, OUTPUT);
    pinMode(eStop, INPUT);
}

//Method Definitions
void roverV1::moveForward() {
  digitalWrite(mdrv1EnB,HIGH);
  digitalWrite(mdrv2EnA,HIGH);

  digitalWrite(mdrv1In3, LOW);
  digitalWrite(mdrv1In4, HIGH);
  digitalWrite(mdrv2In1, LOW);
  digitalWrite(mdrv2In2, HIGH);
}

void roverV1::moveBackward() {
  digitalWrite(mdrv1EnB,HIGH);
  digitalWrite(mdrv2EnA,HIGH);

  digitalWrite(mdrv1In3, HIGH);
  digitalWrite(mdrv1In4, LOW);
  digitalWrite(mdrv2In1, HIGH);
  digitalWrite(mdrv2In2, LOW);
} 

void roverV1::spinLeft() {
  digitalWrite(mdrv1EnB,HIGH);
  digitalWrite(mdrv2EnA,HIGH);

  digitalWrite(mdrv1In3, HIGH);
  digitalWrite(mdrv1In4, LOW);
  digitalWrite(mdrv2In1, LOW);
  digitalWrite(mdrv2In2, HIGH);
}

void roverV1::spinRight() {
  digitalWrite(mdrv1EnB,HIGH);
  digitalWrite(mdrv2EnA,HIGH);

  digitalWrite(mdrv1In3, LOW);
  digitalWrite(mdrv1In4, HIGH);
  digitalWrite(mdrv2In1, HIGH);
  digitalWrite(mdrv2In2, LOW);
}

void roverV1::engageBrakes() {
  digitalWrite(mdrv1EnB,LOW);
  digitalWrite(mdrv2EnA,LOW);  
}