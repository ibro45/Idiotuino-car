#include <NewPing.h>

// line 337 in Studuino.cpp has to be commented out, or else there will occur a "Tone.cpp" error
#include "Studuino.h" 

NewPing sonarR(10, 11, 5800); // right ultrasonic sensor
NewPing sonarL(12, 13, 5800); // left ultrasonic sensor
NewPing sonarF(8, 9, 15); // front ultrasonic sensor

Studuino board;

void setup() {
  board.InitDCMotorPort(PORT_M1);
  board.InitDCMotorPort(PORT_M2);
  
}

void loop() {
  
  if (sonarF.ping_cm()) 
  {
    if (sonarR.ping_cm() > sonarL.ping_cm())
    {
      board.DCMotor(PORT_M1, NORMAL, 255, 300, COAST);
    }
    else if (sonarL.ping_cm() > sonarR.ping_cm())
    {
      board.DCMotor(PORT_M2, NORMAL, 255, 300, COAST);
    }
    else 
    {
      board.DCMotor(PORT_M1, NORMAL, 255, 500, COAST);
    } 
  }
  else if (sonarL.ping_cm() != 0 && sonarL.ping_cm() < 15) 
  {
    board.DCMotor(PORT_M2, NORMAL, 255, 300, COAST); // move right from obstacle
  }
  else if (sonarR.ping_cm() != 0 && sonarR.ping_cm() < 15) 
  {
    board.DCMotor(PORT_M1, NORMAL, 255, 300, COAST); // move left from obstacle
  }
  else 
  {
    board.Move(FORWARD, 255, 100, COAST);
  } 
} // end of loop()



