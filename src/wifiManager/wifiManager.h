#ifndef WIFI_MANAGER
#define WIFI_MANAGER

#include <Arduino.h>

#include "iwirelessConnection.h"
#include <ESP8266SlaveWirelessConnection.h>
#include <ESP8266APWirelessConnection.h>

class WifiManager
{
public:
    WifiManager(String SSID, String password);
    bool connectToNetwork();
    bool isConnected();
    String getWifiMode();

private:
    IWirelessConnection *_wirelessConnection;

    ESP8266APWirelessConnection _wifiAPMode;
    ESP8266SlaveWirelessConnection _wifiSlaveMode;
};

#endif
