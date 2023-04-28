# ESP32-cam streaming
This project uses an ESP32-Camera to record and stream video over Wi-Fi using the RTSP protocol. The project is built using PlatformIO and can be easily installed and configured. The ESP32 sends the IP-address for the video feed to Firebase.
## Related GitHub repos
[API](https://github.com/fogge1/survelliance-camera-server)

[ESP32](https://github.com/fogge1/surveillance-camera-esp32)

[WEB](https://github.com/abbGusjak251/iot-surveillance-web-app)

## Installation PlatformIO
1. Clone project
2. Install PlatformIO (e.g., Visual Studio Code or PlatformIO cli).
3. Build and upload it to a ESP32 camera

## Configuration
* Modify wifi credentials (In the file **"wifi_cred.h"**)
* Modify Firebase credentials
## Usage
Connect to 'rtsp://<ip>:8554/mjpeg/1' (e.g, using vlc or mpv)

## License
This project is licensed under the MIT-license.

