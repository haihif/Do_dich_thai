#include "device_app.h"
#include "app_config.h"
#include  "ArduinoJson.h"

void device_app_init();

DynamicJsonDocument doc(1024);
String buffer;

void device_app_init(){
    ibme_app.device_id = DEVICE_ID;
    ibme_app.patient_data.patient_id = 0;
    ibme_app.patient_data.name = "N.H.Hai";
    ibme_app.patient_data.age = 30;
    ibme_app.patient_data.bed_id = 10;
    ibme_app.patient_data.room_id = 501;
    ibme_app.is_mqtt_data_new = 0;
    String mqtt_pub_string = "{\"patient_id\":\"\",\"name\":,\"age\":,\"bed_id\":,\"room_id\":,\"device_id\":\"\",\"is_mqtt_data_new\":,\"app_cmd\":}";

    deserializeJson(doc, mqtt_pub_string);

    doc["patient_id"] = serialized(ibme_app.patient_data.patient_id);
    doc["name"] = serialized(ibme_app.patient_data.name);
    doc["age"] = ibme_app.patient_data.age;
    doc["bed_id"] = ibme_app.patient_data.bed_id;
    doc["device_id"] = serialized(ibme_app.device_id);
    doc["is_mqtt_data_new"] = ibme_app.is_mqtt_data_new;

    serializeJson(doc, mqtt_pub_string);
    buffer = mqtt_pub_string;
    ibme_app.mqtt_tx_data = buffer;
    Serial.print(ibme_app.mqtt_tx_data);
}

