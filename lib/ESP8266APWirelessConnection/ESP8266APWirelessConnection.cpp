#include "ESP8266APWirelessConnection.h"

#include <ESP8266WiFi.h>

void ESP8266APWirelessConnection::configureConnection(String SSID, String password)
{
    _SSID = SSID;
    _password = password;
}

bool ESP8266APWirelessConnection::connectDevice()
{
    WiFi.mode(WIFI_AP);
    WiFi.softAP(_SSID, _password);

    return isConnected();
}

String ESP8266APWirelessConnection::printMode()
{
    return (isConnected) ? "Access-Point mode" : "Disconnected";
}

String ESP8266APWirelessConnection::getIPv4()
{
    return WiFi.softAPIP().toString();
}

bool ESP8266APWirelessConnection::isConnected()
{
    return (WiFi.getMode() == WIFI_AP);
}

int ESP8266APWirelessConnection::connectedDevices()
{
    return WiFi.softAPgetStationNum();
}