#include <iostream>
#include <gtest/gtest.h>
#include <stack>
#include <cstdlib>

#include "StackArrayDouble.h"

using namespace std;
class StackArrayDoubleTest : public testing::Test
{
protected:
    void SetUp() override
    {
        size = 1000;
        for (int i = 0; i < size; i++)
            stack2.push(i);
    }

    StackArrayDouble<int> stack1;
    StackArrayDouble<int> stack2;
    size_t size;
};

TEST_F(StackArrayDoubleTest, isEmptyInitially)
{
    ASSERT_EQ(stack1.size(), 0) << "Expected empty stack initially, but got non zero size.\n";
}

TEST_F(StackArrayDoubleTest, popThrowsExceptionWhenEmpty)
{
    ASSERT_THROW(stack1.pop(), out_of_range) << "Expected pop to throw out of range error, but got nothing.\n";
}

TEST_F(StackArrayDoubleTest, correctSizeAtPush)
{
    for (int i = 0; i < size; i++)
    {
        ASSERT_NO_THROW(stack1.push(i)) << "Threw exception when none was expected.\n";
        ASSERT_EQ(stack1.size(), i + 1) << "Mismatch size error when pushing.\n";
        ASSERT_EQ(stack1.top(), i) << "Mismatch in expected top value and received value.\n";
    }
}

TEST_F(StackArrayDoubleTest, isEmptyWorks)
{
    ASSERT_EQ(stack1.isEmpty(), true) << "Expected isEmpty() to return true when empty\n";
    stack1.push(1);
    ASSERT_EQ(stack1.isEmpty(), false) << "Expected isEmpty() to return false when not empty\n";
}

TEST_F(StackArrayDoubleTest, topThrowsExceptionWhenEmpty)
{
    ASSERT_THROW(stack1.top(), out_of_range) << "Expected top to throw out of range error, but got nothing.\n";

    stack1.push(1);
    stack1.pop();

    ASSERT_THROW(stack1.top(), out_of_range) << "Expected top to throw out of range error, but got nothing.\n";
}

TEST_F(StackArrayDoubleTest, topCorrectValue)
{
    for (int i = size - 1; i >= 0; i--)
    {
        ASSERT_EQ(stack2.top(), i) << "Mismatch in expected top value and received value.\n";
        ASSERT_NO_THROW(stack2.pop()) << "Threw exception when none was expected.\n";
    }
}

TEST_F(StackArrayDoubleTest, topCorrectValueRandom)
{
    stack<int> groundTruth;
    srand(1);

    for (int i = 0; i < size; i++)
    {
        int value = rand() % 10000;
        stack1.push(value);
        groundTruth.push(value);
    }

    while (!stack1.isEmpty())
    {
        ASSERT_EQ(stack1.top(), groundTruth.top());
        stack1.pop();
        groundTruth.pop();
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}