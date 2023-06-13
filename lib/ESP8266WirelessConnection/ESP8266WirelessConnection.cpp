#include "ESP8266WirelessConnection.h"

#include <ESP8266WiFi.h>
// #include <ESP8266WiFiMulti.h> Testear antes softAP en roaming

void ESP8266WirelessConnection::createConnection(String SSID, String password)
{
    WiFi.mode(WIFI_AP);
}

bool ESP8266WirelessConnection::connectDevice()
{
    WiFi.softAP(_SSID, _password);

    return (isConnected());
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