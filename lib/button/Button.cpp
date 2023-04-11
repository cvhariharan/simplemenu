#include "Arduino.h"
#include "Button.h"

Button::Button(int pin) {
    pinMode(pin, INPUT);
    _pin = pin;
    _lastUpdate = 0;
    _numClicks = 0;
    _lastState = 0;
}

int Button::update() {
    unsigned long now = millis();
    int state = digitalRead(_pin);

    // If button is pressed for more than the debounce delay and the previous state was off
    // consider it as a stable button press and store the state
    if(state != _lastState && (now - _lastUpdate) > DEBOUNCE_DELAY && state) {
        _lastUpdate = now;
        _lastState = state;
    }

    // If button is released for more than the debounce delay (by comparing to previous state which should be on)
    // consider it as a stable button release, press and release is considered a click, increment counter
    if(state != _lastState && (now - _lastUpdate) > DEBOUNCE_DELAY && !state) {
        _lastUpdate = now;
        _lastState = state;
        _numClicks++;
    }


    // If more than CLICK_INTERVAL time has passed between the last button press/release
    // return the clicks
    if((now - _lastUpdate) > CLICK_INTERVAL && _numClicks > 0) {
        int clicks = _numClicks;
        _numClicks = 0;
        return clicks;
    }

    return -1;
}