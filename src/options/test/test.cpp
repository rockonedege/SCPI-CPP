#define BOOST_TEST_MODULE test options
#include <boost/test/included/unit_test.hpp>

#include "../include/options.hpp"

BOOST_AUTO_TEST_CASE(test_Options)
{
  auto no_such_file = "";
  BOOST_TEST(tom::has_settings_file(no_such_file) == false);
}

BOOST_AUTO_TEST_CASE(test_port_parse_1)
{
  auto port = tom::parse("COM1");
  BOOST_TEST("COM1" == port.name);
  BOOST_TEST(0 == port.baud_rate);
  BOOST_TEST(0 == port.parity);
  BOOST_TEST(0 == port.flow);
}

BOOST_AUTO_TEST_CASE(test_port_parse_2)
{
  auto port = tom::parse("COM1:1");
  BOOST_TEST("COM1" == port.name);
  BOOST_TEST(1 == port.baud_rate);
  BOOST_TEST(0 == port.parity);
  BOOST_TEST(0 == port.flow);
}

BOOST_AUTO_TEST_CASE(test_port_parse_3)
{
  auto port = tom::parse("COM1:1,1");
  BOOST_TEST("COM1" == port.name);
  BOOST_TEST(1 == port.baud_rate);
  BOOST_TEST(1 == port.parity);
  BOOST_TEST(0 == port.flow);
}

BOOST_AUTO_TEST_CASE(test_port_parse_4)
{
  auto port = tom::parse("COM1:1,1,1");
  BOOST_TEST("COM1" == port.name);
  BOOST_TEST(1 == port.baud_rate);
  BOOST_TEST(1 == port.parity);
  BOOST_TEST(1 == port.flow);
}

BOOST_AUTO_TEST_CASE(test_port_parse_separator)
{
  auto port = tom::parse("COM1:1 1-1");
  BOOST_TEST("COM1" == port.name);
  BOOST_TEST(1 == port.baud_rate);
  BOOST_TEST(1 == port.parity);
  BOOST_TEST(1 == port.flow);
}

BOOST_AUTO_TEST_CASE(test_port_parse_fewer_parameters)
{
  BOOST_CHECK_THROW(tom::parse("COM1-1-"), std::invalid_argument);
}