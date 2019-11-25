/*
 * File:   timed_serial_port.cpp
 * Author: Terraneo Federico
 * Distributed under the Boost Software License, Version 1.0.
 * Created on September 12, 2009, 3:47 PM
 *
 * v1.06: C++11 support
 *
 * v1.05: Fixed a bug regarding reading after a timeout (again).
 *
 * v1.04: Fixed bug with timeout set to zero
 *
 * v1.03: Fix for Mac OS X, now fully working on Mac.
 *
 * v1.02: Code cleanup, speed improvements, bug fixes.
 *
 * v1.01: Fixed a bug that caused errors while reading after a timeout.
 *
 * v1.00: First release.
 */

#include <string>
#include <algorithm>
#include <iostream>
#include <boost/bind.hpp>
#include <iterator>

#include "../include/serialport.hpp"
#include "../../logging/include/logging.hpp"

using namespace std;
using namespace boost;

timed_serial_port::timed_serial_port() : m_io(), m_port(m_io), m_timer(m_io),
                                         m_timeout(boost::asio::chrono::seconds(0)) {}

timed_serial_port::timed_serial_port(const std::string &devname,
                                     unsigned int baud_rate,
                                     asio::serial_port_base::parity opt_parity,
                                     asio::serial_port_base::character_size opt_csize,
                                     asio::serial_port_base::flow_control opt_flow,
                                     asio::serial_port_base::stop_bits opt_stop)
    : m_io(), m_port(m_io), m_timer(m_io), m_timeout(boost::asio::chrono::seconds(0))
{
    open(devname, baud_rate, opt_parity, opt_csize, opt_flow, opt_stop);
}

void timed_serial_port::open(const std::string &devname, unsigned int baud_rate,
                             asio::serial_port_base::parity opt_parity,
                             asio::serial_port_base::character_size opt_csize,
                             asio::serial_port_base::flow_control opt_flow,
                             asio::serial_port_base::stop_bits opt_stop)
{
    if (isOpen())
        close();
    m_port.open(devname);
    m_port.set_option(asio::serial_port_base::baud_rate(baud_rate));
    m_port.set_option(opt_parity);
    m_port.set_option(opt_csize);
    m_port.set_option(opt_flow);
    m_port.set_option(opt_stop);
}

bool timed_serial_port::isOpen() const
{
    return m_port.is_open();
}

void timed_serial_port::close()
{
    if (isOpen() == false)
        return;
    m_port.close();
}

void timed_serial_port::setTimeout(const asio::chrono::steady_clock::duration &t)
{
    m_timeout = t;
}

void timed_serial_port::write(const char *data, size_t size)
{
    asio::write(m_port, asio::buffer(data, size));
}

void timed_serial_port::write(const std::vector<char> &data)
{
    asio::write(m_port, asio::buffer(&data[0], std::size(data)));
}

void timed_serial_port::writeString(const std::string &s)
{

    asio::write(m_port, asio::buffer(s.c_str(), s.size()));
}

void timed_serial_port::read(char *data, size_t size)
{
    if (m_readData.size() > 0) //If there is some data from a previous read
    {
        istream is(&m_readData);
        size_t toRead = min(m_readData.size(), size); //How many bytes to read?
        is.read(data, toRead);
        data += toRead;
        size -= toRead;
        if (size == 0)
            return; //If read data was enough, just return
    }

    m_setupParameters = ReadSetupParameters(data, size);
    performReadSetup(m_setupParameters);

    //For this code to work, there should always be a timeout, so the
    //request for no timeout is translated into a very long timeout
    if (m_timeout != boost::asio::chrono::seconds(0))
        m_timer.expires_from_now(m_timeout);
    else
        m_timer.expires_from_now(boost::asio::chrono::hours(100000));

    m_timer.async_wait(boost::bind(&timed_serial_port::timeoutExpired, this,
                                 asio::placeholders::error));

    m_readresult = READ_RESULT::READ_INPROGRESS;
    m_bytesTransferred = 0;
    for (;;)
    {
        m_io.run_one();
        switch (m_readresult)
        {
        case READ_RESULT::READ_SUCCESS:
            m_timer.cancel();
            return;
        case READ_RESULT::READ_TIMEOUT:
            m_port.cancel();
            tom::logging_event(tom::severity::error, "Timeout expired");
            throw(timeout_exception("Timeout expired"));
        case READ_RESULT::READ_ERROR:
            m_timer.cancel();
            m_port.cancel();
            tom::logging_event(tom::severity::error, "Error while reading");
            throw(boost::system::system_error(boost::system::error_code(),
                                              "Error while reading"));
            //if READ_RESULT::READ_INPROGRESS remain in the loop
        }
    }
}

