if(EXISTS "/home/sebastolmos/projects/octagram/test/PointClassTests[1]_tests.cmake")
  include("/home/sebastolmos/projects/octagram/test/PointClassTests[1]_tests.cmake")
else()
  add_test(PointClassTests_NOT_BUILT PointClassTests_NOT_BUILT)
endif()
