#ifndef STACK_DOUBLE_ARRAY_H
#define STACK_DOUBLE_ARRAY_H
#include "AbstractStack.h"

template <typename T>
class StackArrayDouble : public AbstractStack<T>
{
private:
    T *data;
    int length;
    int topIndex;

public:
    StackArrayDouble();

    ~StackArrayDouble();

    StackArrayDouble(const StackArrayDouble &other);

    StackArrayDouble &operator=(const StackArrayDouble &other);

    bool isEmpty();

    int size();

    T &top();

    T pop();

    void push(const T &e);
};

template <typename T>
StackArrayDouble<T>::StackArrayDouble()
{
    length = 10;
    data = new T[length];
    topIndex = -1;
}

template <typename T>
StackArrayDouble<T>::~StackArrayDouble()
{
    // delete[] data;
}

template <typename T>
StackArrayDouble<T>::StackArrayDouble(const StackArrayDouble &other)
{
    topIndex = other.topIndex;
    data = new T[other.length];
    for (int i = 0; i <= topIndex; ++i)
    {
        data[i] = other.data[i];
    }
    length = other.length;
}

template <typename T>
StackArrayDouble<T> &StackArrayDouble<T>::operator=(const StackArrayDouble &other)
{
    if (this != &other)
    {
        topIndex = other.topIndex;
        delete[] data;
        data = new T[other.length];
        for (int i = 0; i <= other.topIndex; ++i)
        {
            data[i] = other.data[i];
        }
        length = other.length;
    }
    return *this;
}

template <typename T>
bool StackArrayDouble<T>::isEmpty()
{
    return topIndex == -1;
}

template <typename T>
int StackArrayDouble<T>::size()
{
    return topIndex + 1;
}

template <typename T>
T &StackArrayDouble<T>::top()
{
    if (isEmpty())
    {
        throw std::out_of_range("Stack top out_of_range");
    }
    return data[topIndex];
}

template <typename T>
T StackArrayDouble<T>::pop()
{
    if (isEmpty())
    {
        throw std::out_of_range("Stack pop out_of_range");
    }
    return data[topIndex--];
}

template <typename T>
void StackArrayDouble<T>::push(const T &e)
{
    if (topIndex == length - 1)
    {
        T *temp = new T[length * 2];
        for (int i = 0; i < length; i++)
        {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        length *= 2;
    }
    data[++topIndex] = e;
}

#endif