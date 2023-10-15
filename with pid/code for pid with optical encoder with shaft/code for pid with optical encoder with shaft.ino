#define encoderright 2
#define encoderleft 3

// PID constants (adjust as needed)
float kp = 0.06; // Proportional gain
float ki = 0.0; // Integral gain
float kd = 0.01; // Derivative gain

// PID variables
float error = 0.0;
float integral = 0.0;
float derivative = 0.0;
float previousError = 0.0;
float output = 0.0;


unsigned int rpmright;
unsigned int rpmleft;

volatile byte rightpulses;
volatile byte leftpulses;

unsigned long TIME;
unsigned int pulse_per_turn = 20;  // number of the opens in the shaft 
float wheel_circumference=20.41;  // the R for the wheel 
//depends on the number of slots on the slotted disc

void countright(){
  // counting the number of pulses for calculation of rpm
  rightpulses++;
}
void countleft(){
  // counting the number of pulses for calculation of rpm
  leftpulses++;
}


/*************************pid**************************/
void adjustMotorSpeeds(int targetSpeedLeft, int targetSpeedRight) {
    // Calculate speed errors
    float errorLeft = targetSpeedLeft - calculateSpeedLeft();
    float errorRight = targetSpeedRight - calculateSpeedRight();

    // Calculate proportional term
    float pTermLeft = kp * errorLeft;
    float pTermRight = kp * errorRight;

    // Calculate integral term (if ki is non-zero)
    integral += ki * (errorLeft + errorRight);

    // Calculate derivative term (if kd is non-zero)
    derivative = kd * (errorLeft - errorRight);

    // Calculate the output
    output = pTermLeft + integral + derivative;

    // Adjust motor speeds
    int newSpeedLeft = targetSpeedLeft + output;
    int newSpeedRight = targetSpeedRight - output;


    // this for the constrains 

    int minSpeed = 70; // Replace with your minimum allowed speed
    int maxSpeed = 220;  // Replace with your maximum allowed speed

    if (newSpeedLeft < minSpeed) {
        newSpeedLeft = minSpeed;
    } else if (newSpeedLeft > maxSpeed) {
        newSpeedLeft = maxSpeed;
    }

    if (newSpeedRight < minSpeed) {
        newSpeedRight = minSpeed;
    } else if (newSpeedRight > maxSpeed) {
        newSpeedRight = maxSpeed;
    }    

    // Set motor speeds (adjust as needed)
    setMotorSpeeds(newSpeedLeft, newSpeedRight);
}




/***************************for encoder and we could put here the pid ***************************/
   //reset all to 0
  rpmright = 0;
  rpmleft = 0;

  rightpulses = 0;
  leftpulses = 0;

  TIME = 0;

 
  pinMode(encoderright, INPUT);// setting up encoder pin as input
  pinMode(encoderleft, INPUT);// setting up encoder pin as input

  //triggering count function everytime the encoder turns from HIGH to LOW
  attachInterrupt(digitalPinToInterrupt(encoderright), countright, FALLING);
  attachInterrupt(digitalPinToInterrupt(encoderleft), countleft, FALLING);






void setup() {


  // this if the encoder has  output pin 
  pinMode(encoderright, INPUT);// setting up encoder pin as input
  pinMode(encoderleft, INPUT);// setting up encoder pin as input
 

   adjustMotorSpeeds(100,100);





}

void loop() {
  
      adjustMotorSpeeds(100,100);

     /**********************************code for pid updated with encoder ******************/
   if (millis() - TIME >= 100){ // updating every 0.1 second
    detachInterrupt(digitalPinToInterrupt(encoderright)); // turn off trigger
    detachInterrupt(digitalPinToInterrupt(encoderleft)); // turn off trigger

    //calcuate for rpm 
    rpmright = (60 *100 / pulse_per_turn)/ (millis() - TIME) * rightpulses;

  

    rpmleft = (60 *100 / pulse_per_turn)/ (millis() - TIME) * leftpulses;
   
    // Calculate target speeds based on desired behavior
    float targetSpeedLeft = 100; // Adjust as needed
    float targetSpeedRight = 100; // Adjust as needed
  

    // Call the PID control function to adjust motor speeds
    adjustMotorSpeeds(targetSpeedLeft, targetSpeedRight);


        //trigger count function everytime the encoder turns from HIGH to LOW
    attachInterrupt(digitalPinToInterrupt(encoderright), countright, FALLING);
    attachInterrupt(digitalPinToInterrupt(encoderleft), countleft, FALLING);

}


// function for the motor speed  
// void setMotorSpeeds(int speed_M1, int speed_M2){}

