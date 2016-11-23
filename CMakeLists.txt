cmake_minimum_required(VERSION 3.2)
project(simpleDB)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(SOURCE_FILES main.cpp)

add_executable(simpleDB ${SOURCE_FILES} src/Database.cpp src/Database.hpp src/Command.cpp src/Command.hpp src/Printer.cpp src/Printer.hpp src/Reader.cpp src/Reader.hpp src/Transaction.cpp src/Transaction.hpp)
