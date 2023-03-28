#include <Arduino.h>
#include <Led.h>

Led::Led(int interval, int pin): time(interval), blinkLed(pin) {} // constructor with initialization list

bool Led::setInterval(int interval) {
    if(interval<= 0)
        return true;
    time= interval;
    return false;
}

void Led::blink() {
    digitalWrite(blinkLed, HIGH);
    delay(time);
    digitalWrite(blinkLed, LOW);
    delay(time);
}

void Led::blinks(int quantity, int blinksInterval, int ledBuiltIn, bool stayHigh) {
    for(int i= 0; i< quantity; i++) {
        digitalWrite(ledBuiltIn, HIGH);
        delay(blinksInterval);
        digitalWrite(ledBuiltIn, LOW);
        delay(blinksInterval);
    }

    if(stayHigh)
        digitalWrite(ledBuiltIn, HIGH);
}