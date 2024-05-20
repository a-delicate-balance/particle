#pragma once

#ifndef EDITOR_H
#define EDITOR_H

#include "SDL_Loader.hpp"

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 540;

class ParticleApplication
{
  SDL_Surface* testSurface = nullptr;
  SDL_Texture* test_tex = nullptr;

  int total_vertical = 1;
  int total_horizontal = 2;

  struct
  {
    int w;
    int h;
  } screen_size;

public:
  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;

  ParticleApplication();
  ~ParticleApplication();

  void load_test_img();
  void unload_test_img();
  void push_test_img();
  void draw_test_rect();
  void render_rect(int x, int y, int w, int h, SDL_Color color);
  void render_panel(int left, int top, bool max_w, bool max_h, SDL_Color color);
};




#endif
