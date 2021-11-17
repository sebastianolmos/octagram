set(HPP_LIST 
    "${PROJECT_SOURCE_DIR}/include/octagram/algorithm/convexhull.hpp")
set(CPP_LIST "convexhull.cpp")

add_library(algorithmLib ${CPP_LIST} ${HEADER_LIST})
target_include_directories(algorithmLib PUBLIC ${PROJECT_SOURCE_DIR}/include)