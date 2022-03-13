cmake_minimum_required(VERSION 3.22.2)



add_library(rational STATIC rational.cpp rational.h)

add_executable(main main.cpp)

target_link_libraries(main rational)