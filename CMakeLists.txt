cmake_minimum_required(VERSION 3.22.1)
project(Doodle-Jump)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Doodle-Jump main.cpp)
target_link_libraries(Doodle_Jump sfml-graphics sfml-audio)