#pragma once

#include <iostream>
#include <string>
#include <concepts>
#include <type_traits>
#include <format>

template <typename T>
concept Loggable =
    std::is_same_v<std::decay_t<T>, char*> || 
    std::is_same_v<std::decay_t<T>, const char*> ||
    std::is_same_v<std::decay_t<T>, std::string> ||
    std::is_same_v<std::decay_t<T>, void*>;

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


  void print(const LogLevel &desired_level, const std::string &label,
             const Loggable auto &entry, size_t size = 0)
  {
    if (desired_level < log_level_)
      return;

    std::string entry_str;
    if constexpr(std::is_same_v<std::decay_t<decltype(entry)>, void*>) {
      if (size == 0) {
        entry_str = "!!LOGGER ERROR!! Invalid use of print with size=0 on raw buffer";
      } else {
        entry_str = buff_to_string(static_cast<const uint8_t*>(entry), size);
      }
    } 
    else 
    {
      entry_str = entry;
    }
  
    *output_stream_ << format_output(desired_level, label, entry_str);
  }

private:
  std::string currtime_str();
  std::string log_level_to_string(const LogLevel &level);
  std::string buff_to_string(const uint8_t* entry, size_t size);

  std::string format_output(const LogLevel &level, const std::string &label, 
                            const std::string &entry);

  LogLevel log_level_;
  std::ostream* output_stream_;
  bool alloc_;
};
