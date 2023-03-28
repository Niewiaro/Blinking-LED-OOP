// Github
// https://github.com/Niewiaro/Arduino-FORBOT-1-OOP
// inspiration
// https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink

#include <Arduino.h> // include Arduino library
#include <Led.h> // include header file of a class

#define LED_PIN 8 // pin used for LED
#define TIME 1000 // time of blink
#define PERCENT 20 // decrease interval in %

Led *pBlinker; // pointer to Led Class Object
float *pTime= NULL; // pointer to time

void setup() { // the setup function runs once when you press reset or power the board
  float time= TIME; // set tiem as defined
  pTime= &time; // set pointer to varable

  Led Blinker(time, LED_PIN); // declaration of an object
  pBlinker= &Blinker; // set pointer to object

  pinMode(LED_BUILTIN, OUTPUT); // initialize digital pin LED_BUILTIN as an output (13)
  pinMode(LED_PIN, OUTPUT); // initialize digital pin LED_PIN as an output

  pBlinker->blinks(5, 80, LED_BUILTIN, true);
}

void loop() { // the loop function runs over and over again forever
  *pTime= pBlinker->setInterval((int)*pTime)? TIME: *pTime* (100- PERCENT)/ 100; // conditional statement
  pBlinker->blink(); // calling an object's method
}