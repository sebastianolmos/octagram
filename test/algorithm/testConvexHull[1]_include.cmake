if(EXISTS "/home/sebastolmos/projects/octagram/test/algorithm/testConvexHull[1]_tests.cmake")
  include("/home/sebastolmos/projects/octagram/test/algorithm/testConvexHull[1]_tests.cmake")
else()
  add_test(testConvexHull_NOT_BUILT testConvexHull_NOT_BUILT)
endif()
