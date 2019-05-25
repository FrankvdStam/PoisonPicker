#define flowIncrement 1

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
bool Contains(CRGB* crgbArray, int size_, CRGB crgb){
  for(int i = 0; i < size_; i++){
    if(crgbArray[i] == crgb){
      return true;
    }
  }
  return false;
}



CRGB GetRandomColor(){
  return colors[random(NUM_COLORS)];
}

//Fills randomColors with randomized colors
void RandomizeColors(){

  //Fill the array with black
  for(int i = 0; i < NUM_LED_SEGMENTS; i++){
    randomColors[i] = CRGB::Black;
  }

  //Fill each element with a random color that has not been used before
  for(int i = 0; i < NUM_LED_SEGMENTS; i++){    
    CRGB color = GetRandomColor();
    while(Contains(randomColors, NUM_LED_SEGMENTS, color)){
       color = GetRandomColor();
    }
    randomColors[i] = color;
  }
}

//sets 8 leds based on an index
void SetSegment(int index, CRGB crgb){
  for(int i = index * LEDS_PER_SEGMENT; i < (index + 1) * LEDS_PER_SEGMENT; i++){
    leds[i] = crgb; 
  }
}




//Create flowing pattern by generating new colors for each led and then approaching them over time
void Flow(){
  //For every segment..
  for(int segment = 0; segment < NUM_LED_SEGMENTS; segment++){
    //Check the first led of this segment against the randomized color
    if(leds[segment * LEDS_PER_SEGMENT] == randomColors[segment]){
      randomColors[segment] = GetRandomColor();
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
      
      CRGB approach = Approach(leds[segment * LEDS_PER_SEGMENT], randomColors[segment]);
/*
      if(segment == 0){
        Serial.print("Approaching, old: ");
        PrintColor(leds[segment * LEDS_PER_SEGMENT]);
        Serial.print(", new: ");
        PrintColor(approach);
        Serial.print("\n");
      }
      */
      SetSegment(segment, approach);
    }
  }
}

CRGB Approach(CRGB source, CRGB destination){
  int r = source.r;
  int g = source.g;
  int b = source.b;
  
  if(source.r != destination.r)
  {
    if(source.r > destination.r)
    {
      r -= flowIncrement;
    }
    else{
      r += flowIncrement;
    }
  }
  
  if(source.g != destination.g)
  {
    if(source.g > destination.g){
      g -= flowIncrement;
    }
    else{
      g += flowIncrement;
    }
  }

  if(source.b != destination.b)
  {
    if(source.b > destination.b){
      b -= flowIncrement;
    }
    else{
      b += flowIncrement;
    }
  }

  return CRGB(r, g, b);
}

