if(EXISTS "/home/sebastolmos/projects/octagram/test/VectorClassTests[1]_tests.cmake")
  include("/home/sebastolmos/projects/octagram/test/VectorClassTests[1]_tests.cmake")
else()
  add_test(VectorClassTests_NOT_BUILT VectorClassTests_NOT_BUILT)
endif()