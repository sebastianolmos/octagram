add_test( algTest.iniTest /home/sebastolmos/projects/octagram/bin/testTests [==[--gtest_filter=algTest.iniTest]==] --gtest_also_run_disabled_tests)
set_tests_properties( algTest.iniTest PROPERTIES WORKING_DIRECTORY /home/sebastolmos/projects/octagram/test/algorithm SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( testTests_TESTS algTest.iniTest)
