#ifndef Hue_h
#define Hue_h

#include "Arduino.h"
#include "Adafruit_NeoPixel.h"

class Hue
{
    public:
        Hue(uint8_t pixelPin, uint8_t pixels);
        bool SetColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t brightness);
        bool StripStart();
        bool StripClear();
    protected:
        uint8_t _pixelPin;
        uint8_t _pixels;
        Adafruit_NeoPixel _strip;
};

#endif