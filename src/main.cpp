#include <Arduino.h>

#include "wifiManager/wifiManager.h"

String SSID = "antcolony";
String password = ""; // 12345678

WifiManager wifiConnection(SSID, password);

void setup()
{
  Serial.begin(9600);
  wifiConnection.connectToNetwork();
}

void loop()
{
  if (!wifiConnection.isConnected())
  {
    wifiConnection.connectToNetwork();
  }
  else
  {
    Serial.println("------ Device mode: " + wifiConnection.getWifiMode());
  }
}