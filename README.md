# Programming Assignment 1
## Stacks in three ways

This programming assignment will have you writing the stack data structure in three different approaches. You will be expected to complete a report comparing your three implementations. There is an optional bonus assignment as well for 5%.

## Table of Contents

- [Project Description](#project-description)
  - [Function Description](#function-description)
  - [Memory Checks](#memory-checks)
- [Testing and Validation](#testing-and-validation)

## Project Description

In this programming assignment, **you are only expected to modify StackArrayDouble.h, StackArrayLinear.h and StackLinkedList.h**. You are provided with an additional file **AbstractStack.h** which defines the base class from which the other three implementations are derived.

The following functions have been defined in the abstract class and must be implemented in each of the three derived implementations along with their respective constructors and destructors. This is where you come in :)

```cpp
virtual bool isEmpty() = 0;
virtual int size() = 0;
virtual T &top() = 0;
virtual T pop() = 0;
virtual void push(const T &e) = 0;
```

### Function Description

```cpp
virtual bool isEmpty() = 0;
```
* `isEmpty` returns whether the current state of the stack is empty i.e. is the current size equal to 0.

```cpp
virtual int size() = 0;
```
* `size` returns the current number of items present in the stack

```cpp
virtual T &top() = 0;
```
* `top` returns the value of the item presently at the top of the stack i.e. the most recently pushed value. If the stack is empty throw a `out_of_range` exception

```cpp
virtual T pop() = 0;
```
* `pop` returns the value at the top of the stack, similar to `top` but also removes this item from the stack.

```cpp
virtual void push(const T& e) = 0
```
* `push` takes in a value of type `T` and pushes it to the top of the stack.

### Memory Checks

Along with implementing the actual data structure itself, you are expected to ensure your code has no memory leaks as well or there will be a point deduction. We will go into further detail on how to detect memory leaks below.

## Testing and Validation

In order to test and validate the running of your code there are a few commands to help you along with a `main.cpp` file if you would like to do your own testing. 

The provided `makefile` grants you some testing functionality with the following commands

`make set` 
* Sets up the testing environment and compiles your code. Make sure to run this command each time you test your code.

`make double_test`
* Runs the test cases for the StackArrayDouble implementation along with a memory check

`make linear_test`
* Runs the test cases for the StackArrayDouble implementation along with a memory check

`make linked_test`
* Runs the test cases for the StackArrayDouble implementation along with a memory check

`make all`
* Runs all test cases and provides a final score for this assignment