add_executable(
    testTests
    testTest.cpp
)

set(LIBS gtest_main octagramLib)

#https://google.github.io/googletest/quickstart-cmake.html
target_link_libraries(testTests ${LIBS})

include(GoogleTest)
gtest_discover_tests(testTests)