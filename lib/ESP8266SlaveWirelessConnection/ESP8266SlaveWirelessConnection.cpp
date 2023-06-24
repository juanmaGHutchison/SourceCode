#include "ESP8266SlaveWirelessConnection.h"

#include <ESP8266WiFi.h>

void ESP8266SlaveWirelessConnection::configureConnection(String SSID, String password)
{
    _SSID = SSID;
    _password = password;
}

bool ESP8266SlaveWirelessConnection::connectDevice()
{
    int delayOneSecond = 1000;

    WiFi.begin(_SSID, _password);

    delay(delayOneSecond);

    return isConnected();
}

String ESP8266SlaveWirelessConnection::printMode()
{
    return (isConnected()) ? "Slave-connected mode" : "Disconnected";
}

String ESP8266SlaveWirelessConnection::getIPv4()
{
    return WiFi.localIP().toString();
}

bool ESP8266SlaveWirelessConnection::isConnected()
{
    return (WiFi.status() == WL_CONNECTED);
}

int ESP8266SlaveWirelessConnection::connectedDevices()
{
    return WiFi.scanNetworks();
}