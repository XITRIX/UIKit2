/*
 * Copyright 2011-2019 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx#license-bsd-2-clause
 */
#include <Application.hpp>
#include <GLFWVideo.hpp>
#include <SDLVideo.hpp>

int Application::run() {
    new SDLVideo();
}