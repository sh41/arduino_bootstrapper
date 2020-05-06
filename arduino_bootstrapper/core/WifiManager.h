/*
  WifiManager.h - Managing Wifi and OTA
  
  Copyright (C) 2020  Davide Perini
  
  Permission is hereby granted, free of charge, to any person obtaining a copy of 
  this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
  copies of the Software, and to permit persons to whom the Software is 
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in 
  all copies or substantial portions of the Software.
  
  You should have received a copy of the MIT License along with this program.  
  If not, see <https://opensource.org/licenses/MIT/>.
*/

#ifndef _DPSOFTWARE_WIFI_MANAGER_H
#define _DPSOFTWARE_WIFI_MANAGER_H

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include "Helpers.h"
#include "../../include/Secrets.h"
#include "../../include/Configuration.h"


// WiFi Client
extern WiFiClient espClient;

class WifiManager {

  private:
    Helpers helper;

  public:
    void setupWiFi(void (*manageDisconnections)(), void (*manageHardwareButton)());
    void setupOTAUpload();
    int getQuality();
    bool isWifiConfigured(); // check if wifi is correctly configured
    void launchWebServerForOTAConfig(); // if no ssid available, launch web server to get config params via browser

};

#endif