#ifndef OUTPUT_H
#define OUTPUT_H

#include "Arduino.h"
#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

namespace output {
    void configure();
    void send_data(uint8_t data);
}

#endif