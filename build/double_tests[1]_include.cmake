if(EXISTS "/Users/aakash_personal/Desktop/TexasA&M/TAMU/CSCE 221/PA1/build/double_tests[1]_tests.cmake")
  include("/Users/aakash_personal/Desktop/TexasA&M/TAMU/CSCE 221/PA1/build/double_tests[1]_tests.cmake")
else()
  add_test(double_tests_NOT_BUILT double_tests_NOT_BUILT)
endif()
