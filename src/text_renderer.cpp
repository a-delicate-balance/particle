#include "text_renderer.hpp"

using namespace particle;

textrenderer::textrenderer() {
  std::cout << "starting ttf" << std::endl;
  TTF_Init();
  std::cout << "started ttf" << std::endl;

}

textrenderer::~textrenderer() {
  TTF_Quit();
}

void textrenderer::load_font(std::string font_path, int size) {
  font = TTF_OpenFont(font_path.c_str(), size);
  if (font == nullptr) { std::cout << "no way was it the font" << std::endl; }
}

void textrenderer::render_text(application* app, std::string text, SDL_Color col) {
  text_rect.x = 50;
  text_rect.y = 10;
  // std::cout << "font: " << &font << std::endl;
  // std::cout << "col: "
  //           << "\nr = " << (int)col.r
  //           << "\ng = " << (int)col.g
  //           << "\nb = " << (int)col.b
  //           << "\na = " << (int)col.a
  //           << std::endl;
  // std::cout << text.c_str() << std::endl;
  text_surface = TTF_RenderText_Solid(font, text.c_str(), col);
  text_tex = SDL_CreateTextureFromSurface(app->renderer, text_surface);
  TTF_SizeText(font, text.c_str(), &text_rect.w, &text_rect.h);
}
void textrenderer::display_text(application* app) {
  SDL_RenderCopy(app->renderer, text_tex, nullptr, &text_rect);
}