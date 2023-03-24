#include <Arduino.h>
#include <Led.h>

Led::Led(int interval, int pin): time(interval), ledBuiltIn(pin) {} // constructor with initialization list

bool Led::setInterval(int interval) {
    if(interval<= 0)
        return true;
    time= interval;
    return false;
}

void Led::blink() {
    digitalWrite(ledBuiltIn, HIGH);
    delay(time);
    digitalWrite(ledBuiltIn, LOW);
    delay(time);
}
