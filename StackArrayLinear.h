#ifndef STACK_LINEAR_ARRAY_H
#define STACK_LINEAR_ARRAY_H
#include "AbstractStack.h"

template <typename T>
class StackArrayLinear : public AbstractStack<T> {
private:
    T* data;
    int length;
    int topIndex;

public:
    StackArrayLinear();

    ~StackArrayLinear();

    StackArrayLinear(const StackArrayLinear& other);

    StackArrayLinear& operator=(const StackArrayLinear& other);

    bool isEmpty();

    int size();

    T& top();

    T pop();

    void push(const T& e);

};

template <typename T>
StackArrayLinear<T>::StackArrayLinear(){
    length = 10;
    data = new T[length];
    topIndex = -1;
}

template <typename T>
StackArrayLinear<T>::~StackArrayLinear(){
    delete[] data;
}

template <typename T>
StackArrayLinear<T>::StackArrayLinear(const StackArrayLinear& other) {
    topIndex = other.topIndex;
    data = new T[other.length];
    for (int i = 0; i <= topIndex; ++i) {
        data[i] = other.data[i];
    }
    length = other.length;
}

template <typename T>
StackArrayLinear<T>& StackArrayLinear<T>::operator=(const StackArrayLinear& other) {
    if (this != &other) {
        topIndex = other.topIndex;
        delete[] data;
        data = new T[other.length];
        for (int i = 0; i <= other.topIndex; ++i) {
            data[i] = other.data[i];
        }
        length = other.length;
    }
    return *this;
}

template <typename T>
bool StackArrayLinear<T>::isEmpty(){
    return topIndex == -1;
}

template <typename T>
int StackArrayLinear<T>::size(){
    return topIndex + 1;
}

template <typename T>
T& StackArrayLinear<T>::top(){
    if (isEmpty()){
        throw std::out_of_range("Stack top out_of_range");
    }
    return data[topIndex];
}

template <typename T>
T StackArrayLinear<T>::pop(){
    if (isEmpty()){
        throw std::out_of_range("Stack pop out_of_range");
    }
    return data[topIndex--];
}

template <typename T>
void StackArrayLinear<T>::push(const T& e){
    if(topIndex == length - 1){
        T* temp = new T[length + 10];
        for(int i = 0; i < length; i++){
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        length += 10;
    }
    data[++topIndex] = e;
}

#endif