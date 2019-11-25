#include <fmt/format.h>
using namespace fmt::literals;

#include "../../logging/include/logging.hpp"
#include "../../commands/include/commands.hpp"
#include "../../serialport/include/serialport.hpp"
#include "../../options/include/options.hpp"

#include "../include/example.hpp"

namespace
{
int run_sp(const std::string& port)
{
  using namespace boost;
  using std::cout;
  using std::endl;

  try
  {

    timed_serial_port serial(port, 9600);
    serial.setTimeout(asio::chrono::seconds(50));

    //Text test
    serial.writeString("Hello world\r\n");
    tom::logging_event(tom::severity::info, serial.readStringUntil());

    //Binary test
    unsigned char values[] = {0xde, 0xad, 0xbe, 0xef};
    serial.write(reinterpret_cast<char *>(values), sizeof(values));
    serial.read(reinterpret_cast<char *>(values), sizeof(values));
    for (unsigned int i = 0; i < sizeof(values); i++)
    {
      tom::logging_event(tom::severity::info, "{}"_format(static_cast<int>(values[i])));
    }

    serial.close();

    return 0;
  }
  catch (boost::system::system_error &e)
  {
    tom::logging_event(tom::severity::error, "Error: {}"_format(e.what()));
    return 1;
  }
}
} // namespace

int main(int argc, char *argv[])
{
  using namespace std;

  tom::init_log2();

  cout << "Hipot Testers Version 0.01"
       << "\n"
       << "Built on " << __DATE__ << ", " __TIME__
       << "\n"
       << "Using Boost version: " << BOOST_LIB_VERSION
       << "\n"
       <<
      R"(Usage: 
    Hipot -p COM1:1,0,0 -p COM2:1,0,0  
    )"
       << "\n";

  auto options = tom::parse_options(argc, argv);

  tom::logging_data("Specified ports:");
  for (auto &p : options.ports)
    tom::logging_data("- {}"_format(p.name));

  if (!options.ports.empty())
  {
    auto port = options.ports.front();
    std::cout << "opening {}"_format(port.name);
    example(port.name.c_str());
  }

  run_sp("COM3");
}