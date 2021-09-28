cmake_minimum_required(VERSION 3.16.3)
project(playPolygon)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(extern)
add_subdirectory(src)
add_subdirectory(test)

enable_testing()