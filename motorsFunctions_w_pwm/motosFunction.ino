/*
* discreption : code have the functions of the motor  bts7960
* note : pins en1 ,en2 adjust the pwm 
*
*
**/

#define RPWM_MOTORRIGHT_PIN 5 
#define LPWM_MOTORRIGHT_PIN 6
#define RPWM_MOTORLEFT_PIN 7
#define LPWM_MOTORLEFT_PIN 8

#define PWM_MOTORRIGHT 9
#define PWM_MOTORLEFT 10






void setup() {
  // put your setup code here, to run once:
  pinMode(RPWM_MOTORRIGHT_PIN, OUTPUT);
  pinMode(LPWM_MOTORRIGHT_PIN, OUTPUT);
  pinMode(RPWM_MOTORLEFT_PIN, OUTPUT);
  pinMode(RPWM_MOTORLEFT_PIN, OUTPUT);

  pinMode(PWM_MOTORRIGHT, OUTPUT);
  pinMode(PWM_MOTORLEFT, OUTPUT);





}


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
  digitalWrite(RPWM_MOTORRIGHT_PIN,LOW); // motor1
  digitalWrite(LPWM_MOTORRIGHT_PIN,HIGH);  // motor1
  analogWrite(PWM_MOTORRIGHT, 255);

}

// function to rotate the left motor in clock wise direction 
void motorleft_C()
{
  digitalWrite(RPWM_MOTORLEFT_PIN,LOW); // motor2
  digitalWrite(LPWM_MOTORLEFT_PIN,HIGH);  // motor2
  analogWrite(PWM_MOTORLEFT, 255);

}

// function to rotate the right motor in counterclock wise direction 
void motorright_CC()
{
  digitalWrite(RPWM_MOTORRIGHT_PIN,HIGH); // motor1
  digitalWrite(LPWM_MOTORRIGHT_PIN,LOW);  // motor1
  analogWrite(PWM_MOTORRIGHT, 255);

}

// function to rotate the left motor in counterclock wise direction 
void motorleft_CC()
{
  digitalWrite(RPWM_MOTORLEFT_PIN,HIGH); // motor2
  digitalWrite(LPWM_MOTORLEFT_PIN,LOW);  // motor2
  analogWrite(PWM_MOTORLEFT, 255);

}

// function to stop the right motor 
void stopMotorRight()
{
  digitalWrite(RPWM_MOTORRIGHT_PIN,LOW); // motor1
  digitalWrite(LPWM_MOTORRIGHT_PIN,LOW);  // motor1
  analogWrite(PWM_MOTORRIGHT, 0);

}

// function to stop the left motor 
void stopMotorLeft()
{
  digitalWrite(RPWM_MOTORLEFT_PIN,LOW); // motor1
  digitalWrite(LPWM_MOTORLEFT_PIN,LOW);  // motor1
  analogWrite(PWM_MOTORLEFT, 0);

}