add_test( generation.giftWrappingGenTest1 /home/sebastolmos/projects/octagram/bin/testGeneration [==[--gtest_filter=generation.giftWrappingGenTest1]==] --gtest_also_run_disabled_tests)
set_tests_properties( generation.giftWrappingGenTest1 PROPERTIES WORKING_DIRECTORY /home/sebastolmos/projects/octagram/test/sampling SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( generation.grahamScanGenTest1 /home/sebastolmos/projects/octagram/bin/testGeneration [==[--gtest_filter=generation.grahamScanGenTest1]==] --gtest_also_run_disabled_tests)
set_tests_properties( generation.grahamScanGenTest1 PROPERTIES WORKING_DIRECTORY /home/sebastolmos/projects/octagram/test/sampling SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( testGeneration_TESTS generation.giftWrappingGenTest1 generation.grahamScanGenTest1)