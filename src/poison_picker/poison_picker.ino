#include "led_controller.h"
#include "dashboard.h"
#include "src/pplib/pplib.h"
#include "src/pplib/animations/color_wheel.h"

int min = 1000;
int max = 0;

animator* m_animator;

class serial_logger : public i_logger
{
public:
	serial_logger() : i_logger(){}

	void print(const char* str) 
	{ 
		Serial.print(str);
	}

	void print(int i) 
	{ 
		Serial.print(i);
	}

	void print(unsigned long i) 
	{ 
		Serial.print(i);
	}

	void print(unsigned char i)
	{
		Serial.print(i);
	}
};

void calibrate_potmeter()
{
	Serial.println("Calibrating potmeter.");

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
	tone(13, 220, 200);

	Serial.begin(9600);
	Serial.println("Starting.");

	//calibrate_potmeter();

	i_logger::set(new serial_logger());
	if (i_logger::available()) {
		i_logger& logger = i_logger::get();
		logger.print("logger initialized");
	}

	//i_logger* logger = new serial_logger();
	//debug::set_logger(logger);

	i_led_controller*	m_led_controller	= new led_controller();
	i_dashboard*		m_dashboard			= new dashboard();

	i_animation** animations = new i_animation*[3];
	animations[0] = new color_wheel(m_led_controller, m_dashboard);
	animations[1] = new flow(m_led_controller, m_dashboard);
	animations[2] = new brightness(m_led_controller, m_dashboard);

	m_animator = new animator(m_led_controller, m_dashboard, animations, 3);
}


void loop() 
{
	//Serial.println("Loop");
	m_animator->update(millis());
}
