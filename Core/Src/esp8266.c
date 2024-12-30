/*
 * esp8266.c
 *
 *  Created on: Dec 30, 2024
 *      Author: Admin
 */


#include "esp8266.h"
#include "uart.h"
#include "string.h"
#include "stdio.h"

// Initialize ESP8266 and check if it's responsive
void ESP8266_Init(void) {
    // Send "AT" command to check if the module is working
    sprintf(uart_tx_buffer, "AT\r\n");
    UART_Transmit(uart_tx_buffer, strlen(uart_tx_buffer));

    // Wait for response and check if ESP responds with OK
    UART_Receive();
    if (strstr(uart_rx_buffer, "OK") != NULL) {
        // Successful connection, we can proceed
        sprintf(uart_tx_buffer, "AT+RST\r\n"); // Reset the module
        UART_Transmit(uart_tx_buffer, strlen(uart_tx_buffer));
    }
}

// Connect the ESP8266 to a Wi-Fi network
void ESP8266_ConnectWiFi(void) {
    // Send Wi-Fi connection command (replace with your SSID and password)
    sprintf(uart_tx_buffer, "AT+CWJAP=\"YourSSID\",\"YourPassword\"\r\n");
    UART_Transmit(uart_tx_buffer, strlen(uart_tx_buffer));

    // Wait for connection response (e.g., "WIFI GOT IP")
    UART_Receive();
    if (strstr(uart_rx_buffer, "WIFI GOT IP") != NULL) {
        // Wi-Fi connected successfully
    }
}

// Send a GET request to a URL (e.g., for JSON data)
void ESP8266_SendGetRequest(char *url) {
    // AT+CIPSTART="TCP","<server_ip>",<port> (e.g., AT+CIPSTART="TCP","192.168.1.100",80)
    sprintf(uart_tx_buffer, "AT+CIPSTART=\"TCP\",\"%s\",80\r\n", url);
    UART_Transmit(uart_tx_buffer, strlen(uart_tx_buffer));

    // Wait for connection response
    UART_Receive();
    if (strstr(uart_rx_buffer, "CONNECT") != NULL) {
        // Connection successful, send GET request
        sprintf(uart_tx_buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", url);
        UART_Transmit(uart_tx_buffer, strlen(uart_tx_buffer));

        // Wait for response (the JSON data)
        UART_Receive();
        // Process the JSON or simply forward it to the computer
        UART_Transmit(uart_rx_buffer, strlen(uart_rx_buffer));
    }
}
