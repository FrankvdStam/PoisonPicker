#include "led_controller.h"
#include "dashboard.h"
#include "src/pplib/pplib.h"
#include "src/pplib/animations/color_wheel.h"

int min = 1000;
int max = 0;

animator* m_animator;

//Defines debug.h get_serial(). Allows Serial println's inside pplib
HardwareSerial* get_serial(){
	return &Serial;
}

void calibrate_potmeter()
{
	int pot_min = 1024;
	int pot_max = 0;

	while(true){
		int value = analogRead(A0);

		bool print = false;
		if(value > pot_max){
			print = true;
			pot_max = value;
		}
		if(value < pot_min){
			print = true;
			pot_min = value;
		}
		if(print){
			Serial.print("Min: ");
			Serial.print(pot_min);
			Serial.print(" Max: ");
			Serial.print(pot_max);
			Serial.print('\n');
		}
	}
}

void setup() 
{
	Serial.begin(9600);
	Serial.println("Starting.");

	//calibrate_potmeter();

	i_led_controller*	m_led_controller	= new led_controller();
	i_dashboard*		m_dashboard			= new dashboard();

	i_animation** animations = new i_animation*[1];
	animations[0] = new color_wheel(m_led_controller, m_dashboard);
	animations[1] = new brightness(m_led_controller, m_dashboard);

	m_animator = new animator(m_led_controller, m_dashboard, animations, 2);
}


void loop() 
{
	//Serial.println("Loop");
	m_animator->update(millis());
}
