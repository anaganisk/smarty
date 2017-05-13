#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <FS.h>

// #include <Routes.h>
#include <Hue.h>

const char* ssid = WIFI_SSID;
const char* password = WIFI_PASS;

ESP8266WebServer server(80);  // smarty webserver
Hue hue(PIXEL_PIN, PIXEL_COUNT); //smarty hue

void setup(void){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Searching for");
  Serial.println(ssid);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("smarty")) {
    Serial.println("MDNS: smarty.local");
  }

  //  routes
  server.on("/rgb-strip", handleRgbStrip);
  server.on("/", handleRoot);
  server.onNotFound(handleNotFound);

  server.begin();
  SPIFFS.begin();
  Serial.println("HTTP server started");
  hue.StripStart();
}

void loop(void){
  server.handleClient();
}

void handleRoot() {
  File file = SPIFFS.open("/hue.html", "r");
  server.streamFile(file, "text/html");
  file.close();
}

void handleNotFound(){
  String message = "<h1 style=\"color:red\">Unsupported</h1>";
  server.send(404, "text/html", message);
}

void handleRgbStrip() {
  if (server.hasArg("r") &&
    server.hasArg("g") &&
    server.hasArg("b") &&
    server.hasArg("br")) {
    hue.SetColor(server.arg("r").toInt(),
      server.arg("g").toInt(),
      server.arg("b").toInt(),
      server.arg("br").toInt());
    server.send(200, "text/json", "{ \"status\": true}");
  } else {
    String message = "requires 'r, g, b and br' < 255' params";
    server.send(502, "text/json", "{ \"status\": false, \"message\":" + message +"}");
  }
};
