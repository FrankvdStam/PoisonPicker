#pragma once

//rotary encoder (can't change these; these pins have hardware interrupts)
#define ROTARY_ENCODER_PIN1		2
#define ROTARY_ENCODER_PIN2		3

//Display pins
#define DISPLAY_PIN_D7			4
#define DISPLAY_PIN_D6			5
#define DISPLAY_PIN_D5			6
#define DISPLAY_PIN_D4			7
#define DISPLAY_PIN_EN			11
#define DISPLAY_PIN_RS			12

//led strip pin
#define LED_PIN					13

//Button pins (14 is mapped to A0 on Arduino uno, 15 to A1, etc.)
#define BUTTON_PIN_TOGGLE_STATE 14
#define BUTTON_PIN_RANDOMIZE	15
#define BUTTON_PIN_KEY			16
#define BUTTON_PIN_SWITCH		17
