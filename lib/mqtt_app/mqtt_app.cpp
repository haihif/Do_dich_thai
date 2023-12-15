#include <Arduino.h>
// #include <ESP8266WiFi.h>
#include <MQTT.h>
#include "mqtt_app.h"
#include "LiquidCrystal_I2C.h"
#include "app_config.h"
#include "display_app.h"
#include "device_app.h"
#include <SPI.h>
#include <WiFi.h>

const char ssid[] = WIFI_SSID_CONFIG;
const char pass[] = WIFI_PASSWORD_CONFIG;

WiFiClient net;
MQTTClient client;

static char buffer[1024] = "default";

void mqtt_app_init();
void mqtt_app_client_publish(device_app* p_app);
void mqtt_app_client_subcribe(device_app* p_app);

void wifi_connect(){
  Serial.print("Wifi...");
  display_text(0,0,"WIFI...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.print("\nWifi connected!");
  display_text(0,0,"WIFI connected!");
}

void mqtt_connect(){
  Serial.print("\nMQTT broker...");
  display_text(0,1,"MQTT broker...");
  while (!client.connect(MQTT_CLIENT_ID, MQTT_USER_NAME, MQTT_PASSWORD)) {
    Serial.print(".");
    delay(300);
  }
  Serial.print("\nMQTT connected!");
  display_text(0,1,"MQTT connected!");
}
void connect() {
  wifi_connect();
  delay(100);
  mqtt_connect();
  client.subscribe(MQTT_MAIN_TOPIC + "/" + MQTT_DATA_SUB_TOPIC);
  client.subscribe(MQTT_MAIN_TOPIC + "/" + MQTT_APP_CMD_TOPIC);
}

void message_received_callback(String &topic, String &payload) {
  Serial.println(topic + " - " + payload);
  if (topic == (MQTT_MAIN_TOPIC + "/" + MQTT_DATA_SUB_TOPIC))
    ibme_app.mqtt_rx_data = payload;
  else if (topic == MQTT_MAIN_TOPIC + "/" + MQTT_APP_CMD_TOPIC){
    if (payload == "1"){

    }

  }

}

void mqtt_app_init(){
  WiFi.begin(ssid, pass);
  client.begin(MQTT_BROKER_ADDRESS, net);
  client.setHost("103.1.238.175", 1885);
  client.onMessage(message_received_callback);
  connect();
}

void mqtt_app_client_publish(device_app* p_app){
  sprintf(buffer, "%d", p_app->volume); 
  client.publish(MQTT_MAIN_TOPIC + "/" + MQTT_DATA_SUB_TOPIC, buffer);
}

void mqtt_app_client_subcribe(device_app* p_app){

}

void mqtt_status_checking(){
  client.loop();
  delay(10);
  if (!client.connected()){
    connect();
  }
}

