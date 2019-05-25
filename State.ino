


void GoToIdleState(bool enableLeds){
  if(enableLeds){
    RandomizeColors();    
    for(int i = 0; i < NUM_LED_SEGMENTS; i++){
      SetSegment(i, randomColors[i]);
    }
  }
  else{
    for(int i = 0; i < NUM_LED_SEGMENTS; i++){
      SetSegment(i, CRGB::Black);
    }
  }
}

void GoToRandomizerState(){
  //Start with all leds enabled
  for(int i = 0; i < NUM_LED_SEGMENTS; i++){
    RandomizingState[i] = true;    
  }
  state = STATE_RANDOMIZE;
}


void ReadInput(){
  bool enablePressed = !digitalRead(BUTTON_ENABLE);
/*
  Serial.print("enablePressed: ");
  Serial.print(enablePressed);
  Serial.print(", canPressEnable: ");
  Serial.print(canPressEnable);
  Serial.print("\n");  
  */
  
  if(enablePressed && canPressEnable){
    canPressEnable = false;
    ledsOn = !ledsOn;
    //Serial.println("Going into idle state with toggled led state");
    GoToIdleState(ledsOn);
  }

  if(!enablePressed){
    canPressEnable = true;
  }

  bool randomPressed = !digitalRead(BUTTON_RANDOM);
  
  if(randomPressed && canPressRandom){
    canPressRandom = false;
    GoToRandomizerState();
  }

  if(!randomPressed){
    canPressRandom = true;
  }
}

void Randomize(){
  int interval = 10;
  int cycles = 50;

  //Loop for the amount of segments we have, skipping 1 so that we end up with 1 color in the end
  for(int ledSegment = 0; ledSegment < NUM_LED_SEGMENTS-1; ledSegment++){

    //Loop the amount of cycles 
    for(int cycle = 0; cycle < cycles; cycle++){
      RandomizeColors();    
      for(int j = 0; j < NUM_LED_SEGMENTS; j++){
        if(RandomizingState[j]){
          SetSegment(j, randomColors[j]);
        }
        else{
          SetSegment(j, CRGB::Black);
        }
      }
      FastLED.show();
      delay(interval);
      interval += 1;
      //cycles -= 1;
    }

    //Each cycle we slow down a little AND do less cycles
    //interval += 100;
    cycles -= 10;

    //We also turn off one of the leds
    int index = random(NUM_LED_SEGMENTS);
    while(!RandomizingState[index]){
      index = random(NUM_LED_SEGMENTS);
    }    
    RandomizingState[index] = false;
  }

  Serial.println("RandomizingState");
  //make sure all leds are off when they are supposed to in our exit condition
  for(int j = 0; j < NUM_LED_SEGMENTS; j++){
    Serial.print(j);
    Serial.print(" ");
    Serial.print(RandomizingState[j]);
    Serial.print("\n");
    
    if(!RandomizingState[j]){
      SetSegment(j, CRGB::Black);
    }
  }
  FastLED.show();

  //Blink the victorious led a couple times
  //Find victorious led
  int victoriousIndex = 0;
  for(int i = 0; i < NUM_LED_SEGMENTS; i++){
    if(RandomizingState[i]){
      victoriousIndex = i;
      break;
    }
  }

  delay(300);
  
  for(int i = 0; i < 5; i++){
    SetSegment(victoriousIndex, CRGB::Black);
    FastLED.show();
    delay(200);
    SetSegment(victoriousIndex, randomColors[victoriousIndex]);
    FastLED.show();
    delay(200);
  }
  
  //Idle without changing the current led config
  state = STATE_IDLE;
}
