#ifndef P_APP_H
#define P_APP_H

#include "includes.hpp"

namespace particle {
class application {
  private:
  const int SCREEN_WIDTH = 960;
  const int SCREEN_HEIGHT = 540;
  public:
  SDL_Renderer* renderer;
  SDL_Window* window;
  application();
  ~application();
};
}

#endif