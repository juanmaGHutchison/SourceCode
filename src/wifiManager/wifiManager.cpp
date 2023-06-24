#include "wifiManager.h"

WifiManager::WifiManager(String SSID, String password)
{
    _wifiAPMode.configureConnection(SSID, password);
    _wifiSlaveMode.configureConnection(SSID, password);

    connectToNetwork();
}

bool WifiManager::connectToNetwork()
{
    if (_wifiSlaveMode.connectDevice())
        _wirelessConnection = &_wifiSlaveMode;
    else if (_wifiAPMode.connectDevice())
        _wirelessConnection = &_wifiAPMode;

    return _wirelessConnection->isConnected();
}

bool WifiManager::isConnected()
{
    return _wirelessConnection->isConnected();
}

String WifiManager::getWifiMode()
{
    _wirelessConnection->printMode();
}