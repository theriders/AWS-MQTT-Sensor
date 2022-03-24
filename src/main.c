
#include "nvs_flash.h"
// MQTT Stuff
#include "mqtt.h"
// Host
#include "host.h"
// Debug
#include "esp_log.h"

const char* Wifi_SSID = "ATTMfTv66a";
const char* Wifi_Pass = "wfd97s#fg+gx";

// AWS Stuff
#define CONFIG_AWS_IOT_MQTT_TX_BUF_LEN 100
#define CONFIG_AWS_IOT_MQTT_RX_BUF_LEN 100
#define CONFIG_AWS_IOT_MQTT_NUM_SUBSCRIBE_HANDLERS 4

const char* Mqtt_Broker_Url  = "mqtts://a2m733ysclyt2b-ats.iot.us-east-2.amazonaws.com";
// Host object
host_t host;

void app_main(void)
{
  //Initialize NVS
  esp_err_t ret = nvs_flash_init();
  if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
    ESP_ERROR_CHECK(nvs_flash_erase());
    ret = nvs_flash_init();
  }
  ESP_ERROR_CHECK(ret);

  host.wifi_creds.Wifi_SSID = Wifi_SSID;
  host.wifi_creds.Wifi_Pass = Wifi_Pass;

  init_host(&host);

//   mqtt_app_start(Mqtt_Broker_Url);
}
