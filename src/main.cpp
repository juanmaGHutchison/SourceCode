#include <Arduino.h>

#include "wifiManager/wifiManager.h"
#include <sMQTTBroker.h>

#define PORT 1883


String SSID = "antcolony";
String password = ""; // 12345678

WifiManager wifiConnection(SSID, password);
sMQTTBroker broker;

void setup()
{
  Serial.begin(9600);
  wifiConnection.connectToNetwork();

  broker.init(PORT, true);
}

void loop()
{
  broker.update();
  if (!wifiConnection.isConnected())
  {
    wifiConnection.connectToNetwork();
  }
  else
  {
    Serial.println("------ Device mode: " + wifiConnection.getWifiMode());
  }
}