cmake_minimum_required(VERSION 3.15)
project(Sockets)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sockets server.cpp)
target_link_libraries(Sockets ws2_32)