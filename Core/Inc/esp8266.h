/*
 * esp8266.h
 *
 *  Created on: Dec 30, 2024
 *      Author: Admin
 */

#ifndef INC_ESP8266_H_
#define INC_ESP8266_H_

// AT commands to interact with ESP8266
void ESP8266_Init(void);          // Initialize ESP8266 and check response
void ESP8266_ConnectWiFi(void);   // Connect ESP8266 to Wi-Fi
void ESP8266_SendGetRequest(char *url); // Send GET request to the server

#endif /* INC_ESP8266_H_ */
