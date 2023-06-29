#include "wifiManager.h"

WifiManager::WifiManager(String SSID, String password)
{
    _wifiAPMode.configureConnection(SSID, password);
    _wifiSlaveMode.configureConnection(SSID, password);
}

bool WifiManager::connectToNetwork()
{
    // Disconnect all WIFI modes
    // This is needed because otherwise it will create an AP and connect to itself
    if (_wifiAPMode.isConnected())
        _wifiAPMode.disconnect();

    // Connect in proper mode
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
    return _wirelessConnection->printMode();
}

WifiManager::~WifiManager()
{
    _wirelessConnection->disconnect();
    delete _wirelessConnection;
}