//LED Strip Setup
#include <FastLED.h>
#define DATA_PIN    3
#define NUM_LEDS    60
#define BRIGHTNESS  127
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define UPDATES_PER_SECOND 100
#define BUTTON 2
CRGB leds[NUM_LEDS];

//Misc Setup
long prevMillis = 0;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(BUTTON, INPUT_PULLUP);
  randomSeed(analogRead(1));
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //set custom RGB colors for the target and normal LED Colors:
  int targetLEDColor[3] =CRGB::Green;
  int normalLEDColor[3] =CRGB::Red;
  int difficulty = 5;

  //function to run the stop-the-light game
  runGame(normalLEDColor[0], normalLEDColor[1], normalLEDColor[2],
          targetLEDColor[0], targetLEDColor[1], targetLEDColor[2], difficulty);

}
