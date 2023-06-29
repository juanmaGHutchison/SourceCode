#include "ESP8266SlaveWirelessConnection.h"

#include <ESP8266WiFi.h>

void ESP8266SlaveWirelessConnection::configureConnection(String SSID, String password)
{
    _SSID = SSID;
    _password = password;
}

bool ESP8266SlaveWirelessConnection::connectDevice()
{
    int delaySeconds = 1,
        maxAttempts = 7;

    WiFi.begin(_SSID, _password);

    for (int attempts = 0; attempts < maxAttempts && !isConnected(); ++attempts)
        delay(delaySeconds * 1000);

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

bool ESP8266SlaveWirelessConnection::antNetworkIsAvailable()
{
    Serial.println("ESP8266SlaveWirelessConnection::antNetworkIsAvailable()");
    bool antNetworkExists = (isConnected());
    int networks = WiFi.scanNetworks();

    for (int i = 0; i < networks && !antNetworkExists; ++i)
    {
        antNetworkExists = (WiFi.SSID(i) == _SSID && WiFi.RSSI(i) >= (int32_t)-70);
        Serial.println((int32_t)WiFi.RSSI(i) + " dbm");
    }

    Serial.println((antNetworkExists) ? "ANE: OK" : "ANE: NO");
    Serial.println((isConnected()) ? "IC: OK" : "IC: NO");
    Serial.println((WiFi.status() == WL_CONNECTED) ? "POSI" : "PONO");

    return antNetworkExists;
}

bool ESP8266SlaveWirelessConnection::disconnect()
{
    return WiFi.disconnect();
}