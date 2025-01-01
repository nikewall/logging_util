#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <format>

#include "logger.hpp"

Logger::Logger(const LogLevel &log_level)
  : log_level_(log_level), output_stream_(&std::cout), alloc_(false)
{ }

Logger::Logger(const LogLevel &log_level, const std::string &log_file)
  : log_level_(log_level), output_stream_(new std::ofstream(log_file))
  , alloc_(true)
{ }

Logger::~Logger()
{
  if (alloc_) {
    delete output_stream_;
  }
}

std::string Logger::log_level_to_string(const LogLevel &level) {
  switch(level) {
    case kLogDebug: return "DEBUG";
    case kLogWarning: return "WARN";
    case kLogError: return "ERROR";
    default: return "???";
  }
}

std::string Logger::currtime_str() {
  auto now = std::chrono::system_clock::now();
  auto local_time = std::chrono::zoned_time{std::chrono::current_zone(), now};

  return std::format("{:%H:%M:%S}", local_time);
}

std::string Logger::buff_to_string(const uint8_t* entry, size_t size) {
  std::string output_str;
  output_str.reserve(2 * size); // prealloc 2char/bytes

  for (size_t i = 0; i < size; i++) {
    output_str += std::format("{:02x} ", entry[i]);
  }

  return output_str;
}

std::string Logger::format_output(const LogLevel &level, const std::string &label,
                                  const std::string &entry)
{
  return std::format("{} [{}]: ({}) {}\n", currtime_str(),
                     log_level_to_string(level), label, entry);
}

