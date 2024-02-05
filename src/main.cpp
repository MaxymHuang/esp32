#include <Arduino.h>
#include <WiFiMulti.h>

#define WIFI_SSID "gay wifi"
#define WIFI_PASSWORD "31415926"

WiFiMulti multi;

void setup() {
    // Wait until the serial port is connected
    Serial.begin(115200);
    while (!Serial) {}

    pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
    // Configure the known networks (first one gets higher priority)
    multi.addAP(WIFI_SSID, WIFI_PASSWORD);
    

    // Connect to the first available network
    Serial.println("Looking for a network...");
    if (multi.run() == WL_CONNECTED) {
        Serial.print("Successfully connected to network: ");
        Serial.println(WiFi.SSID());
        digitalWrite(LED_BUILTIN, LOW);
    } else {
        Serial.println("Failed to connect to a WiFi network");
    }
    delay(5000);
}
