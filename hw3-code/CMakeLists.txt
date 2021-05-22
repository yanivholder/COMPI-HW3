cmake_minimum_required(VERSION 3.17)
project(hw3_code)

set(CMAKE_CXX_STANDARD 11)

add_executable(hw3_code main.cpp hw3-output.cpp sym_tables.cpp lex.yy.c parser.tab.cpp)
add_executable(tests main.cpp sym_tables.cpp  hw3-output.cpp)
