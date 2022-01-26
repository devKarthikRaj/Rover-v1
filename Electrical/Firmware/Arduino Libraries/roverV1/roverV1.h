/*
 * roverV1.h - //Contains pin & IO definitions and movement methods for rover version 1.   
 * double dutyCycleCreated by Karthik Raj, November 22, 2021.
 */

#ifndef roverV1_h 
#define roverV1_h

class roverV1 {
  public:
    //Pin definitions
    #define mdrv1EnA 3
    #define mdrv1In1 2
    #define mdrv1In2 4

    #define mdrv1EnB 7
    #define mdrv1In3 6
    #define mdrv1In4 8

    #define mdrv2EnA A2
    #define mdrv2In1 A0
    #define mdrv2In2 A1

    #define mdrv2EnB A3
    #define mdrv2In3 12
    #define mdrv2In4 11

    #define eStop 13

    //Constructor
    roverV1();

    //Methods
    void roverV1::moveForward();
    void roverV1::moveBackward();
    void roverV1::spinRight();
    void roverV1::spinLeft();
    void roverV1::engageBrakes();
};

#endif