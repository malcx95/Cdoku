cmake_minimum_required(VERSION 3.3)
project(Cdoku)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
#set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_BUILD_TYPE Debug)

file(GLOB Cdoku_SRC
    "*.c",
    ".h")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(cdoku ${Cdoku_SRC})
target_link_libraries(cdoku ${CURSES_LIBRARIES})

