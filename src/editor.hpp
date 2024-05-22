#include <fstream>
#include "includes.hpp"
#include "app.hpp"

namespace particle {
class io_handler{
  private:
  std::fstream stream;
  public:
  io_handler(std::string file_path);
  ~io_handler();
  std::string return_stream_data();
};
}