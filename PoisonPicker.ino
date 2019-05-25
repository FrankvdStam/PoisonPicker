#include <FastLED.h>

//===============================================================================================================================================
//Definitions
//===============================================================================================================================================

#define NUM_LED_SEGMENTS 5
#define LEDS_PER_SEGMENT 8
#define NUM_LEDS 40

#define BUTTON_ENABLE 5
#define BUTTON_RANDOM 4

#define NUM_COLORS 33

//states
#define STATE_IDLE      0
#define STATE_RANDOMIZE 1

//randomizer
#define RANDOMIZER_START_INTERVAL 10

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
  FastLED.setBrightness(50);
  randomSeed(analogRead(0));

  GoToIdleState(true);
}






//===============================================================================================================================================
//State machine
//===============================================================================================================================================

void loop() {
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
  FastLED.show();  
}




