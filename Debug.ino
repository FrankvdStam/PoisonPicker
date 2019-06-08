void PrintLeds(){
  Serial.println("Printing all leds:");
  
  for(int i = 0; i < NUM_LEDS; i++){
    Serial.print("leds[");
    Serial.print(i);
    Serial.print("] = ");
    Serial.print(leds[i].r);
    Serial.print(",");    
    Serial.print(leds[i].g);
    Serial.print(",");
    Serial.print(leds[i].b);
    Serial.print("\n");
  }
}

void PrintColor(CRGB crgb){
  Serial.print("(");
  Serial.print(crgb.r);
  Serial.print(",");    
  Serial.print(crgb.g);
  Serial.print(",");
  Serial.print(crgb.b);
  Serial.print(")");
}
