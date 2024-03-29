#include "../include/text.hpp"


ParticleText::ParticleText(ParticleEditor* _p_editor)
{
  p_editor = _p_editor;

  sdl_check_func(TTF_Init(), "TTF");
}
ParticleText::~ParticleText()
{
  std::cout << "Clearing SDL_TTF" << std::endl;
  TTF_Quit();
  std::cout << "ttf gone" << std::endl;
}
void ParticleText::generate_atlas(std::string font_path)
{

}
void ParticleText::load_static_text(std::string font_path, std::string str)
{
  TTF_Font* font = TTF_OpenFont(font_path.c_str(), 50);
  sdl_check_ptr(font, "font");
  SDL_Color tex_col;
  tex_col.r = 255;
  tex_col.g = 255;
  tex_col.b = 255;
  tex_col.a = 255;
  SDL_Color bg_col;
  bg_col.r = 155;
  bg_col.g = 155;
  bg_col.b = 155;
  bg_col.a = 155;
  SDL_Surface* text_surface = TTF_RenderUTF8_Solid(font, str.c_str(), tex_col);
  sdl_check_ptr(text_surface, "text surface");
  text = SDL_CreateTextureFromSurface(p_editor->renderer, text_surface);
  sdl_check_ptr(text, "Texture for static text");
  TTF_SizeText(font, str.c_str(), &text_rect.w, &text_rect.h);
  text_rect.x = 50;
  text_rect.y = 10;
}
void ParticleText::draw_static_text()
{
  SDL_RenderCopy(p_editor->renderer, text, nullptr, &text_rect);
}
void ParticleText::unload_static_text()
{
  SDL_DestroyTexture(text);
}