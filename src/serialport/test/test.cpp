#define BOOST_TEST_MODULE test serial port
#include <boost/predef.h>

#include <boost/test/included/unit_test.hpp>
#include <string>

#include "../include/serialport.hpp"

BOOST_AUTO_TEST_CASE(test_OpenPort_OK)
{

#if BOOST_OS_WINDOWS
    const std::string port = "COM4";
#elif BOOST_OS_LINUX
    const std::string port = "/dev/pst/5";
#else
#pragma message("not supported yet")
#endif
    BOOST_TEST_MESSAGE("test opening " + port);
    timed_serial_port serial(port, 9600);
    BOOST_TEST(serial.isOpen());
}

BOOST_AUTO_TEST_CASE(test_OpenPort_Fail)
{
    BOOST_TEST_MESSAGE("test opening COM30");
    BOOST_CHECK_THROW(timed_serial_port("COM30", 9600), boost::system::system_error);
}
