#ifndef INPUT_H
#define INPUT_H

#include "Arduino.h"

namespace input {

    void configure(int ploadPin, int clockEnablePin, int clockPin, int dataPin);
    void read();
    boolean is_alarm_pushed();
    boolean is_right_turn_pushed();
    boolean is_left_turn_pushed();
    boolean is_head_light_pushed();
    boolean is_stop_signal_pushed();
    boolean is_rear_light_pushed();
    boolean is_fog_light_pushed();

}

#endif
