#ifndef I_WIRELESS_CONNECTION
#define I_WIRELESS_CONNECTION

#include <Arduino.h>

class IWirelessConnection
{
public:
    virtual void createConnection(String SSID, String passwrod) = 0;
    virtual bool connectDevice() = 0;
    virtual String getIPv4() = 0;
    virtual bool isConnected() = 0;
    virtual int connectedDevices() = 0;
};

#endif