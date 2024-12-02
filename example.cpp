#include "logger.hpp"

int main() {
  auto log_level = Logger::kLogWarning;

  Logger my_logger(log_level);
  my_logger.print(Logger::kLogDebug, "1. you shouldn't see me");
  my_logger.print(Logger::kLogError, "2. An error occurred");
  my_logger.print(Logger::kLogWarning, "3. Maybe take a look at this");

  Logger file_logger(log_level, "my_logfile.txt");
  file_logger.print(Logger::kLogDebug, "1. you shouldn't see me");
  file_logger.print(Logger::kLogError, "2. An error occurred");
  file_logger.print(Logger::kLogWarning, "3. Maybe take a look at this");

  return 0;
}
