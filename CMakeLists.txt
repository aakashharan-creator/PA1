cmake_minimum_required(VERSION 3.12) # version can be different

project(my_cpp_project) #name of your project

enable_testing() #to  discover tests in test explorer 

add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

add_executable(double_tests double_test.cpp) # add this executable
add_executable(linear_test linear_test.cpp) # add this executable
add_executable(linked_test linked_list.cpp) # add this executable

target_link_libraries(double_tests PRIVATE gtest) # link google test to this executable
target_link_libraries(linear_test PRIVATE gtest) # link google test to this executable
target_link_libraries(linked_test PRIVATE gtest) # link google test to this executable

include(GoogleTest)
gtest_discover_tests(double_tests) # discovers tests by asking the compiled test executable to enumerate its tests
gtest_discover_tests(linear_test) # discovers tests by asking the compiled test executable to enumerate its tests
gtest_discover_tests(linked_test) # discovers tests by asking the compiled test executable to enumerate its tests