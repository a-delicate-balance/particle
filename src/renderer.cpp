#include "../include/renderer.hpp"

ParticleRenderer::ParticleRenderer(ParticleEditor* _p_editor)
{
  p_editor = _p_editor;
  p_editor->renderer = SDL_CreateRenderer(p_editor->window, -1, SDL_RENDERER_ACCELERATED);
  sdl_check_ptr(p_editor->renderer, "Renderer");
}
ParticleRenderer::~ParticleRenderer()
{
  std::cout << "Clearing Renderer" << std::endl;
  SDL_DestroyRenderer(p_editor->renderer);
  std::cout << "renderer gone" << std::endl;
}
void ParticleRenderer::load_test_img()
{
  testSurface = SDL_LoadBMP("assets/test.bmp");
  sdl_check_ptr(testSurface, "testing surface");
  test_tex = SDL_CreateTextureFromSurface(p_editor->renderer, testSurface);
}
void ParticleRenderer::push_test_img()
{
  SDL_RenderClear(p_editor->renderer);
  sdl_check_func(SDL_RenderCopy(p_editor->renderer, test_tex, nullptr, nullptr), "RenderCopy");
}
void ParticleRenderer::unload_test_img()
{
  SDL_FreeSurface(testSurface);
  testSurface = nullptr;
  SDL_DestroyTexture(test_tex);
  test_tex = nullptr;
}
void ParticleRenderer::draw_test_rect()
{
  SDL_Rect* rekt = new SDL_Rect;
  rekt->h = 500;
  rekt->w = 500;
  rekt->x = 10;
  rekt->y = 10;
  SDL_SetRenderDrawColor(p_editor->renderer, 0x00, 0xAA, 0xAF, 0xFF);
  SDL_RenderFillRect(p_editor->renderer, rekt);
}