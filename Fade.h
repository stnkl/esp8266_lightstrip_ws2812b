#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESPEssentials.h>
#include <Ticker.h>
#include <TimeLib.h>

#include "Animation.h"
#include "Config.h"
#include "Hardware.h"
#include "WebSocket.h"

enum FadeMode
{
  NONE = 0,
  ALARM,
  SUNSET
};

extern FadeMode currentFade;

void handleFade();
void startFade(FadeMode fadeMode);
void stopFade();
void fadeTick();

void initTime();
void getSunsetTime();
time_t getNtpTime();
void sendNTPpacket(IPAddress &address);