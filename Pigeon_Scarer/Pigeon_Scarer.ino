
// Added Motion Sensor

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <BlynkSimpleEsp8266.h>

BlynkTimer timer;
// Your WiFi credentials.

char auth[] = "575b164c97e04d2992b73d9beedaa519";
char ssid[] = "Gimp";
char pass[] = "FC7KUNPX";

// constants won't change. They're used here to set pin numbers:
const int Motion_Sensor_Pin = D1;     // the number of the pushbutton pin
const int led_Pin =  D5;      // the number of the LED pin

// variables will change:

int Motion_Sensor_state = 0;         // variable for reading the Motion-Sensor status 

void setup() {
  pinMode(led_Pin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Motion_Sensor_Pin, INPUT);
  Serial.begin(115200);
  Serial.println("Booting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
    Blynk.begin(auth, ssid, pass);
    
  }
  
  
  
  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH)
      type = "sketch";
    else // U_SPIFFS
      type = "filesystem";

    // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();
  

}

void loop() {
  ArduinoOTA.handle();
  Motion_Sensor();
}

void Motion_Sensor(){
    // read the state of the  value:
  Motion_Sensor_state = digitalRead(Motion_Sensor_Pin);
  Serial.println(Motion_Sensor_state);

  // check if the Motion-Sensor as detected any movement. If it as, the buttonState is HIGH:
  if (Motion_Sensor_state == LOW) {
    // turn LED on:
    digitalWrite(led_Pin, HIGH);
    digitalWrite(LED_BUILTIN, LOW);
  }
  else if (Motion_Sensor_state == HIGH){
    // turn LED off:
    digitalWrite(led_Pin, LOW);
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
