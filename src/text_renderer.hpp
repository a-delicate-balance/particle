#ifndef P_TEXT_RENDERER_H
#define P_TEXT_RENDERER_H

//#include "includes.hpp"
#include "app.hpp"

namespace particle {
class textrenderer {
  private:
  TTF_Font* font;
  SDL_Surface* text_surface;
  SDL_Texture* text_tex;
  SDL_Rect text_rect;
  public:
  textrenderer();
  ~textrenderer();
  void load_font(std::string font_path, int size);
  void render_text(application* app, std::string text, SDL_Color col);
  void display_text(application* app);
};

} // namespace particle

#endif