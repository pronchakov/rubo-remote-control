#include "output.h"

    void output::configure() {
        ::Mirf.cePin=4;
        ::Mirf.csnPin=10;
        ::Mirf.spi = &::MirfHardwareSpi;
        ::Mirf.init();
        ::Mirf.setTADDR((byte *)"serv1");
        ::Mirf.payload = sizeof(uint8_t);
        ::Mirf.channel = 90;
        ::Mirf.config();
    }

    void output::send_data(uint8_t data) {
        ::Mirf.send(&data);
        while(::Mirf.isSending()) {
            continue;
        }
    }