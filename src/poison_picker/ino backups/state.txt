


void goto_state_idle(bool enableLeds){
  if(enableLeds){
    randomize_colors();    
    for(int i = 0; i < NUM_LED_SEGMENTS; i++){
      set_segment(i, random_colors[i]);
    }
  }
  else{
    for(int i = 0; i < NUM_LED_SEGMENTS; i++){
      set_segment(i, CRGB::Black);
    }
  }
}

void goto_state_randomize(){
  //Start with all leds enabled
  for(int i = 0; i < NUM_LED_SEGMENTS; i++){
    randomizing_state[i] = true;    
  }
  state = STATE_RANDOMIZE;
}


void read_input(){
  bool enable_pressed = !digitalRead(BUTTON_ENABLE);
/*
  Serial.print("enablePressed: ");
  Serial.print(enablePressed);
  Serial.print(", canPressEnable: ");
  Serial.print(canPressEnable);
  Serial.print("\n");  
  */
  
  if(enable_pressed && can_press_enable){
    can_press_enable = false;
    leds_on = !leds_on;
    //Serial.println("Going into idle state with toggled led state");
    goto_state_idle(leds_on);
  }

  if(!enable_pressed){
    can_press_enable = true;
  }

  bool random_pressed = !digitalRead(BUTTON_RANDOM);
  
  if(random_pressed && can_press_random){
    can_press_random = false;
    goto_state_randomize();
  }

  if(!random_pressed){
    can_press_random = true;
  }
}

void randomize(){
  int interval = 10;
  int cycles = 50;

  //Loop for the amount of segments we have, skipping 1 so that we end up with 1 color in the end
  for(int led_segment = 0; led_segment < NUM_LED_SEGMENTS-1; led_segment++){

    //Loop the amount of cycles 
    for(int cycle = 0; cycle < cycles; cycle++){
      randomize_colors();    
      for(int j = 0; j < NUM_LED_SEGMENTS; j++){
        if(randomizing_state[j]){
          set_segment(j, random_colors[j]);
        }
        else{
          set_segment(j, CRGB::Black);
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
    while(!randomizing_state[index]){
      index = random(NUM_LED_SEGMENTS);
    }    
    randomizing_state[index] = false;
  }

  Serial.println("Randomizing_state");
  //make sure all leds are off when they are supposed to in our exit condition
  for(int j = 0; j < NUM_LED_SEGMENTS; j++){
    Serial.print(j);
    Serial.print(" ");
    Serial.print(randomizing_state[j]);
    Serial.print("\n");
    
    if(!randomizing_state[j]){
      set_segment(j, CRGB::Black);
    }
  }
  FastLED.show();

  //Blink the victorious led a couple times
  //Find victorious led
  int victorious_index = 0;
  for(int i = 0; i < NUM_LED_SEGMENTS; i++){
    if(randomizing_state[i]){
      victorious_index = i;
      break;
    }
  }

  delay(300);
  
  for(int i = 0; i < 5; i++){
    set_segment(victorious_index, CRGB::Black);
    FastLED.show();
    delay(200);
    set_segment(victorious_index, random_colors[victorious_index]);
    FastLED.show();
    delay(200);
  }
  
  //Idle without changing the current led config
  state = STATE_IDLE;
}
