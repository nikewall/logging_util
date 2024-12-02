# logging_util

### A simple logging utility for C++11 projects

## Features
- Support for stdout and file descriptors
- Three default log levels: DEBUG, WARNING, and ERROR
- *WIP* User-specified log levels
- *WIP* Support for tee-style output forking within one Logger object.

## Building
### Building example executable
This project requires CMake(> 3.16), make, and a C++11 compatible compiler.

To build and run the example executable:
```
mkdir build/
cd build/
cmake ..
make -j 
./logger_example
```

### Building static library (.a)
To build the `logger` static library to link against in your own project,
use `make install`. 
This saves the built `liblogger.a` into build/lib/.
```
mkdir build/
cd build/
cmake ..
make -j install
ls lib/
```
