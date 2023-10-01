#define X_dir 34 //input only pin
#define Y_dir 35 //input only pin
#define push_button 36 //input only pin
//the range of x or y directions from 0 --> 1023
volatile short X_reading = 512, Y_reading = 512;
volatile short mappingValue_X=0; // adding the variable for mapping the value for the motor 
volatile short mappingValue_Y=0; // adding the variable for mapping the value for the motor 


void setup()
{

  pinMode(RPWM_MOTORRIGHT_PIN, OUTPUT);
  pinMode(LPWM_MOTORRIGHT_PIN, OUTPUT);
  pinMode(RPWM_MOTORLEFT_PIN, OUTPUT);
  pinMode(RPWM_MOTORLEFT_PIN, OUTPUT);
// for joystick 
  pinMode(X_dir,INPUT);
  pinMode(Y_dir, INPUT);
  pinMode(push_button, INPUT);
  attachInterrupt(push_button, break_fun, RISING);




}
void loop()
{

   X_reading = analogRead(X_dir);
   Y_reading = analogRead(Y_dir);
   mappingValue_X=map(X_reading,512,1023,0,255);
   mappingValue_Y=map(Y_reading,512,1023,0,255);
   

   if(X_reading == 512 && Y_reading == 512)
   {
     //this is the status when the chair stands by
    stopMotorRight();
    stopMotorLeft();

   }
   if(X_reading > 512 && X_reading <= 1023 && Y_reading == 512)
   {
     //this is the status when the chair moves forward
     //due to the value between 512 and 1023 the velocity of the motors set
     forwardMove();
     provideSpeed(mappingValue_X);

   }
   if(X_reading < 512 && X_reading >= 0 && Y_reading == 512)
   {
     //this is the status when the chair moves backword
     //due to the value between 512 and 0 the velocity of the motors set
     reverseMove();
     provideSpeed(mappingValue_X);


   }
   if(X_reading == 512 && Y_reading > 512 && Y_reading <= 1023)
   {
     //this is the status when the chair rotates right
     //due to the value between 512 and 1023 the velocity of the motors set
     rotateRightWO_S();
     provideSpeed(mappingValue_Y);


   }
   if(X_reading == 512 && Y_reading >= 0 && Y_reading < 512)
   {
      //this is the status when the chair rotates left
     //due to the value between 512 and 0 the velocity of the motors set
     rotateLeftWO_S();
     provideSpeed(mappingValue_Y);


   }



    if(X_reading == 1023 && Y_reading == 1023)
   {
     //in this status the chair moves diagonal forward-right

   }
   if(X_reading == 1023 && Y_reading == 0)
   {
     //in this status the chair moves diagonal forward-left

   }
   if(X_reading == 0 && Y_reading == 1023)
   {
     //in this status the chair moves diagonal backward-right

   }
  if(X_reading == 0 && Y_reading == 0)
   {
     //in this status the chair moves diagonal backward-left
     
   }
}
void break_fun()
{
  //stop all motors to stop the movement of the chair
  stopMotorRight();
  stopMotorLeft();


}


