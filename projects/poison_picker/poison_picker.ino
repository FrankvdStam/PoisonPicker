#include "led_controller.h"
#include "dashboard.h"
#include "src/pplib/include/pplib/pplib.h"

//#include "src/pplib/helper.h"

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

void setup() 
{
	Serial.begin(9600);
	Serial.println("Starting.");
	
	i_logger::set(new serial_logger());
	if (i_logger::available()) {
		i_logger& logger = i_logger::get();
		logger.print("logger initialized");
	}

	poison_picker::helper::amount_of_digits(123);


	//i_logger* logger = new serial_logger();
	//debug::set_logger(logger);

	i_led_controller*	m_led_controller	= new led_controller();
	i_dashboard*		m_dashboard			= new dashboard();

	i_animation** animations = new i_animation*[4];
	animations[0] = new color_wheel(m_led_controller, m_dashboard);
	animations[1] = new flow(m_led_controller, m_dashboard);
	animations[2] = new brightness(m_led_controller, m_dashboard);
	animations[3] = new rinald(m_led_controller, m_dashboard);

	m_animator = new animator(m_led_controller, m_dashboard, animations, 4);
}


void loop() 
{
	//Serial.println("Loop");
	m_animator->update(millis());
}
