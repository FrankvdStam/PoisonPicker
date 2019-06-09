#define MIN_MAP_GRAPH 0
#define MAX_MAP_GRAPH 767

#define R_OFFSET 0
#define G_OFFSET 255
#define B_OFFSET 511



int map_graph(int position, int offset)
{
  return position + offset > MAX_MAP_GRAPH ? (position + offset) - MAX_MAP_GRAPH : position + offset;
}

int map_graph_color(int x)
{
  int y = 0;
  if(x < 256)
  {
    y = x;
  }
  else if (x > 255 && x < 512)
  {
    y = 256 - x;
  }
  else{
    y = 0;
  }
  return y;
}


CRGB get_color_from_graph(int position)
{
  int r = map_graph_color(map_graph(position, R_OFFSET));
  int g = map_graph_color(map_graph(position, G_OFFSET));
  int b = map_graph_color(map_graph(position, B_OFFSET));

  return CRGB(r, g, b);
}


int map_analog_read_graph()
{
  return map(analogRead(POTENTIOMETER_BRIGHTNESS), 5, 880, MIN_MAP_GRAPH, MAX_MAP_GRAPH);
}


void set_color_from_potentiometer()
{
  int difference = 5;
  int current_graph_position = map_analog_read_graph();

  if(current_graph_position + difference < previous_graph_position || current_graph_position - difference > previous_graph_position)
  {
    previous_graph_position = current_graph_position;
    
    CRGB color = get_color_from_graph(current_graph_position);
    for(int i = 0; i < NUM_LEDS; i++){
      leds[i] = color;
    }   

    FastLED.show();
    //FastLED.setBrightness(current_brightness);
  }
}
