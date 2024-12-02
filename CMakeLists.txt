project(Logger)
cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wpedantic")

add_subdirectory(src)

add_executable(logger_example example.cpp)
target_link_libraries(logger_example
  logger
)
