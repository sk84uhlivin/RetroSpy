#ifndef SNESSpy_h
#define SNESSpy_h

#include "ControllerSpy.h"

class SNESSpy : public ControllerSpy {
    public:
        void loop();
        void writeSerial();
        void debugSerial();
        void updateState();

    private:
        unsigned char rawData[SNES_BITCOUNT_EXT];
	      unsigned char bytesToReturn = SNES_BITCOUNT;
};

#endif
