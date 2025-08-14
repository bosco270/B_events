#include "B_events.hpp"

B_events::B_events(uint8_t pin, bool level, unsigned long longPressTime) :
    _pin(pin),
    _level(level),
    _longPressTime(longPressTime)
{
    pinMode(_pin, _level ? INPUT_PULLUP : INPUT);
    _lastState = _level ? HIGH : LOW;
    _pressStartTime = 0;
    _shortPressFlag = false;
    _longPressFlag = false;
    _currentPress = false;
}

void B_events::update() {
    bool currentState = digitalRead(_pin);

    // Detecção de borda de descida (pressionado)
    if (currentState != _lastState && currentState == (_level ? LOW : HIGH)) {
        _pressStartTime = millis();
        _currentPress = true;
    }

    // Detecção de borda de subida (soltado)
    if (currentState != _lastState && currentState == (_level ? HIGH : LOW) && _currentPress) {
        unsigned long pressDuration = millis() - _pressStartTime;

        if (pressDuration < _longPressTime) {
            _shortPressFlag = true;
        }
        else {
            _longPressFlag = true;
        }

        _currentPress = false;
    }

    _lastState = currentState;
}

bool B_events::shortPress() {
    if (_shortPressFlag) {
        _shortPressFlag = false;
        return true;
    }
    return false;
}

bool B_events::longPress() {
    if (_longPressFlag) {
        _longPressFlag = false;
        return true;
    }
    return false;
}

bool B_events::isPressed() {
    return _currentPress;
}
