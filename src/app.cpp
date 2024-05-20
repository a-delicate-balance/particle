#include "app.hpp"

using namespace particle;

application::application() {
  std::cout << "INITIALIZING SDL" << std::endl;
  if(SDL_Init(SDL_INIT_VIDEO) < 0 ) {
    std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
  }
  else {
    window = SDL_CreateWindow("particle editor",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                SCREEN_WIDTH,
                                SCREEN_HEIGHT,
                                SDL_WINDOW_RESIZABLE);
    if(window == nullptr) { std::cout << "no window lol." << SDL_GetError() << std::endl; }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr) { std::cout << "no renderer lol." << SDL_GetError() << std::endl; }
  }
  std::cout << "done sdl shit" << std::endl;
}

application::~application() {
  std::cout << "Clearing Renderer" << std::endl;
  SDL_DestroyRenderer(renderer);
  std::cout << "renderer gone" << std::endl;
  std::cout << "Clearing Window and SDL Initialization" << std::endl;
  SDL_DestroyWindow(window);
  SDL_Quit();
  std::cout << "goodbye :)" << std::endl;
}
