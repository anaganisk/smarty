#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Hue.h>

Hue::Hue(uint8_t pixelPin, uint8_t pixels)
{
    _pixelPin = pixelPin; 
    _pixels = pixels;
    _strip = Adafruit_NeoPixel(_pixels, _pixelPin, NEO_GRB + NEO_KHZ800);
}

bool Hue::SetColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t brightness)
{
    for(int i = 0; i < _strip.numPixels(); i++){
        _strip.setPixelColor(i, _strip.Color(
        brightness * red / 255,
        brightness * green / 255, 
        brightness * blue / 255));
        _strip.show();
        delay(20);
    }

    return true;
}

bool Hue::StripStart()
{
    _strip.begin();
    _strip.clear();
    _strip.setBrightness(255);
    for(int i = 0; i < _strip.numPixels() / 2; i++){
        _strip.setPixelColor(i, _strip.Color(0, i * 30, i + 60));
        _strip.show();
        delay(500);
    }
    for(int i = _strip.numPixels() - 1; i >= _strip.numPixels() / 2; i--){
        _strip.setPixelColor(i, _strip.Color(i * 30, i + 60, 0));
        _strip.show();
        delay(500);
    }

    return true;
}

bool Hue::StripClear()
{
    _strip.clear();
}