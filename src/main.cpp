// Github
// https://github.com/Niewiaro/Arduino-FORBOT-1-OOP
// inspiration
// https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink

#include <Arduino.h> // include Arduino library
#include <Led.h> // include header file of a class

#define TIME 1000 // time of blink
#define DECREASE 100 // decrease interval

Led *pBlinker; // pointer to Led Class Object
int *pTime; // pointer to time

void setup() { // the setup function runs once when you press reset or power the board
  int time= TIME; // set tiem as defined
  pTime= &time; // set pointer to varable

  Led Blinker(time, LED_BUILTIN); // declaration of an object
  pBlinker= &Blinker; // set pointer to object

  pinMode(LED_BUILTIN, OUTPUT); // initialize digital pin LED_BUILTIN as an output.
}

void loop() { // the loop function runs over and over again forever
  pBlinker->blink(); // calling an object's method
  *pTime= (pBlinker->setInterval(*pTime))? TIME: *pTime- DECREASE; // conditional statement
}