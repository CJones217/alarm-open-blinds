
#include <Stepper.h>
const int stepsPerRevolution = 1500;
int  sensorPin  =  A0;     // select the input  pin for  the potentiometer 
int  ledPin  =  13;   // select the pin for  the LED
int  sensorValue =  0;  // variable to  store  the value  coming  from  the sensor

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup()
{
pinMode(ledPin,OUTPUT);
myStepper.setSpeed(20);
Serial.begin(9600);
}
void loop(){
sensorValue =  analogRead(sensorPin);

if(sensorValue>225) {
  delay(250);
  if(sensorValue>225){
    Serial.println(sensorValue,  DEC);
    digitalWrite(ledPin,  HIGH); 
    for(int i=0;i<100;i++){
      myStepper.step(stepsPerRevolution);
      delay(250);
    }
    delay(sensorValue);
  } 
 }

digitalWrite(ledPin,  LOW);
delay(sensorValue);
  
}
