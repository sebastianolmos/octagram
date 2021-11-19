set(HPP_LIST 
    "${PROJECT_SOURCE_DIR}/include/octagram/util/random.hpp")
set(CPP_LIST "random.cpp")

add_library(randomLib ${CPP_LIST} ${HEADER_LIST})
target_include_directories(randomLib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(testRan testRan.cpp)
target_link_libraries(testRan randomLib)