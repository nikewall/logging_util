#include "logger.hpp"

int main() {
  auto log_level = Logger::kLogWarning;

  const std::string general = "GENERAL";
  const std::string my_fn = "DATA_HANDLER";
  uint8_t buff[] = {0xba, 0xad, 0xf0, 0x0d};

  Logger my_logger(log_level);
  my_logger.print(Logger::kLogDebug, general, "1. you shouldn't see me");
  my_logger.print(Logger::kLogError, general, "2. An error occurred");
  my_logger.print(Logger::kLogWarning, general, "3. Maybe take a look at this");
  my_logger.print(Logger::kLogWarning, my_fn, (void*)buff, 0);
  my_logger.print(Logger::kLogWarning, my_fn, (void*)buff, sizeof(buff));

  //Logger file_logger(log_level, "my_logfile.txt");
  //file_logger.print(Logger::kLogDebug, "1. you shouldn't see me");
  //file_logger.print(Logger::kLogError, "2. An error occurred");
  //file_logger.print(Logger::kLogWarning, "3. Maybe take a look at this");

  return 0;
}
