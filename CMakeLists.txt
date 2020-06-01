cmake_minimum_required(VERSION 2.60)
project(troia C CXX)

set(CMAKE_CXX_STANDARD 11)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(troia/net)

add_subdirectory(examples/TcpServer)