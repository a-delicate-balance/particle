#ifndef P_TEXT_RENDERER_H
#define P_TEXT_RENDERER_H

//#include "includes.hpp"
#include "app.hpp"
#include <string>
#include <sstream>

namespace particle {
class textrenderer {
  private:
  TTF_Font* font;
  SDL_Surface* text_surface;
  SDL_Texture* text_tex;
  SDL_Rect text_rect;
  int font_size;
  int font_padding = 15;
  public:
  textrenderer();
  ~textrenderer();
  void load_font(std::string font_path, int size, int padding);
  void render_text(application* app, std::string text, SDL_Color col, SDL_Rect rect);
};

} // namespace particle

#endif