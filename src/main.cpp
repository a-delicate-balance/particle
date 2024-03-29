#include <iostream>
#include "../include/SDL_Loader.hpp"
#include "../include/editor.hpp"
#include "../include/windowing.hpp"
#include "../include/renderer.hpp"
#include "../include/text.hpp"


int main()
{
  std::cout << "Hi again" << std::endl;
  ParticleEditor* p_editor = new ParticleEditor();
  ParticleWindow* p_window = new ParticleWindow(p_editor);
  ParticleRenderer* p_renderer = new ParticleRenderer(p_editor);
  ParticleText* p_text = new ParticleText(p_editor);



  bool quit = false;
  SDL_Event e;

  p_renderer->load_test_img();
  p_text->load_static_text("fonts/FiraCode.ttf", "There There");

  while(!quit)
  {
    while(SDL_PollEvent(&e))
    {
      if (e.type == SDL_QUIT)
      {
        quit = true;
      }
    }
    SDL_RenderClear(p_editor->renderer);
    p_renderer->push_test_img();
    p_renderer->draw_test_rect();
    p_text->draw_static_text();
    SDL_RenderPresent(p_editor->renderer);
  }

  p_text->unload_static_text();
  p_renderer->unload_test_img();




  delete p_renderer;
  delete p_window;
  delete p_editor;
  return 0;
}