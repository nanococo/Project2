cmake_minimum_required(VERSION 3.15)
project(Client)

set(CMAKE_CXX_STANDARD 14)

add_executable(Client client.cpp)
target_link_libraries(Client ws2_32)