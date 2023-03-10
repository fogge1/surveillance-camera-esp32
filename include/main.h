#include <WiFiClient.h>
#include <WiFi.h>

#include "OV2640.h"
#include "OV2640Streamer.h"
#include "CRtspSession.h"

#define ENABLE_RTSPSERVER

extern OV2640 cam;

void connectToWifi(void);
void initRTSP(void);