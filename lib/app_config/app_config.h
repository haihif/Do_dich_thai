#ifndef APP_CONFIG_H
#define APP_CONFIG_H

/*Device configuration*/
#define DEVICE_ID                                   (String)"D001"

/*Wifi configuration*/
#define WIFI_SSID_CONFIG                            "Admin"
#define WIFI_PASSWORD_CONFIG                        "pwadmin1"
#define WIFI_SSID_MAX_LENGTH                        32
#define WIFI_PASSWORD_MAX_LENGTH                    32

/*MQTT configuration*/
#define MQTT_BROKER_ADDRESS                         "103.1.238.175"
#define MQTT_CLIENT_ID                              "ClientId2"
#define MQTT_USER_NAME                              "test"
#define MQTT_PASSWORD                               "testadmin" 
#define MQTT_DATA_SUB_TOPIC                         (String)"Patient_Data"
#define MQTT_APP_CMD_TOPIC                          "App/command"
#define MQTT_MAIN_TOPIC                             DEVICE_ID

/*Loadcell configuration*/
#define LOADCELL_DOUT_PIN_CFG                       5  
#define LOADCELL_SCK_PIN_CFG                        18
#define MASS_TO_VOLUME_COEFFICIENT                  1015
#define MASS_DEFAULT_FOR_CALIB                      1000    //gam
#define CALIB_COEFFICIENT                           (uint8_t) 500

/*Other peripherals configuration*/
#define BUTTON_PIN                                  5

/*Flash*/
#define WIFI_SSID_CONFIG_FLASH_ADD                  0x00000000
#define WIFI_PASSWORD_CONFIG_FLASH_ADD              0x00000000
#define WIFI_SSID_UPDATE_FLASH_ADD                  0x00000000
#define WIFI_PASSWORD_UPDATE_FLASH_ADD              0x00000000
#define MQTT_BROKER_FLASH_ADD                       0x00000000
#define DEVICE_ID_FLASH_ADD                         0x00000000
#define CALIB_COEFFICIENT_FLASH_ADD                 0x00000000


#endif 
// IP: 103.1.238.175
// Port:1885
// Username: test
// Password: testadmin