// MultiStepper.pde
// -*- mode: C++ -*-
//
// Shows how to multiple simultaneous steppers
// Runs one stepper forwards and backwards, accelerating and decelerating
// at the limits. Runs other steppers at the same time
//
// Copyright (C) 2009 Mike McCauley
// $Id: MultiStepper.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <AccelStepper.h>
#include <SoftPWMServo.h> 

int pos = 1000;         // variable to store the servo position, in microseconds

static int state1 = 0;
static int state2 = 0;

int TimeForServoChange;
unsigned long LastMillis = 0;


void setup()
{  
    TimeForServoChange = 25;
}

void loop()
{
  // Change direction at the limits
  if (stepper1.distanceToGo() == 0)
	stepper1.moveTo(-stepper1.currentPosition());
  stepper1.run();
  if (stepper2.distanceToGo() == 0)
	stepper2.moveTo(-stepper2.currentPosition());
  stepper2.run();
  if (millis() != LastMillis)
  {
    TimeForServoChange--;  
    LastMillis = millis();
  }
  if (TimeForServoChange <= 0)
  {
    SoftPWMServoServoWrite(SRV1, pos);     // tell servo to go to position in variable 'pos' 
    SoftPWMServoServoWrite(SRV2, pos);     // tell servo to go to position in variable 'pos' 
    SoftPWMServoServoWrite(SRV3, pos);     // tell servo to go to position in variable 'pos' 
    SoftPWMServoServoWrite(SRV4, pos);     // tell servo to go to position in variable 'pos' 
    SoftPWMServoServoWrite(SRV5, pos);     // tell servo to go to position in variable 'pos' 
    SoftPWMServoServoWrite(SRV6, pos);     // tell servo to go to position in variable 'pos' 
    SoftPWMServoServoWrite(SRV7, pos);     // tell servo to go to position in variable 'pos' 
    SoftPWMServoServoWrite(SRV8, pos);     // tell servo to go to position in variable 'pos' 
    SoftPWMServoServoWrite(SRV9, pos);     // tell servo to go to position in variable 'pos' 
    SoftPWMServoServoWrite(SRV10, pos);     // tell servo to go to position in variable 'pos' 
    #if defined(_BOARD_FUBARINO_SD_)
    SoftPWMServoServoWrite(SRV11, pos);     // tell servo to go to position in variable 'pos' 
    SoftPWMServoServoWrite(SRV12, pos);     // tell servo to go to position in variable 'pos' 
    #endif 
    TimeForServoChange = 25;
    pos += 10;
    if (pos > 2000)
    {
      pos = 1000;
    }
  }
}

