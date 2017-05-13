# Smarty [![Build Status](https://travis-ci.org/anaganisk/smarty.png)](https://travis-ci.org/anaganisk/smarty)
*under development*

Smarty is a simple home automation interface based on ESP8266(ESP-01) and Arduino framework. You can tweak platform settings to support other ESP8266 modules.

### Features
    -   Connects to home network
    -   Hue smart lighting(Inspired by Philips Hue)

### Future
    -   OTA updates
    -   Authentication
    -   Temperature
    -   Motion Sensor

### Modules
__Hue__ :
Hue supports Adafruit NeoPixel WS2812 led Strip for now. You can tweak Hue.cpp to support other led strips. 


### How to use
 **requirements**
 1. python 2.7
 2. platformio
 3. esp8266

create env.ini file in project root and replace the values as required.

```ini
[VARIABLES]
    ; home network credentials
    WIFI_SSID = ssid
    WIFI_PASS = password
    ; neopixel led configuration
    PIXEL_COUNT = 8 ;total leds
    PIXEL_PIN = 2 ;GPIO PIN connected to NEOPIXEL strip
```
### License MIT
refer [LICENSE.md](/LICENSE.md) for details