#include "src/FastLED/FastLED.h"
#include "src/pplib/pplib.h"
#include "led_controller.h"

//===============================================================================================================================================
//Definitions
//===============================================================================================================================================

#define NUM_LED_SEGMENTS 9
#define LEDS_PER_SEGMENT 8
#define NUM_LEDS 72

//potentiometer for variable brightness
#define POTENTIOMETER_BRIGHTNESS A0

#define BUTTON_ENABLE 5
#define BUTTON_RANDOM 4

#define NUM_COLORS 33

//states
#define STATE_IDLE      0
#define STATE_RANDOMIZE 1

//randomizer
#define RANDOMIZER_START_INTERVAL 10



int previous_graph_position;

//===============================================================================================================================================
//Variables
//===============================================================================================================================================

int state = STATE_IDLE;

//Randomization related
bool randomizing_state[NUM_LED_SEGMENTS];
CRGB random_colors[NUM_LED_SEGMENTS];

//int interval = RANDOMIZER_START_INTERVAL;


bool can_press_enable = true;
bool can_press_random = true;

bool leds_on = true;
CRGB leds[NUM_LEDS];

//Timers
unsigned long flow_interval = 10;
unsigned long flow_previous_millis = 0;
bool flow_tick = false;

int previous_brightness = 0;


void run_timers(){
  flow_tick = false;
  
  unsigned long current_millis = millis();

  if (current_millis - flow_previous_millis >= flow_interval) {
    flow_previous_millis = current_millis;
    flow_tick = true;
  }
}






//===============================================================================================================================================
//Initialization
//===============================================================================================================================================

class test{
public:
	test(){
	}
};

void setup() {
  Serial.begin(9600);
  Serial.println("Running setup");
  Serial.print("Segments:");
  Serial.print(NUM_LED_SEGMENTS);
  Serial.print("\n");
  Serial.print("Leds:");
  Serial.print(NUM_LEDS);
  Serial.print("\n");

  pinMode(BUTTON_ENABLE, INPUT_PULLUP);
  pinMode(BUTTON_RANDOM, INPUT_PULLUP);
  pinMode(POTENTIOMETER_BRIGHTNESS, INPUT);
  


  test t;


  led_controller led_c;
  led_c.clear();
  led_c.set_segment(0, CRGB::White);
  led_c.set_segment(1, CRGB::Red);
  led_c.show();
  delay(1000);









  previous_brightness = map(analogRead(POTENTIOMETER_BRIGHTNESS), 0, 900, 0, 255); 
  previous_graph_position = map_analog_read_graph();
  
  FastLED.addLeds<WS2812, 6, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(10);
  randomSeed(analogRead(0));

  goto_state_idle(true);
}



void set_brightness()
{  
  int difference = 5;
  int current_brightness = map(analogRead(POTENTIOMETER_BRIGHTNESS), 0, 900, 0, 255);

  if(current_brightness + difference < previous_brightness || current_brightness - difference > previous_brightness)
  {
    previous_brightness = current_brightness;
    FastLED.setBrightness(current_brightness);
  }
}


//===============================================================================================================================================
//State machine
//===============================================================================================================================================


void loop() {
 //set_color_from_potentiometer();
 //set_brightness();
 
  run_timers();
  
  
  //Serial.println(state);
  if(state == STATE_IDLE){
    read_input();
    if(flow_tick){
      flow();
    }
  }
  
  if(state == STATE_RANDOMIZE){
    randomize();
  }
  //Serial.println(state);
  //Serial.println("Showing leds");
  //PrintLeds();
  FastLED.show();  
}
