// (c) Benjamin McGinty 2021

// +---------+---------+
// |  Robot  |         |
// +---------+---------+
// | Servo1A | Servo1B |
// | Servo2A | Servo2B |
// +---------+---------+

#include <Servo.h>

Servo servoSetA;
Servo servoSetB;

// Define the servo pin:

const int FWD_BTN = A0; // the number of the pushbutton pin
const int BWD_BTN = A1; // the number of the pushbutton pin
const int SRVO_L_BTN = A2; // the number of the pushbutton pin
const int SRVO_R_BTN = A3; // the number of the pushbutton pin

const int MTR_FWD = 2; // the number of the motor pin
const int MTR_BWD = 3; // the number of the motor pin

// create variable for target location
int targetAngle = 90;

void setup() 
{  // Attach the Servo variable to a pin:
  servoSetA.attach(5);
  servoSetB.attach(6);

  pinMode(FWD_BTN, INPUT_PULLUP);
  pinMode(BWD_BTN, INPUT_PULLUP);
  pinMode(SRVO_L_BTN, INPUT_PULLUP);
  pinMode(SRVO_R_BTN, INPUT_PULLUP);

  pinMode(MTR_FWD, OUTPUT); // forwards command
  pinMode(MTR_BWD, OUTPUT); // backwards commmand
} 

void loop() 
{ 
  servoSetA.write(targetAngle);
  servoSetB.write(targetAngle);
  
  int fwdState;
  fwdState = digitalRead(FWD_BTN);
  int bwdState;
  bwdState = digitalRead(BWD_BTN);
  int srvoLBtnState;
  srvoLBtnState = digitalRead(SRVO_L_BTN);
  int srvoRBtnState;
  srvoRBtnState = digitalRead(SRVO_R_BTN);

  if (fwdState == HIGH && bwdState == LOW) {
    digitalWrite(MTR_FWD, HIGH); 
    digitalWrite(MTR_BWD, LOW);   
  }
  else if (fwdState == LOW && bwdState == HIGH) {
    digitalWrite(MTR_FWD, LOW); 
    digitalWrite(MTR_BWD, HIGH); 
  }
  else{
    digitalWrite(MTR_FWD, LOW); 
    digitalWrite(MTR_BWD, LOW); 
  }

  if (srvoLBtnState == HIGH){
    targetAngle = targetAngle + 1;
    servoSetA.write(targetAngle);
    servoSetB.write(targetAngle);
  }
  else if (srvoRBtnState == HIGH){
    targetAngle = targetAngle - 1;
    servoSetA.write(targetAngle);
    servoSetB.write(targetAngle);
  }
  
}  
