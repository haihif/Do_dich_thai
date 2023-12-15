#include <Arduino.h>

#include "mqtt_app.h"
#include "display_app.h"
#include "loadcell.h"
#include "device_app.h"
#include "app_config.h"

#include "ArduinoJson.h"

device_app ibme_app;

unsigned long myTime=0;

void setup() {
  Serial.begin(115200);
  DynamicJsonDocument doc(1024);
  display_init();
  display_clear();
  mqtt_app_init();
  display_clear();
  loadcell_init();
  device_app_init();

  myTime = millis();
}

void loop() {
  mqtt_status_checking();
  display_clear_rect(0,0,15,0);
  display_text(0,0,ibme_app.patient_data.name);
  display_clear_rect(0,1,15,1);
  ibme_app.volume = loadcell_get_mass();
  display_num(0,1,ibme_app.volume);
 
  if (millis() - myTime > 5000){
  mqtt_app_client_publish(&ibme_app);
  myTime = millis();
  }
}