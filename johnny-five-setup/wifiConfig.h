#if defined(ARDUINO_SAMD_MKR1000) && !defined(WIFI_101)

#define WIFI_101
#endif
#ifdef WIFI_101
#include <WiFi101.h>
#include "utility/WiFiClientStream.h"
#include "utility/WiFiServerStream.h"
#define WIFI_LIB_INCLUDED
#endif

#ifdef ARDUINO_WIFI_SHIELD
#include <WiFi.h>
#include "utility/WiFiClientStream.h"
#include "utility/WiFiServerStream.h"
#ifdef WIFI_LIB_INCLUDED
#define MULTIPLE_WIFI_LIB_INCLUDES
#else
#define WIFI_LIB_INCLUDED
#endif
#endif

#ifdef ESP8266

#define ESP8266_WIFI
#endif
#ifdef ESP8266_WIFI
#include <ESP8266WiFi.h>
#include "utility/WiFiClientStream.h"
#include "utility/WiFiServerStream.h"
#ifdef WIFI_LIB_INCLUDED
#define MULTIPLE_WIFI_LIB_INCLUDES
#else
#define WIFI_LIB_INCLUDED
#endif
#endif

char ssid[] = "Your WiFi SSID";

#define SERVER_PORT 3030

#define WIFI_WPA_SECURITY

#ifdef WIFI_WPA_SECURITY
char wpa_passphrase[] = "Your WiFi Password";
#endif 

#ifdef WIFI_WEP_SECURITY

byte wep_index = 0;
char wep_key[] = "your_wep_key";
#endif

#ifdef MULTIPLE_WIFI_LIB_INCLUDES
#error "you may not define more than one wifi device type in wifiConfig.h."
#endif

#ifndef WIFI_LIB_INCLUDED
#error "you must define a wifi device type in wifiConfig.h."
#endif

#if ((defined(WIFI_NO_SECURITY) && (defined(WIFI_WEP_SECURITY) || defined(WIFI_WPA_SECURITY))) || (defined(WIFI_WEP_SECURITY) && defined(WIFI_WPA_SECURITY)))
#error "you may not define more than one security type at the same time in wifiConfig.h."
#endif

#if !(defined(WIFI_NO_SECURITY) || defined(WIFI_WEP_SECURITY) || defined(WIFI_WPA_SECURITY))
#error "you must define a wifi security type in wifiConfig.h."
#endif

#if (defined(ESP8266_WIFI) && !(defined(WIFI_NO_SECURITY) || (defined(WIFI_WPA_SECURITY))))
#error "you must choose between WIFI_NO_SECURITY and WIFI_WPA_SECURITY"
#endif

#ifdef SERVER_IP
WiFiClientStream stream(IPAddress(SERVER_IP), SERVER_PORT);
#else
WiFiServerStream stream(SERVER_PORT);
#endif

#if defined(WIFI_101) && !defined(ARDUINO_SAMD_MKR1000)

#define IS_IGNORE_PIN(p) ((p) == 10 || (IS_PIN_SPI(p) && (p) != SS) || (p) == 5 || (p) == 7)

#elif defined(ARDUINO_WIFI_SHIELD) && defined(__AVR_ATmega32U4__)

#define IS_IGNORE_PIN(p) ((IS_PIN_SPI(p) || (p) == 4) || (p) == 7 || (p) == 10 || (p) == 24 || (p) == 28)

#elif defined(ARDUINO_WIFI_SHIELD)

#define IS_IGNORE_PIN(p) ((IS_PIN_SPI(p) || (p) == 4) || (p) == 7 || (p) == 10)

#elif defined(ESP8266_WIFI) && defined(SERIAL_DEBUG)
#define IS_IGNORE_PIN(p) ((p) == 1)

#endif