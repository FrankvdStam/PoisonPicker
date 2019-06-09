#include "src/pplib/pplib.h"
#include "led_controller.h"
#include "dashboard.h"

int min = 1000;
int max = 0;

void setup() 
{
	Serial.begin(9600);
	init(new led_controller(), new dashboard());
}


void loop() 
{
	update(millis());
}
