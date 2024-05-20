//TODO: STUFF ABOUT THE editor
//requirements:
//1. text buffer of file for modification
//2. cursor to navigate the buffer
//3. event handling for user keystrokes
//4. 


#include "../include/editor.hpp"

std::string ParticleEditor::fstream_to_string (std::fstream& in)
{
  std::stringstream sstr;
  sstr << in.rdbuf();
  for (int i = 0; i < sstr.str().length(); i++) { std::cout << sstr.str().at(i) << std::endl; }
  return sstr.str();
}

ParticleEditor::ParticleEditor(std::string filepath)
{
  std::fstream stream;
  stream.open(filepath, std::ios::in | std::ios::out | std::ios::ate);
  if (stream.is_open())
  {
    buffer.filebuf = fstream_to_string(stream);
    buffer.cursor = stream.tellg();
    stream.seekg(0, std::ios::beg);
    stream.seekp(0, std::ios::beg);
  }
}

void ParticleEditor::text_editor_event_handler(SDL_Event* e)
{
//  switch (e->type)
//  {
//    case SDL_BACKSPACE:
//      if (buffer.cursor > 0)
//      {
//      }
//  }
}


ParticleEditor::~ParticleEditor()
{

}
