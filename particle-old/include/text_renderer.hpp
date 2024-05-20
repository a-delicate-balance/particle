#include <vector>
#include <string>
#include "app.hpp"


class ParticleTextRenderer
{
  ParticleApplication* p_app;
  SDL_Texture* text = nullptr;
  SDL_Rect text_rect;

  struct character
  {
    char key;
    SDL_Texture* char_text;
  };
  character charset[224];

  SDL_Texture* generate_texture(std::string font_path, char* _chr);

public:
  ParticleTextRenderer(ParticleApplication* p_app);
  ~ParticleTextRenderer();  
  void load_static_text(std::string font_file, std::string str);
  void draw_static_text();
  void unload_static_text();
};
