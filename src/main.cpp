#include "includes.hpp"
#include "app.hpp"
#include "text_renderer.hpp"

int main()
{
  particle::application* app = new particle::application;
  particle::textrenderer* text_renderer = new particle::textrenderer;

  std::string str = "hullo";
  text_renderer->load_font("/home/parth/Projects/particle/fonts/FiraCode.ttf", 50);

  SDL_Event e;
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
      SDL_RenderClear(app->renderer);
      text_renderer->render_text(app, str, WHITE);
      text_renderer->display_text(app);
      SDL_RenderPresent(app->renderer);
    }

  }

  TTF_Quit();

  delete app;

  return 0;
}