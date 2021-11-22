add_executable(
    genRandomPoints
    genRandomPoints.cpp
)

add_executable(
    genHullPoints
    genHullPoints.cpp
)

add_executable(
    runConvexHull
    runConvexHull.cpp
)

target_link_libraries(genRandomPoints octagramLib)
target_link_libraries(genHullPoints octagramLib)
target_link_libraries(runConvexHull octagramLib)