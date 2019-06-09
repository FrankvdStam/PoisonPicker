#pragma once
#include "pplib.h"
#include "animations/animations.h"

void init(poison_picker::devices::i_led_controller* led_controller, poison_picker::devices::i_dashboard* dashboard);
void update(unsigned long miliseconds);