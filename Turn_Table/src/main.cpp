#include <Arduino.h>

//L293D
//Motor
const int motorPin1  = 5;  // Pin 14 of L293
const int motorPin2  = 6;  // Pin 10 of L293

const int buttonPin = 2;    // Pin for the pushbutton
int buttonState = 0;        // sets the buttonstate to 0

unsigned long previousMillis = 0;        // will store last time button was pushed
const long interval = 1000;           // duration of spinning motor


void setup(){
 
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(buttonPin, INPUT);
    
    //Motor Control - Motor A: motorPin1,motorpin2

   // //This code  will turn Motor A clockwise for 2 sec.
   // digitalWrite(motorPin1, HIGH);
   // digitalWrite(motorPin2, LOW);
   // digitalWrite(motorPin3, LOW);
   // digitalWrite(motorPin4, LOW);
   // delay(2000); 
}


void loop(){
   unsigned long currentMillis = millis();
   buttonState = digitalRead(buttonPin);
        if (buttonState == HIGH) {
                if (currentMillis - previousMillis >= interval) {
                        previousMillis = currentMillis;
                        analogWrite(motorPin1, 50);
                        analogWrite(motorPin2, 0);
                }
                else{
                        analogWrite(motorPin1, 0);
                        analogWrite(motorPin2, 0);
                }
        }
        else{
        }
}      
