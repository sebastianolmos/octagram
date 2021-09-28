add_executable(
    DummyTests
    testDummyPolygon.cpp
    testDummyPoint.cpp
)

#https://google.github.io/googletest/quickstart-cmake.html
target_link_libraries(
        DummyTests
        gtest_main
        octagramLib
)

include(GoogleTest)
gtest_discover_tests(DummyTests)