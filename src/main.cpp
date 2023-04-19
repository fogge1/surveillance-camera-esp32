#include <Arduino.h>
#include "wifi_cred.h"
#include "main.h"
#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#define FIREBASE_API_KEY ""
#define FIREBASE_DB "" 

OV2640 cam;
IPAddress ip;
// Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

bool signupOK = false;

void setup() {
  //ESP.restart();
  // put your setup code here, to run once:
  Serial.begin(115200);

  cam.init(esp32cam_aithinker_config);
  connectToWifi();
  initRTSP();

  config.api_key = FIREBASE_API_KEY;
  config.database_url = FIREBASE_DB;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("ok");
    signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  config.token_status_callback = tokenStatusCallback;

  Firebase.begin(&config, &auth);
  
  Firebase.reconnectWiFi(true);

  if (Firebase.ready() && signupOK && WiFi.status() == WL_CONNECTED) {
    String address = "rtsp://" + String(ip[0]) + '.' + \
    String(ip[1]) + '.' +\
    String(ip[2]) + '.' +\
    String(ip[3]);
    Firebase.RTDB.setString(&fbdo, "ips/cam32", address);
  }
  
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
  ip = WiFi.localIP();


  Serial.printf("\nIP Address: ");
  Serial.println(ip);
}