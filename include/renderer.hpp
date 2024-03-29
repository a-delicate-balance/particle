#include "editor.hpp"

class ParticleRenderer
{
  ParticleEditor* p_editor = nullptr;
  SDL_Surface* testSurface = nullptr;
  SDL_Texture* test_tex = nullptr;

public:
  ParticleRenderer(ParticleEditor* p_editor);
  ~ParticleRenderer();
  void load_test_img();
  void unload_test_img();
  void push_test_img();
  void draw_test_rect();
};