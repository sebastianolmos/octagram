add_executable(
    testGeneration
    testGeneration.cpp
)

set(LIBS gtest_main octagramLib)

#https://google.github.io/googletest/quickstart-cmake.html
target_link_libraries(testGeneration ${LIBS})

include(GoogleTest)
gtest_discover_tests(testGeneration)