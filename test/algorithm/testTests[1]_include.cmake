if(EXISTS "/home/sebastolmos/projects/octagram/test/algorithm/testTests[1]_tests.cmake")
  include("/home/sebastolmos/projects/octagram/test/algorithm/testTests[1]_tests.cmake")
else()
  add_test(testTests_NOT_BUILT testTests_NOT_BUILT)
endif()
