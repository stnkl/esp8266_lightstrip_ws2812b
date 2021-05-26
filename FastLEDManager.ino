
#define NUM_LEDS 6
#define LIGHTSTRIP_PIN 5

#include "FastLEDManager.h"

#include "Animations/color.h"
#include "Animations/rbWave.h"
#include "Animations/rgbWave.h"

#include <ESPEssentials.h>



void setup()
{
  initESPEssentials("Lightstrip");

  FastLEDManager.initialize(NUM_LEDS);
  // FastLEDManager.enableCycleButton(4);
  // FastLEDManager.enablePotentiometer(5);

  FastLEDManager.addLeds<WS2812B, LIGHTSTRIP_PIN, GRB>(FastLEDManager.brightnessCorrectedLeds, NUM_LEDS);

  // FastLEDManager.setDither(0);
  // FastLEDManager.setTemperature(Tungsten100W);
  // FastLEDManager.setBrightness(255);

  FastLEDManager.registerAnimation(new Color("Color"));
  FastLEDManager.registerAnimation(new RbWave("RB Wave"));
  FastLEDManager.registerAnimation(new RgbWave("RGB Wave"));
}

void loop()
{
  handleESPEssentials();
  FastLEDManager.handle();
}
