#include "includes.hpp"
#include "app.hpp"
#include "text_renderer.hpp"
#include "editor.hpp"

int main() {
  particle::application* app = new particle::application;
  particle::textrenderer* text_renderer = new particle::textrenderer;

  std::string str = "hullo";
  text_renderer->load_font("/home/parth/Projects/particle/fonts/FiraCode.ttf", 50, 15);

  particle::io_handler* test_file = new particle::io_handler("/home/parth/Projects/particle/config.cfg");
  std::string other = test_file->return_stream_data();

  SDL_Rect dyna_rect {.x = 50, .y = 10};
  SDL_Rect file_rect {.x = 50, .y = 60};

  SDL_Event e;
  bool quit = false;
  while(!quit) {
    while(SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        quit = true;
      }
      if (e.type == SDL_KEYDOWN) {
        str = "key down";
      }
      if (e.type == SDL_KEYUP) {
        str = "key up";
      }
      SDL_RenderClear(app->renderer);
      // text_renderer->render_text(app, str, WHITE, dyna_rect);
      text_renderer->render_text(app, other, WHITE, file_rect);
      SDL_RenderPresent(app->renderer);
    }

  }

  TTF_Quit();

  delete test_file;
  delete text_renderer;
  delete app;
  return 0;
}