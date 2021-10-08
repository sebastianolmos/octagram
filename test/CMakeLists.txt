add_executable(
    DummyTests
    testDummyPolygon.cpp
    testDummyPoint.cpp
)

add_executable(
    PointClassTests
    testIntPoint.cpp
)

add_executable(
    VectorClassTests
    testIntVector.cpp
)

add_executable(
    SegmentClassTests
    testIntSegment.cpp
)

add_executable(
    PolygonClassTests
    testPolygonControl.cpp
)


set(LIBS gtest_main octagramLib)

#https://google.github.io/googletest/quickstart-cmake.html
target_link_libraries(DummyTests ${LIBS})
target_link_libraries(PointClassTests ${LIBS})
target_link_libraries(VectorClassTests ${LIBS})
target_link_libraries(SegmentClassTests ${LIBS})
target_link_libraries(PolygonClassTests ${LIBS})

include(GoogleTest)
gtest_discover_tests(DummyTests)
gtest_discover_tests(PointClassTests)
gtest_discover_tests(VectorClassTests)
gtest_discover_tests(SegmentClassTests)
gtest_discover_tests(PolygonClassTests)