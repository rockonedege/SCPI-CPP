#include <iostream>
#include <string>

#include <boost/predef.h>
#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>
#include <boost/system/system_error.hpp>

#define MAXLEN 12 // maximum buffer size

using namespace boost;

namespace simulator
{
const char *default_port()
{

  // open the platform specific device name
  // windows will be COM ports, linux will use /dev/ttyS* or /dev/ttyUSB*, etc
#if BOOST_OS_WINDOWS
  const char *port = "COM2";
#elif BOOST_OS_LINUX
  const char *port = "/dev/pst/3";
#else
#pragma message("not supported yet")
#endif

  return port;
}

std::string read_console(asio::serial_port &serial)
{
  std::string input;
  std::cout << "Enter Message: ";
  std::cin >> input;

  if (input == "exit")
   return input;

  // write to the port
  // asio::write guarantees that the entire buffer is written to the serial port
  asio::write(serial, asio::buffer(input));
  std::cout << input << " written.\n";

  return input;
}

void read_port(asio::serial_port &serial, size_t bytes)
{
  char data[MAXLEN];
  std::string message(data, bytes);

  // read bytes from the serial port
  // asio::read will read bytes until the buffer is filled
  size_t nread = asio::read(
      serial, asio::buffer(data, bytes));

  std::cout << "Received " << nread << " bytes:" << message << std::endl;
}

void run(const char *port)
{
  asio::io_context io;

  try
  {
    asio::serial_port serial(io);
    serial.open(port);

    for (;;)
    {
      std::cout << port << " opened successfully.\n";

      if ("exit" == read_console(serial)) break;

      read_port(serial, MAXLEN);
    }

    serial.close();
  }
  catch (system::system_error &e)
  {
    std::cerr << e.what() << std::endl;
  }
}
} // namespace simulator

int main(int argc, char *argv[])
{
  std::cout << R"(Usage: 
    simulator <port_name[=COM2|/dev/pst/3]>
    )";

  simulator::run(argc > 1 ? argv[1] : simulator::default_port());

  return 0;
}