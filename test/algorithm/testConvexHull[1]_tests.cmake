add_test( intConvexHull.giftWrappingBasicTest /home/sebastolmos/projects/octagram/bin/testConvexHull [==[--gtest_filter=intConvexHull.giftWrappingBasicTest]==] --gtest_also_run_disabled_tests)
set_tests_properties( intConvexHull.giftWrappingBasicTest PROPERTIES WORKING_DIRECTORY /home/sebastolmos/projects/octagram/test/algorithm SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( intConvexHull.giftWrappingTest1 /home/sebastolmos/projects/octagram/bin/testConvexHull [==[--gtest_filter=intConvexHull.giftWrappingTest1]==] --gtest_also_run_disabled_tests)
set_tests_properties( intConvexHull.giftWrappingTest1 PROPERTIES WORKING_DIRECTORY /home/sebastolmos/projects/octagram/test/algorithm SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( intConvexHull.giftWrappingSortTest /home/sebastolmos/projects/octagram/bin/testConvexHull [==[--gtest_filter=intConvexHull.giftWrappingSortTest]==] --gtest_also_run_disabled_tests)
set_tests_properties( intConvexHull.giftWrappingSortTest PROPERTIES WORKING_DIRECTORY /home/sebastolmos/projects/octagram/test/algorithm SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( intConvexHull.grahamScanBasicTest /home/sebastolmos/projects/octagram/bin/testConvexHull [==[--gtest_filter=intConvexHull.grahamScanBasicTest]==] --gtest_also_run_disabled_tests)
set_tests_properties( intConvexHull.grahamScanBasicTest PROPERTIES WORKING_DIRECTORY /home/sebastolmos/projects/octagram/test/algorithm SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( intConvexHull.grahamScanTest1 /home/sebastolmos/projects/octagram/bin/testConvexHull [==[--gtest_filter=intConvexHull.grahamScanTest1]==] --gtest_also_run_disabled_tests)
set_tests_properties( intConvexHull.grahamScanTest1 PROPERTIES WORKING_DIRECTORY /home/sebastolmos/projects/octagram/test/algorithm SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( intConvexHull.grahamScanSortTest /home/sebastolmos/projects/octagram/bin/testConvexHull [==[--gtest_filter=intConvexHull.grahamScanSortTest]==] --gtest_also_run_disabled_tests)
set_tests_properties( intConvexHull.grahamScanSortTest PROPERTIES WORKING_DIRECTORY /home/sebastolmos/projects/octagram/test/algorithm SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( testConvexHull_TESTS intConvexHull.giftWrappingBasicTest intConvexHull.giftWrappingTest1 intConvexHull.giftWrappingSortTest intConvexHull.grahamScanBasicTest intConvexHull.grahamScanTest1 intConvexHull.grahamScanSortTest)
