#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>

#include <boost/log/trivial.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "../include/options.hpp"
#include "../../logging/include/logging.hpp"

namespace tom
{

using namespace boost;
using namespace boost::filesystem;
// using std::cout;
using std::string;
using std::vector;

Port parse(const std::string &line)
{
    vector<std::string> parameters;
    boost::split(parameters, line, boost::is_any_of(",:- "));

    size_t size = parameters.size();

    auto name = parameters.at(0);
    auto baud_rate = size > 1 ? std::stoul(parameters.at(1), nullptr, 0) : 0;
    auto parity = size > 2 ? std::stoul(parameters.at(2), nullptr, 0) : 0;
    auto flow = size > 3 ? std::stoul(parameters.at(3), nullptr, 0) : 0;

    return {name, baud_rate, parity, flow};
}

bool has_settings_file(const path &name)
{
    return exists(name) && is_regular_file(name);
}

auto parse_options(int argc, char *argv[]) -> Options
{
    namespace po = program_options;
    auto settings_file = current_path() / (string(argv[0]) + ".cfg");

    string help =
        R"(Options can be specified through 
- the command line or 
- a setting.txt fileside side by side with the executable"
)";

    Options opt{};

    po::options_description general("General Options");
    general.add_options()("help,h", help.c_str());

    po::options_description serialport("Serial Port Options");
    serialport.add_options()("ports,p", po::value<vector<string>>()->composing(), R"(serial ports,
    Format: <port>:<baud rate>,<parity>,<flow control> 
    Example: 
    - COM1 
    - COM1:1 
    - COM1:1,0 
    - COM1:1,0,0

    Specification: 
    - character size fixed to 8 bits non-changable   
    - stop_bits fixed to 1
    - baud rate:  
      0: 9600(default), 1: 19200, 2: 38400 
    - parity: 
      0: none(default), 1: odd, 2: even 
    - flow control: 
      0: none(default), 1: software 
    )");

    po::options_description all("Allowed Options");
    all.add(general)
        .add(serialport);

    // loading from cmd line, allowing unregistered options
    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv)
                  .options(all)
                  .allow_unregistered()
                  .run(),
              vm);

    // load from file if any
    if (has_settings_file(settings_file))
    {
        BOOST_LOG_TRIVIAL(info) << "Loaded configuration from " << settings_file << "\n";
        po::store(po::parse_config_file<char>(settings_file.string().c_str(), all, true), vm);
    }

    po::notify(vm);

    if (vm.count("help"))
    {
        BOOST_LOG_TRIVIAL(info) << all << "\n";
    }
    else
    {
        if (vm.count("ports"))
        {
            auto ports = vm["ports"].as<std::vector<std::string>>();
            std::for_each(ports.begin(), ports.end(), [&opt](auto &&port) {
                opt.ports.push_back(parse(port));
            });
        }
        else
        {
            BOOST_LOG_TRIVIAL(error) << "no serial port specified.";
            std::exit(0);
        }
    }

    return opt;
}
} // namespace tom
