// #include <iostream>
#include "../include/SDL_Loader.hpp"

bool sdl_check_ptr (void* ptr, std::string desc)
{
  if (ptr == nullptr) {std::cerr << desc << " Pointer not valid. SDL Error: " << SDL_GetError() << std::endl; return false; }
  return true;
}

bool sdl_check_func (int status, std::string desc)
{
  if (status < 0) {std::cerr << desc << " Function exited with error code " << status << ". SDL Error: " << SDL_GetError() << std::endl; return false; }
  return true;
}
