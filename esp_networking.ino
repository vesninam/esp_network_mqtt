#include <SpacebrewYun.h>

#include "Config.h"
#include "WIFI.h"
#include "Server.h"
#include "MQTT.h"

void setup(void){
  Serial.begin(115200);
  WIFI_init(false);
  server_init();
  MQTT_init();
  pinMode(led, OUTPUT);
  mqtt_cli.publish("esp8266/state", "hello emqx");
  mqtt_cli.subscribe("esp8266/command");
}

void loop(void){
  server.handleClient();                   
  mqtt_cli.loop();
}
