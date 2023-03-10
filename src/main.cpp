#include <Arduino.h>


#include "wifi_cred.h"
#include "main.h"

OV2640 cam;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  cam.init(esp32cam_aithinker_config);

  connectToWifi();

  initRTSP();
}

void loop() {

}

void connectToWifi(void) {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Print Wifi ssid
  Serial.print("\nConnecting to: ");
  for (int i = 0; ssid[i] != '\0'; i++) {
    Serial.print(ssid[i]);
  }
  Serial.println();

  // If not connected to wifi print .
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Get esp32 ip
  IPAddress ip = WiFi.localIP();

  Serial.printf("\nIP Address: ");
  Serial.println(ip);
}