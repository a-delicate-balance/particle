#pragma once

#ifndef SDL_LOADER_HPP
#define SDL_LOADER_HPP


#include <iostream>
#include "SDL2/SDL.h"

#include "SDL2/SDL_ttf.h"


bool sdl_check_ptr (void* ptr, std::string desc);
bool sdl_check_func (int status, std::string desc);

#endif