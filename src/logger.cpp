#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>

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

void Logger::print(const LogLevel &desired_level, const std::string &string) {

  if (desired_level < log_level_)
    return;

  time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  auto timestamp = std::put_time(std::localtime(&now), "%T"); // HR:MIN:SEC

  *output_stream_ << "[" << timestamp << "] " 
    << log_level_to_string(desired_level) << ": " 
    << string << "\n";
}
