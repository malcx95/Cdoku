cmake_minimum_required(VERSION 3.3)
project(Sudoku)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
#set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB Sudoku_SRC
    "*.c",
    ".h")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(sudoku ${Sudoku_SRC})
target_link_libraries(sudoku ${CURSES_LIBRARIES})

