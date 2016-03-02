#include "Arduino.h"
#include "input.h"
#include "output.h"

void setup() {
    Serial.begin(9600);

    input::configure(3, 9, 2, 8);
    output::configure();

    input::read();
}

void loop() {

    input::read();

    if (input::is_alarm_pushed()) {
        Serial.println("alarm enabled");
        output::send_data(3);
    } else if (input::is_right_turn_pushed()) {
        Serial.println("right enabled");
        output::send_data(4);
    } else if (input::is_left_turn_pushed()) {
        Serial.println("left enabled");
        output::send_data(5);
    } else if (input::is_head_light_pushed()) {
        Serial.println("head enabled");
        output::send_data(6);
    } else if (input::is_stop_signal_pushed()) {
        Serial.println("stop enabled");
        output::send_data(7);
    } else if (input::is_rear_light_pushed()) {
        Serial.println("rear enabled");
        output::send_data(8);
    } else if (input::is_fog_light_pushed()) {
        Serial.println("fog enabled");
        output::send_data(9);
    }

}
