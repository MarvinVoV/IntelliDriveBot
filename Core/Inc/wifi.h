/*
 * wifi.h
 *
 *  Created on: Dec 30, 2024
 *      Author: Admin
 */

#ifndef INC_WIFI_H_
#define INC_WIFI_H_


void WiFi_Init(void);          // Initialize Wi-Fi and connect
void WiFi_RequestData(char *url); // Send GET request to fetch data

#endif /* INC_WIFI_H_ */
