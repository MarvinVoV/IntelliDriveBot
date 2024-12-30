/*
 * wifi.c
 *
 *  Created on: Dec 30, 2024
 *      Author: Admin
 */


#include "wifi.h"
#include "esp8266.h"

// Initialize the Wi-Fi module and connect to the network
void WiFi_Init(void) {
    ESP8266_Init();       // Initialize ESP8266
    ESP8266_ConnectWiFi(); // Connect to Wi-Fi network
}

// Request data from the specified URL
void WiFi_RequestData(char *url) {
    ESP8266_SendGetRequest(url); // Send GET request and receive data
}
