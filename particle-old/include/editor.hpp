#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
#include <vector>
#include "SDL_Loader.hpp"

class ParticleEditor
{
private:
  std::string fstream_to_string(std::fstream& in);
  size_t buf_size = 4096;
public:
  struct{
    std::string filebuf;
    int cursor = 0;
  } buffer;
  ParticleEditor(std::string filepath);
  void text_editor_event_handler(SDL_Event* e);
  ~ParticleEditor();

};
