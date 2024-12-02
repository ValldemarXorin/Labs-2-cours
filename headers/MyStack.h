//
// Created by vova3 on 29.11.2024.
//

#ifndef LABS_2_COURS_MYSTACK_H
#define LABS_2_COURS_MYSTACK_H
#include <stdexcept>

template <typename TNode>
struct StackNode {
    TNode data;
    StackNode* next;

    explicit StackNode(const TNode& value) : data(value), next(nullptr) {};
};

template <typename TStack>
class MyStack {
    StackNode<TStack>* top;

public:

    MyStack();

    ~MyStack();

    void push(const TStack& value);

    void pop();

    bool is_empty() const;

    template <typename T>
    T get(int index) const;
};
#endif //LABS_2_COURS_MYSTACK_H
