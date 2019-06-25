//--------------------------------------------
// Example for a rotary encoder
// Bart Venneker 2015
//--------------------------------------------
// This example uses a rotary encoder to set the 
// value of a variable (rotaryCount)
//
// See http://youtu.be/KzT3aUE1-0Q for more info (in DUTCH!!)

#define ROTARYPA 2
#define ROTARYPB 4

long rotaryCount = 0;
long lastRotaryCount = 0;

unsigned long previousMillis = 0;
const long interval = 10;  

void setup() {     
  pinMode(ROTARYPA, INPUT);
  pinMode(ROTARYPB, INPUT);  
  
  digitalWrite (ROTARYPA, HIGH);   // enable pull-up
  digitalWrite (ROTARYPB, HIGH);   // enable pull-up
  
  Serial.begin(9600);
  
  attachInterrupt (0, rotaryTurn, RISING);    // interrupt 0 is pin 2, For rotary encoder
}


void loop() {

  if (lastRotaryCount != rotaryCount) {
    Serial.println(rotaryCount);
    lastRotaryCount = rotaryCount;
  }

}

void rotaryTurn()
{
  unsigned long currentMillis = millis();

//debounce
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
  
      // Interrupt Service Routine for a change to Rotary Encoder pin A
        
      if (digitalRead (ROTARYPB)) 
      {
         rotaryCount--;   // Turn it Down!
      }
      else 
      {
         rotaryCount++;   // Turn it Up!
      }
      
      //Serial.write("interrupt: ");
      //Serial.print(rotaryCount);
      //Serial.write("\n");
  }

} 
