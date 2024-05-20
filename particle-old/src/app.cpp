#include "../include/app.hpp"
#include <SDL2/SDL_video.h>


ParticleApplication::ParticleApplication()
{
  std::cout << "INITIALIZING SDL" << std::endl;
  if(SDL_Init(SDL_INIT_VIDEO) < 0 )
  {
    std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
  }
  else
  {
    window = SDL_CreateWindow("particle editor",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                SCREEN_WIDTH,
                                SCREEN_HEIGHT,
                                SDL_WINDOW_RESIZABLE);

    sdl_check_ptr(window, "Window");
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    sdl_check_ptr(renderer, "Renderer");
  }
}

ParticleApplication::~ParticleApplication()
{
  std::cout << "Clearing Renderer" << std::endl;
  SDL_DestroyRenderer(renderer);
  std::cout << "renderer gone" << std::endl;
  std::cout << "Clearing Window and SDL Initialization" << std::endl;
  SDL_DestroyWindow(window);
  SDL_Quit();
  std::cout << "goodbye :)" << std::endl;
}


void ParticleApplication::load_test_img()
{
  testSurface = SDL_LoadBMP("assets/test.bmp");
  sdl_check_ptr(testSurface, "testing surface");
  test_tex = SDL_CreateTextureFromSurface(renderer, testSurface);
}
void ParticleApplication::push_test_img()
{
  SDL_RenderClear(renderer);
  sdl_check_func(SDL_RenderCopy(renderer, test_tex, nullptr, nullptr), "RenderCopy");
}
void ParticleApplication::unload_test_img()
{
  SDL_FreeSurface(testSurface);
  testSurface = nullptr;
  SDL_DestroyTexture(test_tex);
  test_tex = nullptr;
}
void ParticleApplication::draw_test_rect()
{
  SDL_Rect* rekt = new SDL_Rect;
  rekt->h = 500;
  rekt->w = 500;
  rekt->x = 10;
  rekt->y = 10;
  SDL_SetRenderDrawColor(renderer, 0x00, 0xAA, 0xAF, 0xFF);
  SDL_RenderFillRect(renderer, rekt);
}

void ParticleApplication::render_rect(int x, int y, int w, int h, SDL_Color color)
{
  SDL_Rect rect = {x,y, w,h};
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderFillRect(renderer, &rect);
}

void ParticleApplication::render_panel(int left, int top, bool max_w, bool max_h, SDL_Color color)
{
  // SDL_DisplayMode dm;
  // SDL_GetCurrentDisplayMode(0, &dm);
  // screen_size.w = dm.w;
  // screen_size.h = dm.h;
  // // | | |
  // // (left / total_vertical) * width, (top / total_horizontal) * height
  // int panel_x = (left / total_vertical) * screen_size.w;
  // int panel_y = (top / total_horizontal) * screen_size.h;
  // int panel_w = (max_w) ? screen_size.w - panel_x : 
  //   panel_x + ((left + 1) / total_vertical) * screen_size.w;
  // int panel_h = (max_h) ? screen_size.h - panel_y :
  //   panel_x + ((top + 1) / total_horizontal) * screen_size.h;

  // std::cout << "Panel details:" <<
  //   max_w << " " <<
  //   max_h << " " <<
  //   panel_x << " " <<
  //   panel_y << " " <<
  //   panel_w << " " <<
  //   panel_h << " " <<
  //   std::endl;

  // render_rect(panel_x, panel_y, panel_w, panel_h, color);
}
