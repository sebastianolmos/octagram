set(HPP_LIST 
    "${PROJECT_SOURCE_DIR}/include/octagram/util/random.hpp")

add_library(randomLib INTERFACE ${HEADER_LIST})
target_include_directories(randomLib INTERFACE ${PROJECT_SOURCE_DIR}/include)

add_executable(testRan testRan.cpp)
target_link_libraries(testRan randomLib)
