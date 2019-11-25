#pragma once
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
#include <boost/utility/string_ref.hpp>

#include <iostream>
#include <string>
#include <vector>

namespace tom
{
using namespace boost;
using namespace boost::filesystem;
// using std::cout;
using std::string;

struct Port
{
    string name;
    size_t baud_rate;
    size_t parity;
    size_t flow;
};

Port parse(const std::string &line);

struct Options
{
    std::vector<Port> ports;
};

bool has_settings_file(const path &name);
auto parse_options(int argc, char *argv[]) -> Options;

} // namespace tom
