#include "editor.hpp"

using namespace particle;

io_handler::io_handler(std::string file_path) {
  stream.open(file_path, std::ios::out | std::ios::in);
  if (!stream) { std::cout << "ERROR: File " << file_path << " was not opened"; }
}

std::string io_handler::return_stream_data() {
  // stream.seekg(0);
  std::string ret;
  char buffer[4096];
  while (stream.read(buffer, sizeof(buffer))) { ret.append(buffer, sizeof(buffer)); }
  ret.append(buffer, stream.gcount());
  // std::cout << ret << std::endl;
  return ret;
}

io_handler::~io_handler() {
  stream.close();
}
