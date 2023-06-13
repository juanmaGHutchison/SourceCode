#include <Arduino.h>

#include "iwirelessConnection.h"
#include <ESP8266WirelessConnection.h>

IWirelessConnection *wirelessConnection = new ESP8266WirelessConnection();

String SSID = "antcolony";
String password = "12345678";

void setup()
{
  wirelessConnection->createConnection(SSID, password);
  wirelessConnection->connectDevice();

  Serial.begin(9600);
}

void loop()
{
  Serial.println("--------------- Connecting ESP8266");
  Serial.print("Connection ");

  if (wirelessConnection->isConnected())
  {
    Serial.println("OK");
    Serial.print("IPv4: ");
    Serial.println(wirelessConnection->getIPv4());
    Serial.println("Connected devices: " + wirelessConnection->connectedDevices());
  }
  else
  {
    Serial.println("FAILED");
  }
}