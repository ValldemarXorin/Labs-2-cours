//
// Created by vova3 on 29.11.2024.
//
#include "../headers/MyStack.h"


template <typename TStack>
MyStack<TStack>::~MyStack() {
    while (!is_empty()) {
        StackNode<TStack>* temp_node = top;
        top = top->next;
        delete temp_node;
    }
}


template <typename TStack>
bool MyStack<TStack>::is_empty() const {
    return top == nullptr;
}


template <typename TStack>
void MyStack<TStack>::push(const TStack &value) {
    auto node = new StackNode<TStack>(value);
    if (is_empty())
        top = node;
    else {
        node->next = top;
        top = node;
    }
}


template <typename TStack>
void MyStack<TStack>::pop() {
    if (is_empty())
        throw std::out_of_range("The element can not deleted because stack is empty");
    StackNode<TStack>* temp_node = top;
    top = top->next;
    delete temp_node;
}

template <typename TStack>
template <typename T>
T MyStack<TStack>::get(int index) const {
    if (index < 0) {
        throw std::out_of_range("Index cannot be negative");
    }

    StackNode<TStack>* current = top;
    int currentIndex = 0;

    while (current != nullptr) {
        if (currentIndex == index) {
            return static_cast<T>(current->data);
        }
        current = current->next;
        currentIndex++;
    }

    throw std::out_of_range("Index out of range");
}