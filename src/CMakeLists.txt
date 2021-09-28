set(HPP_LIST 
    "${PROJECT_SOURCE_DIR}/include/octagram/polygon.hpp"
    "${PROJECT_SOURCE_DIR}/include/octagram/point.hpp")
set(CPP_LIST "polygon.cpp")

add_library(octagramLib ${CPP_LIST} ${HEADER_LIST})
target_include_directories(octagramLib PUBLIC ../include)