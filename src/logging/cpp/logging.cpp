#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/expressions.hpp>

#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

#include <boost/log/sinks/text_file_backend.hpp>

#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/channel_logger.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>

#include <boost/log/attributes/scoped_attribute.hpp>
#include <boost/log/attributes/current_thread_id.hpp>

#include <boost/log/support/date_time.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>

#include <boost/log/attributes/current_process_name.hpp>

#include <string>

#include "../include/logging.hpp"

namespace tom
{

// https://www.scalyr.com/blog/getting-started-quickly-c-logging/
void init_log()
{
  namespace logging = boost::log;
  namespace expr = boost::log::expressions;
  namespace keywords = boost::log::keywords;
  // namespace sinks = boost::log::sinks;
  // namespace src = boost::log::sources;
  namespace attrs = boost::log::attributes;

  boost::log::register_simple_formatter_factory<logging::trivial::severity_level, char>("Severity");

  logging::add_common_attributes();
  logging::add_file_log(
      keywords::file_name = "out.log",
      keywords::format = "%Message%");
  logging::add_console_log(std::cout, keywords::format = "[%TimeStamp%][%Severity%][%ThreadID%]: %Message%");

  logging::core::get()->add_global_attribute("ProgramId", attrs::constant<int>(42));
  logging::core::get()->add_global_attribute("HipotId", attrs::counter<int>(0, 4)); // max 4 stations

  /* a more verbose alternative with lambda
    https://stackoverflow.com/questions/15853981/boost-log-2-0-empty-severity-level-in-logs/24221423#24221423

    keywords::format = (expr::stream
                        << '['
                        << expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S")
                        << "]["
                        //  << logging::trivial::severity
                        << expr::attr<logging::trivial::severity_level>("Severity")
                        << "]["
                        << expr::attr<attrs::current_thread_id::value_type>("ThreadID")
                        << "]: " << expr::smessage)
    */
}

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;
namespace attrs = boost::log::attributes;
namespace expr = boost::log::expressions;

BOOST_LOG_ATTRIBUTE_KEYWORD(tag_attr, "Tag", std::string)
BOOST_LOG_ATTRIBUTE_KEYWORD(channel, "Channel", std::string)

void init_log2()
{

  logging::core::get()->add_global_attribute(
      "Process",
      attrs::current_process_name());
  logging::add_common_attributes();

  logging::register_simple_formatter_factory<
      boost::log::trivial::severity_level, char>("Severity");

  // data channel
  logging::add_file_log(
      keywords::target = "logs/",
      keywords::file_name = "data-%y%m%d_%5N.log",
      keywords::max_files = 356, // maximum number of stored files, 1 year
      keywords::rotation_size = 50 * 1024 * 1024,                                   /*< rotate the file upon reaching 5 MiB size... >*/
      keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0), /*< ...or every day, at midnight, whichever comes first >*/
      keywords::scan_method = sinks::file::scan_matching,
      keywords::filter = expr::has_attr(channel) && channel == "data",
      keywords::format = "[%TimeStamp%][%Process%]: %Message%");

  // event channel
  logging::add_file_log(
      keywords::target = "logs/",
      keywords::file_name = "event.log", /*< active file name pattern >*/
      keywords::target_file_name = "event_%5N.log",
      keywords::max_files = 356, // maximum number of stored files, 1 year
      keywords::rotation_size = 50 * 1024 * 1024,
      keywords::scan_method = sinks::file::scan_matching,
      keywords::filter = (expr::has_attr(channel) && channel == "event") && (logging::trivial::severity >= logging::trivial::debug),
      keywords::format = "[%TimeStamp%][%Severity%][%Process%]: %Message%");

  logging::add_console_log(std::cout,
                           keywords::format = "[%TimeStamp%|%Process%]>> %Message%");

  // logging::core::get()->set_filter(logging::trivial::severity >=
  //                                  logging::trivial::debug);
}

void logging_event(logging::trivial::severity_level lvl, const std::string &message)
{
  src::severity_channel_logger_mt<
      logging::trivial::severity_level, // the type of the severity level
      std::string                       // the type of the channel name
      >
      slg(keywords::channel = "events");

  BOOST_LOG_SEV(slg, lvl) << message;
}

void logging_data(const std::string &message)
{
  BOOST_LOG_SCOPED_THREAD_TAG("Tag", "IMPORTANT_MESSAGE");
  static src::channel_logger_mt<> lg(keywords::channel = "data");

  BOOST_LOG(lg) << message;
}
} // namespace tom