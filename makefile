set: 
	cd build; make

double_test:
	cd build; ./double_tests --gtest_fail_fast

linear_test:
	cd build; ./linear_test --gtest_fail_fast

linked_test:
	cd build; ./linked_test --gtest_fail_fast