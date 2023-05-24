cmake_minimum_required(VERSION 3.22.1)
project(mytest)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(mytest main.cpp)

target_link_libraries(mytest sfml-graphics sfml-audio)