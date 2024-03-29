#pragma once

#ifndef EDITOR_H
#define EDITOR_H

#include "SDL_Loader.hpp"

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 540;

class ParticleEditor
{
public:
  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;
};

#endif