
/*
* discreption : code have the functions of the motor  bts7960
* 
*
*
**/

#define RPWM_MOTORRIGHT_PIN 5 
#define LPWM_MOTORRIGHT_PIN 6
#define RPWM_MOTORLEFT_PIN 7
#define LPWM_MOTORLEFT_PIN 8











// function to move the two motors in the forward direction 
void forwardMove()  // clockwise 
{
  // to move forward adjust the two motors in the clockwise direction 
  motorRight_C();
  motorleft_C();

}

// function to move the two motors in the reverse direction 
void reverseMove()  // counterclockwise 
{
  // to move forward adjust the two motors in the clockwise direction 
  motorright_CC();
  motorleft_CC();
}

//======================functions to rotate ========================

void rotateLeftW_S()  // rotate left with stop the left wheel 
{
  motorRight_C();
  stopMotorLeft();

}

void rotateLeftWO_S()  // rotate left With the left wheel rotate reverse 
{
  motorRight_C();
  motorleft_CC();

}

void rotateRightW_S()  // rotate right with stop the right wheel 
{
  motorleft_C();
  stopMotorRight();

}

void rotateRightWO_S()  // rotate right With the right wheel rotate reverse 
{
  motorleft_C();
  motorright_CC();

}





// ====================== functions for each motor ===================

// function to rotate the right motor in clock wise direction 
void motorRight_C()
{
  analogWrite(RPWM_MOTORRIGHT_PIN,0); // motor1
  analogWrite(LPWM_MOTORRIGHT_PIN,255);  // motor1


}

// function to rotate the left motor in clock wise direction 
void motorleft_C()
{
  analogWrite(RPWM_MOTORLEFT_PIN,0); // motor2
  analogWrite(LPWM_MOTORLEFT_PIN,255);  // motor2
  

}

// function to rotate the right motor in counterclock wise direction 
void motorright_CC()
{
  analogWrite(RPWM_MOTORRIGHT_PIN,255); // motor1
  analogWrite(LPWM_MOTORRIGHT_PIN,0);  // motor1


}

// function to rotate the left motor in counterclock wise direction 
void motorleft_CC()
{
  analogWrite(RPWM_MOTORLEFT_PIN,255); // motor2
  analogWrite(LPWM_MOTORLEFT_PIN,0);  // motor2


}

// function to stop the right motor 
void stopMotorRight()
{
  analogWrite(RPWM_MOTORRIGHT_PIN,0); // motor1
  analogWrite(LPWM_MOTORRIGHT_PIN,0);  // motor1


}

// function to stop the left motor 
void stopMotorLeft()
{
  analogWrite(RPWM_MOTORLEFT_PIN,0); // motor1
  analogWrite(LPWM_MOTORLEFT_PIN,0);  // motor1


}