#pragma once

//abstract types
#include "../src/devices/i_led_controller.h"
#include "../src/devices/i_dashboard.h"
#include "../src/animations/i_animation.h"

using poison_picker::devices::i_dashboard;
using poison_picker::devices::i_led_controller;
using poison_picker::animations::i_animation;

//rgb
#include "../src/rgb.h"

using poison_picker::rgb;

//premade animations
#include "../src/animations/color_wheel.h"
#include "../src/animations/flow.h"
#include "../src/animations/brightness.h"


using poison_picker::animations::color_wheel;
using poison_picker::animations::flow;
using poison_picker::animations::brightness;

//animator to tie things together
#include "../src/animator.h"

using poison_picker::animator;

//debug printing
#include "../src/i_logger.h"

using poison_picker::i_logger;