
#include <numeric>
#include <vector>
#include <string>

#include <boost/range/irange.hpp>

#include "../../serialport/include/serialport.hpp"
#include "../../commands/include/commands.hpp"

#include "../include/example.hpp"

std::string read_string(timed_serial_port &serial, const std::string &cmd)
{
  std::string steps;
  serial.writeString(cmd);
  steps = serial.readStringUntil("\n");
  return steps;
}

size_t read_int(timed_serial_port &serial, const std::string &cmd)
{
  return std::stoul(read_string(serial, cmd));
}

void example(const char* port)
{
  using namespace scpi_99;

  timed_serial_port serial(port, 9600);

  // send "STOP" command to device
  serial.writeString(SOURce::SAFEty::STOP());

  // clear all steps data size_t steps;
  for (auto i : boost::irange(std::size_t{0},
                              read_int(serial, SOURce::SAFEty::SNUMber_query())))
  {
    serial.writeString(SOURce::SAFEty::STEPn::DELete(i));
  }

  std::vector<std::string> commands = {
      SOURce::SAFEty::STEPn::AC::LEVel(1, 500),
      SOURce::SAFEty::STEPn::AC::LIMit::HIGH(1, 0.003),
      SOURce::SAFEty::STEPn::AC::TIME::TEST(1, 3),

      SOURce::SAFEty::STEPn::DC::LEVel(2, 500),
      SOURce::SAFEty::STEPn::DC::LIMit::HIGH(2, 0.003),
      SOURce::SAFEty::STEPn::DC::TIME::TEST(2, 3),

      SOURce::SAFEty::STEPn::IR::LEVel(3, 500),
      SOURce::SAFEty::STEPn::IR::LIMit::HIGH(2, 300000),
      SOURce::SAFEty::STEPn::IR::TIME::TEST(2, 3)};
  for (auto &&cmd : commands)
  {
    serial.writeString(cmd);
  }

  auto steps = read_int(serial, SOURce::SAFEty::SNUMber_query());
  // start test
  serial.writeString(SOURce::SAFEty::STARt::ONCE());
  std::string status = "RUNNING";
  while (status != "STOPPED") // do while status is not stopped
  {
    status = read_string(serial, SOURce::SAFEty::STATus_query());

    if ("STOPPED" != status)
    {
      serial.writeString(SOURce::SAFEty::STOP());
      serial.writeString(SOURce::SAFEty::RESult::ALL::OMETerage_query());

      for (auto i : boost::irange(std::size_t{10}, steps))
      {
        serial.readStringUntil("\n");
      }

      serial.writeString(SOURce::SAFEty::RESult::ALL::MMETerage::NORMal_query());

      for (auto i : boost::irange(std::size_t{10}, steps))
      {
        serial.readStringUntil("\n");
      }
    }
  }

  serial.writeString(SOURce::SAFEty::STOP());
}
