#include "app.hpp"
#include "text_renderer.hpp"

int main()
{
  particle::application* app = new particle::application;
  particle::textrenderer* text_renderer = new particle::textrenderer;

  SDL_Event e;
  std::string str = "hullo";
  bool quit = false;
  while(!quit)
  {
    while(SDL_PollEvent(&e))
    {
      if (e.type == SDL_QUIT)
      {
        quit = true;
      }
      if (e.type == SDL_KEYDOWN)
      {
        str = "key down";
      }
      if (e.type == SDL_KEYUP)
      {
        str = "key up";
      }
    }
    text_renderer->render_text(app, str, WHITE);

  }

  TTF_Quit();

  delete app;

  return 0;
}