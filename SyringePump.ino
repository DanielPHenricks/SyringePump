#include <AccelStepper.h>

AccelStepper stepper(AccelStepper::DRIVER, 3, 2);
// pin 3 is the step input, pin 2 is the direction input

float flowRate = 100;
// the current flow rate of the pump

int red_LED = 11;
int blue_LED = 9;
int green_LED = 10;
// the pins for the different colors for the LED

int button = 5;
// the pin for the first button

int endButton = 8;
// the button that detects if the pump has reached the end of the cycle

int clockwiseButton = 6;
int ccwButton = 7;

/* ### BONUS QUESTIONS 

  Question 1: Two buttons
 

  Question 2: Potentiometer
  in the loop:
  int sensorValue = analogRead(A0) // (the port)
  flowRate = sensorValue / 20.0;
  // convert the sensorVal to a scaled value: (0-1023) -> (0-50) -> divide by 20 to approximate
  Serial.println(flowRate);
  delay(1); // is this necessary?

  ### END BONUS QUESTIONS*/
  
void setup() {
  Serial.begin(9600);
  pinMode(red_LED, OUTPUT);
  pinMode(blue_LED, OUTPUT);
  pinMode(green_LED, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(clockwiseButton, INPUT_PULLUP);
  stepper.setMaxSpeed(1000);
  stepper.setSpeed(flowRate * 3 / 8);
  // 3/8 was calculated by 1 minute/60 seconds * 180 steps/8 millimeters 
  
}

void loop() {

  if(digitalRead(clockwiseButton) == LOW){ //not 100% working yet
    analogWrite(blue_LED, 255);
    analogWrite(green_LED, 0);
    analogWrite(red_LED, 0);
    stepper.runSpeed();
    Serial.println("clockwise");
  }
  if(digitalRead(button) == LOW){
    analogWrite(green_LED, 255);
    analogWrite(red_LED, 0);
    analogWrite(blue_LED, 0);
    stepper.runSpeed(); // you should step now
    Serial.println("main button");
  }
  else { // pause because you are not at the end yet
    analogWrite(red_LED, 255);
    analogWrite(green_LED, 255);
    analogWrite(blue_LED, 0);
  }
  
}
