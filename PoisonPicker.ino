#include <FastLED.h>

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
bool RandomizingState[NUM_LED_SEGMENTS];
CRGB randomColors[NUM_LED_SEGMENTS];

//int interval = RANDOMIZER_START_INTERVAL;


bool canPressEnable = true;
bool canPressRandom = true;

bool ledsOn = true;
CRGB leds[NUM_LEDS];

//Timers
unsigned long flowInterval = 10;
unsigned long flowPreviousMillis = 0;
bool flowTick = false;

int previous_brightness = 0;


void RunTimers(){
  flowTick = false;
  
  unsigned long currentMillis = millis();

  if (currentMillis - flowPreviousMillis >= flowInterval) {
    flowPreviousMillis = currentMillis;
    flowTick = true;
  }
}






//===============================================================================================================================================
//Initialization
//===============================================================================================================================================


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
  previous_brightness = map(analogRead(POTENTIOMETER_BRIGHTNESS), 0, 900, 0, 255); 
  previous_graph_position = map_analog_read_graph();
  FastLED.addLeds<WS2812, 6, GRB>(leds, NUM_LEDS);
  
  /*
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB::White;
  }
  PrintLeds();
  FastLED.show();
  delay(5000);

  for(int i = 0; i < NUM_LED_SEGMENTS; i++){
      SetSegment(i, CRGB::Red);
  }
  PrintLeds();
  FastLED.show();
  delay(5000);
*/
  FastLED.setBrightness(10);
  randomSeed(analogRead(0));

  GoToIdleState(true);
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
set_color_from_potentiometer();

  /*
 set_brightness();
 
  RunTimers();
  
  
  //Serial.println(state);
  if(state == STATE_IDLE){
    ReadInput();
    if(flowTick){
      Flow();
    }
  }
  
  if(state == STATE_RANDOMIZE){
    Randomize();
  }
  //Serial.println("Showing leds");
  //PrintLeds();
  FastLED.show();  */
}
