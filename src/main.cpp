#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    while (!Serial) { ; }  // シリアル待ち
    Serial.println("ESP32-S3 USB-OTG test");
}

void loop() {
    Serial.println("Hello from ESP32-S3!");
    delay(1000);
}
