set(HPP_LIST 
    "${PROJECT_SOURCE_DIR}/include/octagram/sampling/generation.hpp"
    "${PROJECT_SOURCE_DIR}/include/octagram/sampling/timer.hpp")
set(CPP_LIST 
    "generation.cpp"
    "timer.cpp")

add_library(samplingLib ${CPP_LIST} ${HEADER_LIST})
target_include_directories(samplingLib PUBLIC ${PROJECT_SOURCE_DIR}/include)
