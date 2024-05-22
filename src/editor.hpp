#include <fstream>
#include "includes.hpp"
#include "app.hpp"

namespace particle {
class io_handler {
  private:
  std::fstream stream;
  public:
  io_handler(std::string file_path);
  ~io_handler();
  std::string return_stream_data();
};
class buffer_handler {
  private:
  std::string buffer;
  public:
  buffer_handler();
  ~buffer_handler();
  void flush_and_fill_buffer(io_handler io);
};
class event_handler {
  private:
  event_handler();
  ~event_handler();
  bool export_event_bool();
  std::string export_event_str();
};
}