set(HPP_LIST 
    "${PROJECT_SOURCE_DIR}/include/octagram/algorithm/convexhull.hpp")

add_library(algorithmLib INTERFACE ${HEADER_LIST})
target_include_directories(algorithmLib INTERFACE ${PROJECT_SOURCE_DIR}/include)