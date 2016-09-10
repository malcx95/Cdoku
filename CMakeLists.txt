cmake_minimum_required(VERSION 3.3)
project(Calsole)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" -std=c++11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES main.cpp)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(calsole main.cpp)
target_link_libraries(calsole ${CURSES_LIBRARIES})

