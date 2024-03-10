#ifndef STACK_LinkedList_H
#define STACK_LinkedList_H
#include "AbstractStack.h"

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
};

template <typename T>
class StackLinkedList : public AbstractStack<T>{
private:
    Node<T>* head;
    int length;
public:
    StackLinkedList();

    ~StackLinkedList();

    StackLinkedList(const StackLinkedList& other);

    StackLinkedList& operator=(const StackLinkedList& other);

    bool isEmpty();

    int size();

    T& top();

    T pop();

    void push(const T& e);

};

// Your implementation here
template <typename T>
StackLinkedList<T>::StackLinkedList(){
    head = nullptr;
    length = 0;
}

template <typename T>
StackLinkedList<T>::~StackLinkedList(){
    Node<T>* temp = head;
    while(temp != nullptr){
        Node<T>* temp2 = temp;
        temp = temp->next;
        delete temp2;
    }
}

template <typename T>
StackLinkedList<T>::StackLinkedList(const StackLinkedList& other) {
    head = nullptr;
    length = other.length;

    Node<T>* temp = other.head;
    Node<T>* tail = nullptr;

    while (temp != nullptr) {
        Node<T>* node = new Node<T>();

        if (head == nullptr) {
            head = node;
        }

        if (tail != nullptr) {
            tail->next = node;
        }

        node->data = temp->data;
        tail = node;
        temp = temp->next;
    }

    if (tail != nullptr) {
        tail->next = nullptr;
    }
   
}

template <typename T>
StackLinkedList<T>& StackLinkedList<T>::operator=(const StackLinkedList& other) {
    if (this != &other) {
        Node<T>* temp = head;
        while(temp != nullptr) {
            Node<T>* temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
        
        head = nullptr;
        temp = other.head;
        length = other.length;
        Node<T>* tail = nullptr;

        while (temp != nullptr) {
            Node<T>* node = new Node<T>();

            if (head == nullptr) {
                head = node;
            }

            if (tail != nullptr) {
                tail->next = node;
            }

            node->data = temp->data;
            tail = node;
            temp = temp->next;
        }

        if (tail != nullptr) {
            tail->next = nullptr;
        }
    }
    return *this;
}

template <typename T>
bool StackLinkedList<T>::isEmpty(){
    return length == 0;
}

template <typename T>
int StackLinkedList<T>::size(){
    return length;
}

template <typename T>
T& StackLinkedList<T>::top(){
   if(isEmpty()){
        throw std::out_of_range("Stack top out_of_range");
    }
    return head->data;
}

template <typename T>
T StackLinkedList<T>::pop(){
    if(isEmpty()) {
        throw std::out_of_range("Stack pop out_of_range");
    }
    Node<T>* temp = head;
    head = head->next;
    T pop_data = temp->data;
    delete temp;
    length--;
    return pop_data;
}

template <typename T>
void StackLinkedList<T>::push(const T& e){
    Node<T>* temp = new Node<T>();
    temp->data = e;
    temp->next = head;
    head = temp;
    length++;
}
#endif