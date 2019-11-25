#pragma once

#include <boost/log/trivial.hpp>
#include <string>

namespace tom
{
using severity = boost::log::trivial::severity_level;
void init_log();
void init_log2();
void logging_data(const std::string &);
void logging_event(severity, const std::string &);
} // namespace tom
