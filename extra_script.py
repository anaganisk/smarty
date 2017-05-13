Import("env")

import os
import configparser

if os.path.isfile('./env.ini'):
    config = configparser.ConfigParser()
    config.read('./env.ini')
    env.Append(
    CPPDEFINES=[
        ('WIFI_SSID', '\\"'+config['VARIABLES']['WIFI_SSID']+'\\"'),
        ('WIFI_PASS', '\\"'+config['VARIABLES']['WIFI_PASS']+'\\"'),
        ('PIXEL_COUNT', config['VARIABLES']['PIXEL_COUNT']),
        ('PIXEL_PIN', config['VARIABLES']['PIXEL_PIN'])
    ])
else:
    print "env.ini file not provided."
    os._exit(1);