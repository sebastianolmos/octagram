if(EXISTS "D:/projects/octagram/build/test/DummyTests[1]_tests.cmake")
  include("D:/projects/octagram/build/test/DummyTests[1]_tests.cmake")
else()
  add_test(DummyTests_NOT_BUILT DummyTests_NOT_BUILT)
endif()
