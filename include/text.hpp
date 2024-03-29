#include <vector>
#include <string>
#include "editor.hpp"


class ParticleText
{
  ParticleEditor* p_editor;
  SDL_Texture* text = nullptr;
  SDL_Rect text_rect;

  struct character
  {
    char key;
    SDL_Texture* char_text;
  };
  std::vector<character> charset;

public:
  ParticleText(ParticleEditor* p_editor);
  ~ParticleText();
  void generate_atlas(std::string font_path);
  void load_static_text(std::string font_file, std::string str);
  void draw_static_text();
  void unload_static_text();
};