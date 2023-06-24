#ifndef ESP8266_AP_WIRELESS_CONNECTION
#define ESP8266_AP_WIRELESS_CONNECTION

#include "../../include/iwirelessConnection.h"

class ESP8266APWirelessConnection : public IWirelessConnection
{
public:
    void configureConnection(String SSID, String passwrod);
    bool connectDevice();
    String getIPv4();
    String printMode();
    bool isConnected();
    int connectedDevices();

private:
    String _SSID,
        _password;
};

#endif