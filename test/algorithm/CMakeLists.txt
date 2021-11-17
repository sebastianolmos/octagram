add_executable(
    testTests
    testTest.cpp
)

add_executable(
    testConvexHull
    testIntConvexHull.cpp
)

set(LIBS gtest_main octagramLib)

#https://google.github.io/googletest/quickstart-cmake.html
target_link_libraries(testTests ${LIBS})
target_link_libraries(testConvexHull ${LIBS})

include(GoogleTest)
gtest_discover_tests(testTests)
gtest_discover_tests(testConvexHull)