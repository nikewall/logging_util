#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Logger {
public:
  enum LogLevel {
    kLogDebug = 0,
    kLogWarning,
    kLogError,
    kLogNumTypes
  };

  Logger(const LogLevel &log_level);
  Logger(const LogLevel &log_level, const std::string &log_file);
  ~Logger();

  void print(const LogLevel &desired_level, const std::string &string);

private:
  std::string log_level_to_string(const LogLevel &level);

  LogLevel log_level_;
  std::ostream* output_stream_;
  bool alloc_;
};
