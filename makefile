help:
	@echo "Run 'make set' to set up testing"
	@echo "Run 'make double_test' to test implementation of StackArrayDouble"
	@echo "Run 'make linear_test' to test implementation of StackArrayLinear"

set: 
	cd build; make

double_test:
	cd build; ./double_tests --gtest_fail_fast

linear_test:
	cd build; ./linear_test --gtest_fail_fast