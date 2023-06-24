#include "ESP8266WirelessConnection.h"

#include <ESP8266WiFi.h>
// #include <ESP8266WiFiMulti.h> Testear antes softAP en roaming

void ESP8266WirelessConnection::createConnection(String SSID, String password)
{
    // Allocate Wifi settings
    _SSID = SSID;
    _password = password;
    // Set ESP8266 as access point
    WiFi.mode(WIFI_AP);
}

bool ESP8266WirelessConnection::connectDevice()
{
    WiFi.softAP(_SSID, _password);

    return (WiFi.getMode() == WIFI_AP);
}

String ESP8266WirelessConnection::getIPv4()
{
    return WiFi.softAPIP().toString();
}

bool ESP8266WirelessConnection::isConnected()
{
    return (WiFi.status() == WL_CONNECTED);
}

int ESP8266WirelessConnection::connectedDevices()
{
    return WiFi.softAPgetStationNum();
}