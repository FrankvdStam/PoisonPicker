#pragma once

//abstract types
#include "devices/i_led_controller.h"
#include "devices/i_dashboard.h"
#include "animations/i_animation.h"

using poison_picker::devices::i_dashboard;
using poison_picker::devices::i_led_controller;
using poison_picker::animations::i_animation;

//rgb
#include "rgb.h"

using poison_picker::rgb;

//premade animations
#include "animations/color_wheel.h"
#include "animations/flow.h"
#include "animations/brightness.h"


using poison_picker::animations::color_wheel;
using poison_picker::animations::flow;
using poison_picker::animations::brightness;

//animator to tie things together
#include "animator.h"

using poison_picker::animator;

//debug printing
#include "debug.h"

using poison_picker::i_logger;