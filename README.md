# Programming Assignment 1
## Stacks in three ways

This programming assignment will have you writing the stack data structure in three different approaches. You will be expected to complete a report comparing your three implementations. There is an optional bonus assignment as well for 5%.

## Table of Contents

- [Project Description](#project-description)
- [Installation](#installation)
- [Usage](#usage)

## Project Description

In this programming assignment, **you are expected to modify StackArrayDouble.h, StackArrayLinear.h and StackLinkedList.h**. You are provided with an additional file **AbstractStack.h** which defines the base class from which the other three implementations are derived from.

The following functions have been defined in the abstract class and must be implemented in each of the three derived implementations. This is where you come in :)

```cpp
virtual bool isEmpty() = 0;
virtual int size() = 0;
virtual T &top() = 0;
virtual T pop() = 0;
virtual void push(const T &e) = 0;
```

## Installation

Explain how to install and set up the project on a local machine. Include any dependencies or prerequisites that need to be installed.

## Usage

Provide instructions on how to use the project, including any command-line arguments, input/output formats, or specific steps to follow.

## Contributing

Explain how others can contribute to the project, such as reporting issues, suggesting improvements, or submitting pull requests.