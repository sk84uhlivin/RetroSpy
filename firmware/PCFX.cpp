#include "PCFX.h"

void PCFXSpy::loop() {
    noInterrupts();
    updateState();
    interrupts();
#if !defined(DEBUG)
    writeSerial();
#else
    debugSerial();
#endif
}

void PCFXSpy::updateState() {
    unsigned char bits = PCFX_BITCOUNT;
    unsigned char *rawDataPtr = rawData;

    WAIT_FALLING_EDGE(PCFX_LATCH);

    do {
        WAIT_FALLING_EDGE(PCFX_CLOCK);
        *rawDataPtr = !PIN_READ(PCFX_DATA);
        ++rawDataPtr;
    }
    while(--bits > 0);
}

void PCFXSpy::writeSerial() {
    sendRawData(rawData, 0, PCFX_BITCOUNT);
}

void PCFXSpy::debugSerial() {
    sendRawDataDebug(rawData, 0, PCFX_BITCOUNT);
}