std::vector<char> timed_serial_port::read(size_t size)
{
    vector<char> result(size, '\0'); //Allocate a vector with the desired size
    read(&result[0], size);          //Fill it with values
    return result;
}

std::string timed_serial_port::readString(size_t size)
{
    string result(size, '\0'); //Allocate a string with the desired size
    read(&result[0], size);    //Fill it with values
    return result;
}

std::string timed_serial_port::readStringUntil(const std::string &delim)
{
    // Note: if readData contains some previously read data, the call to
    // async_read_until (which is done in performReadSetup) correctly handles
    // it. If the data is enough it will also immediately call readCompleted()
    m_setupParameters = ReadSetupParameters(delim);
    performReadSetup(m_setupParameters);

    //For this code to work, there should always be a timeout, so the
    //request for no timeout is translated into a very long timeout
    if (m_timeout != boost::asio::chrono::seconds(0))
        m_timer.expires_from_now(m_timeout);
    else
        m_timer.expires_from_now(boost::asio::chrono::hours(100'000));

    m_timer.async_wait(boost::bind(&timed_serial_port::timeoutExpired, this,
                                 asio::placeholders::error));

    m_readresult = READ_RESULT::READ_INPROGRESS;
    m_bytesTransferred = 0;
    for (;;)
    {
        m_io.run_one();
        switch (m_readresult)
        {
        case READ_RESULT::READ_SUCCESS:
        {
            m_timer.cancel();
            m_bytesTransferred -= delim.size(); //Don't count delim
            istream is(&m_readData);
            string result(m_bytesTransferred, '\0'); //Alloc string
            is.read(&result[0], m_bytesTransferred); //Fill values
            is.ignore(delim.size());               //Remove delimiter from stream
            return result;
        }
        case READ_RESULT::READ_TIMEOUT:
            m_port.cancel();
            tom::logging_event(tom::severity::error, "Timeout expired");
            throw(timeout_exception("Timeout expired"));
        case READ_RESULT::READ_ERROR:
            m_timer.cancel();
            m_port.cancel();
            tom::logging_event(tom::severity::error, "Error while reading");
            throw(boost::system::system_error(boost::system::error_code(),
                                              "Error while reading"));
            //if READ_RESULT::READ_INPROGRESS remain in the loop
        }
    }
}

timed_serial_port::~timed_serial_port() {}

void timed_serial_port::performReadSetup(const ReadSetupParameters &param)
{
    if (param.fixedSize)
    {
        asio::async_read(m_port, asio::buffer(param.data, param.size), boost::bind(&timed_serial_port::readCompleted, this, asio::placeholders::error, asio::placeholders::bytes_transferred));
    }
    else
    {
        asio::async_read_until(m_port, m_readData, param.delim, boost::bind(&timed_serial_port::readCompleted, this, asio::placeholders::error, asio::placeholders::bytes_transferred));
    }
}

void timed_serial_port::timeoutExpired(const boost::system::error_code &error)
{
    if (!error && m_readresult == READ_RESULT::READ_INPROGRESS)
        m_readresult = READ_RESULT::READ_TIMEOUT;
}

void timed_serial_port::readCompleted(const boost::system::error_code &error,
                                      const size_t bytesTransferred)
{
    if (!error)
    {
        m_readresult = READ_RESULT::READ_SUCCESS;
        m_bytesTransferred = bytesTransferred;
        return;
    }

//In case a asynchronous operation is cancelled due to a timeout,
//each OS seems to have its way to react.
#ifdef _WIN32
    if (error.value() == 995)
        return; //Windows spits out error 995
#elif defined(__APPLE__)
    if (error.value() == 45)
    {
        //Bug on OS X, it might be necessary to repeat the setup
        //http://osdir.com/ml/lib.boost.asio.user/2008-08/msg00004.html
        performReadSetup(m_setupParameters);
        return;
    }
#else //Linux
    if (error.value() == 125)
        return; //Linux outputs error 125
#endif

    m_readresult = READ_RESULT::READ_ERROR;
}
