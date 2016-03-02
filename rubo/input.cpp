#include "input.h"

namespace input {

    int ploadPin, clockEnablePin, clockPin, dataPin;

    unsigned int old_value = 0b11111111;
    unsigned int new_value = 0b11111111;

    void configure(int ploadPin, int clockEnablePin, int clockPin, int dataPin) {
        input::ploadPin = ploadPin;
        input::clockEnablePin = clockEnablePin;
        input::clockPin = clockPin;
        input::dataPin = dataPin;

        pinMode(ploadPin, OUTPUT);
        pinMode(clockEnablePin, OUTPUT);
        pinMode(clockPin, OUTPUT);
        pinMode(dataPin, INPUT);

        digitalWrite(clockPin, LOW);
        digitalWrite(ploadPin, HIGH);
    }

    void read() {
        old_value = new_value;

        digitalWrite(clockEnablePin, HIGH);
        digitalWrite(ploadPin, LOW);
        delayMicroseconds(5);
        digitalWrite(ploadPin, HIGH);
        digitalWrite(clockEnablePin, LOW);

        new_value = shiftIn(dataPin, clockPin, LSBFIRST);
    }

    boolean is_pushed(int bit) {
        boolean old_bit = (old_value >> bit) & 1;
        boolean new_bit = (new_value >> bit) & 1;
        return !new_bit && old_bit;
    }

    boolean is_alarm_pushed() {
        return false; // TODO: Implement
    }

    boolean is_right_turn_pushed() {
        return is_pushed(6);
    }

    boolean is_left_turn_pushed() {
        return is_pushed(5);
    }

    boolean is_head_light_pushed() {
        return is_pushed(4);
    }

    boolean is_stop_signal_pushed() {
        return is_pushed(3);
    }

    boolean is_rear_light_pushed() {
        return is_pushed(2);
    }

    boolean is_fog_light_pushed() {
        return is_pushed(0);
    }

}