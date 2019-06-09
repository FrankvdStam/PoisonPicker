#define FLOW_INCREMENT 1

CRGB colors[] = {
        CRGB::Blue,
        CRGB::Crimson,
        CRGB::Cyan,
        CRGB::Gold,
        CRGB::Lime,
        CRGB::DarkGreen,        
        CRGB::Green,
        CRGB::Lime,
        CRGB::Orange,
        CRGB::OrangeRed,
        CRGB::Orchid,
        CRGB::Purple,
        CRGB::Red,
        CRGB::Turquoise,
        CRGB::Violet,
        CRGB::Yellow,
        CRGB::YellowGreen,
        CRGB::Coral,
        CRGB::DarkRed,
        CRGB::DarkTurquoise,
        CRGB::Brown,
        CRGB::BurlyWood,
        CRGB::DarkGoldenrod,
        CRGB::DodgerBlue,
        CRGB::FireBrick,
        CRGB::Fuchsia,
        CRGB::Goldenrod,
        CRGB::Indigo,
        CRGB::Maroon,
        CRGB::MediumSpringGreen,
        CRGB::OliveDrab,
        CRGB::SaddleBrown,
        CRGB::SteelBlue,
        CRGB::Teal
};


//===============================================================================================================================================
// Color ranomization
//===============================================================================================================================================
bool contains(CRGB* crgb_array, int size_, CRGB crgb){
  for(int i = 0; i < size_; i++){
    if(crgb_array[i] == crgb){
      return true;
    }
  }
  return false;
}



CRGB get_random_color(){
  return colors[random(NUM_COLORS)];
}

//Fills randomColors with randomized colors
void randomize_colors(){

  //Fill the array with black
  for(int i = 0; i < NUM_LED_SEGMENTS; i++){
    random_colors[i] = CRGB::Black;
  }

  //Fill each element with a random color that has not been used before
  for(int i = 0; i < NUM_LED_SEGMENTS; i++){    
    CRGB color = get_random_color();
    while(contains(random_colors, NUM_LED_SEGMENTS, color)){
       color = get_random_color();
    }
    random_colors[i] = color;
  }
}

//sets 8 leds based on an index
void set_segment(int index, CRGB crgb){
  for(int i = index * LEDS_PER_SEGMENT; i < (index + 1) * LEDS_PER_SEGMENT; i++){
    leds[i] = crgb; 
  }
}




CRGB approach(CRGB source, CRGB destination){
  int r = source.r;
  int g = source.g;
  int b = source.b;
  
  if(source.r != destination.r)
  {
    if(source.r > destination.r)
    {
      r -= FLOW_INCREMENT;
    }
    else{
      r += FLOW_INCREMENT;
    }
  }
  
  if(source.g != destination.g)
  {
    if(source.g > destination.g){
      g -= FLOW_INCREMENT;
    }
    else{
      g += FLOW_INCREMENT;
    }
  }

  if(source.b != destination.b)
  {
    if(source.b > destination.b){
      b -= FLOW_INCREMENT;
    }
    else{
      b += FLOW_INCREMENT;
    }
  }

  return CRGB(r, g, b);
}





//Create flowing pattern by generating new colors for each led and then approaching them over time
void flow(){
  //For every segment..
  for(int segment = 0; segment < NUM_LED_SEGMENTS; segment++){
    //Check the first led of this segment against the randomized color
    if(leds[segment * LEDS_PER_SEGMENT] == random_colors[segment]){
      random_colors[segment] = get_random_color();
/*
      if(segment == 0){
        Serial.print("Generated a new color for segment ");
        Serial.print(segment);
        Serial.print(": ");
        PrintColor(randomColors[segment]);
        Serial.print("\n");
      }*/
    }
    else
    {
      
      CRGB approach_color = approach(leds[segment * LEDS_PER_SEGMENT], random_colors[segment]);
/*
      if(segment == 0){
        Serial.print("Approaching, old: ");
        PrintColor(leds[segment * LEDS_PER_SEGMENT]);
        Serial.print(", new: ");
        PrintColor(approach);
        Serial.print("\n");
      }
      */
      set_segment(segment, approach_color);
    }
  }
}





void torture()
{
  while(true){
    for(int i = 0; i < NUM_LEDS; i++){
      leds[i] = CRGB(random(256),random(256),random(256));
    }
    FastLED.show();
  }
}
