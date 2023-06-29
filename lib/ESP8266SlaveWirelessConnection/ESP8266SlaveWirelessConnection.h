#ifndef ESP8266_SLAVE_WIRELESS_CONNECTION
#define ESP8266_SLAVE_WIRELESS_CONNECTION

#include "../../include/iwirelessConnection.h"

class ESP8266SlaveWirelessConnection : public IWirelessConnection
{
public:
    void configureConnection(String SSID, String passwrod);
    bool connectDevice();
    String getIPv4();
    String printMode();
    bool isConnected();
    bool antNetworkIsAvailable();

    bool disconnect();

private:
    String _SSID,
        _password;
};

#endif