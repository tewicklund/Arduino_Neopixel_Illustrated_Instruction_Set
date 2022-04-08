void runGame(int normalred, int normalgreen, int normalblue, int targetred, int targetgreen, int targetblue, int difficulty)
{
  //set the target LED:
  int targetLED = random(0, NUM_LEDS);

  //get the marker light moving:
  int brightLEDPosition = 0;
  while (digitalRead(BUTTON) == 1)
  {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i].r = int(float(normalred) / 10.0);
      leds[i].g = int(float(normalgreen) / 10.0);
      leds[i].b = int(float(normalblue) / 10.0);
    }

    leds[targetLED].r = int(float(targetred) / 10.0);
    leds[targetLED].g = int(float(targetgreen) / 10.0);
    leds[targetLED].b = int(float(targetblue) / 10.0);
    //FastLED.show();
    if (brightLEDPosition != targetLED)
    {
      leds[brightLEDPosition].r = normalred;
      leds[brightLEDPosition].g = normalgreen;
      leds[brightLEDPosition].b = normalblue;
    }
    else
    {
      leds[brightLEDPosition].r = targetred;
      leds[brightLEDPosition].g = targetgreen;
      leds[brightLEDPosition].b = targetblue;
    }
    FastLED.show();
    brightLEDPosition++;
    if (brightLEDPosition >= NUM_LEDS)
    {
      brightLEDPosition = 0;
    }
    int delayLength = int(500.0/float(difficulty));
    while (prevMillis + delayLength > millis() && digitalRead(BUTTON) == 1) {}
    prevMillis = millis();
   
  }

  if (brightLEDPosition-1 == targetLED) {
    //you win!
    for (int j = 0; j < 4; j++)
    {
      for (int i = 0; i < NUM_LEDS; i++)
      {
        leds[i].r = int(float(targetred) / 5.0);
        leds[i].g = int(float(targetgreen) / 5.0);
        leds[i].b = int(float(targetblue) / 5.0);
      }
      FastLED.show();
      delay(500);
      for (int i = 0; i < NUM_LEDS; i++)
      {
        leds[i].r = 0;
        leds[i].g = 0;
        leds[i].b = 0;
      }
      FastLED.show();
      delay(500);
    }

  }
  else
  {
    //you lose!
    for (int j = 0; j < 4; j++)
    {
      for (int i = 0; i < NUM_LEDS; i++)
      {
        leds[i].r = int(float(normalred) / 5.0);
        leds[i].g = int(float(normalgreen) / 5.0);
        leds[i].b = int(float(normalblue) / 5.0);
      }
      FastLED.show();
      delay(500);
      for (int i = 0; i < NUM_LEDS; i++)
      {
        leds[i].r = 0;
        leds[i].g = 0;
        leds[i].b = 0;
      }
      FastLED.show();
      delay(500);
    }

  }
}
