#ifndef ESP8266_WIRELESS_CONNECTION
#define ESP8266_WIRELESS_CONNECTION

#include "../../include/iwirelessConnection.h"

class ESP8266WirelessConnection : public IWirelessConnection
{
public:
    void createConnection(String SSID, String passwrod);
    bool connectDevice();
    String getIPv4();
    bool isConnected();
    int connectedDevices();

private:
    String  _SSID,
            _password;
};

#endif
