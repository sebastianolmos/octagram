add_subdirectory(algorithm)
add_subdirectory(util)
add_subdirectory(sampling)

set(HPP_LIST 
    "${PROJECT_SOURCE_DIR}/include/octagram/polygon.hpp"
    "${PROJECT_SOURCE_DIR}/include/octagram/point.hpp"
    "${PROJECT_SOURCE_DIR}/include/octagram/segment.hpp"
    "${PROJECT_SOURCE_DIR}/include/octagram/vector.hpp")
#set(CPP_LIST "polygon.cpp")

#add_library(octagramLib ${CPP_LIST} ${HEADER_LIST})
add_library(octagramLib INTERFACE ${HEADER_LIST})
#target_include_directories(octagramLib PUBLIC ../include)
target_include_directories(octagramLib INTERFACE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(octagramLib INTERFACE algorithmLib)
target_link_libraries(octagramLib INTERFACE randomLib)
target_link_libraries(octagramLib INTERFACE samplingLib)