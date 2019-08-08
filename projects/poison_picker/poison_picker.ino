#include "led_controller.h"
#include "dashboard.h"
#include "src/pplib/include/pplib/pplib.h"
#include "serial_logger.h"

poison_picker::poison_picker* m_poison_picker;



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

	i_animation* r = new randomize(m_led_controller, m_dashboard);

	i_animation** animations = new i_animation*[4];
	animations[0] = new color_wheel(m_led_controller, m_dashboard);
	animations[1] = new flow(m_led_controller, m_dashboard);
	animations[2] = new brightness(m_led_controller, m_dashboard);
	animations[3] = new rinald(m_led_controller, m_dashboard);

	m_poison_picker = new poison_picker::poison_picker(m_led_controller, m_dashboard, r, animations, 4);
}


void loop() 
{
	//Serial.println("Loop");
	m_poison_picker->update(millis());
}
