#include <Stepper.h>
 
#define STEPS 1024
 
Stepper stepper(STEPS, 8, 10, 9, 11);
 
void setup() {
  pinMode(13,OUTPUT);
  stepper.setSpeed(12);
  analogReference(INTERNAL);

  Serial.begin(9600);
}
 
void loop() {
  digitalWrite(13, HIGH) ;
  int value = analogRead(A0);
  float volt = value * 5.0 / 1024.0;
  float temp = value / 9.31;

  Serial.println(temp);
  stepper.setSpeed(STEPS);
  if (temp > 0){
    stepper.setSpeed(STEPS);
  }
  else{
    stepper.setSpeed(0);
  }
}
