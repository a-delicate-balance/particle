#include "../include/windowing.hpp"

ParticleWindow::ParticleWindow(ParticleEditor* _p_editor)
{
  p_editor = _p_editor;
  std::cout << "INITIALIZING SDL" << std::endl;
  if(SDL_Init(SDL_INIT_VIDEO) < 0 )
  {
    std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
  }
  else
  {
    p_editor->window = SDL_CreateWindow("particle editor",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                SCREEN_WIDTH,
                                SCREEN_HEIGHT,
                                SDL_WINDOW_RESIZABLE);

    sdl_check_ptr(p_editor->window, "Window");
  }
}

ParticleWindow::~ParticleWindow()
{
  std::cout << "Clearing Window and SDL Initialization" << std::endl;
  SDL_DestroyWindow(p_editor->window);
  SDL_Quit();
  std::cout << "goodbye :)" << std::endl;
}

