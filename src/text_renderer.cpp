#include "text_renderer.hpp"
#include <SDL2/SDL_ttf.h>

using namespace particle;

textrenderer::textrenderer() {
  std::cout << "Initializing SDL_ttf" << std::endl;
  if (TTF_Init() != 0) { std::cout << "ERROR: Failed to initialize SDL_ttf" << std::endl; }
}

textrenderer::~textrenderer() {
  TTF_Quit();
}

void textrenderer::load_font(std::string font_path, int size, int padding) {
  font = TTF_OpenFont(font_path.c_str(), size);
  if (font == nullptr) {
    std::cout << "ERROR: Failed to load font: " << font_path << " SDL Error: " << SDL_GetError() << std::endl;
    return; }
  font_size = size;
  font_padding = padding;
}

void textrenderer::render_text(application* app, std::string text, SDL_Color col, SDL_Rect rect) {
  if (font == nullptr) { std::cout << "ERROR: No font loaded." << std::endl; return; }

  rect.w = SDL_GetWindowSurface(app->window)->w - rect.x;

  // TODO: fixed height on the text.
  // This is so hacky solution for one file it fucking sucks ass lmao
  rect.h = SDL_GetWindowSurface(app->window)->h - rect.y;

  rect.h = 50;

  //Idea time.
  //count the number of '\n'?? (lmao)


  // std::cout << lines << std::endl;

  // well I counted this shit, time to use it.
  // 50 + 10 => size + padding
  // rect.h = lines * (50 + 15);

  //well this shit still sucks ass lol

  // THIS APPROACH ADDS NO PADDING BUT ALLOWS FOR MULTILINE RENDERING.
  // maybe I can use it to optimize rendering?
  // I need more brain power for that lmao.
  uint lines = 0;
  std::string render = "";
  std::istringstream _text(text);
  while (std::getline(_text, render)) {
    ++lines;
    text_surface = TTF_RenderText_Blended(font, render.c_str(), col);
    if (font == nullptr) { std::cout << "ERROR: Failed to load surface for text. SDL Error: " << SDL_GetError() << std::endl; return; }
    text_tex = SDL_CreateTextureFromSurface(app->renderer, text_surface);
    if (font == nullptr) { std::cout << "ERROR: Failed to load texture for text. SDL Error: " << SDL_GetError() << std::endl; return; }
    TTF_SizeText(font, render.c_str(), &rect.w, &rect.h);
    SDL_RenderCopy(app->renderer, text_tex, nullptr, &rect);
    int padding = 15;
    rect.y += font_size + padding;
  }

}