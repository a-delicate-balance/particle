#include <iostream>
#include "../include/app.hpp"
#include "../include/text_renderer.hpp"
#include "../include/editor.hpp"

int main()
{
  std::cout << "Hi again" << std::endl;
  ParticleApplication* p_app = new ParticleApplication();
  ParticleTextRenderer* p_text_renderer = new ParticleTextRenderer(p_app);
  ParticleEditor* p_editor = new ParticleEditor("design.md");

  bool quit = false;
  SDL_Event e;

  p_app->load_test_img();

  p_text_renderer->load_static_text("fonts/FiraCode.ttf", "Hi There");
  // p_text_renderer->load_static_text("fonts/FiraCode.ttf", p_editor->buffer.filebuf);

  while(!quit)
  {
    while(SDL_PollEvent(&e))
    {
      if (e.type == SDL_QUIT)
      {
        quit = true;
      }
    }
    SDL_RenderClear(p_app->renderer);
    p_app->push_test_img();
    p_app->render_panel(0, 0, false, true, {0x00, 0xaf, 0x11, 0xff});
    p_app->render_rect(50, 10, 500, 500, {0xff, 0xaf, 0x00, 0xff});
    p_text_renderer->draw_static_text();
    SDL_RenderPresent(p_app->renderer);
  }

  p_text_renderer->unload_static_text();
  p_app->unload_test_img();

  delete p_app;
  return 0;
}
