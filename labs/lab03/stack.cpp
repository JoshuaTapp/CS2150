#include "stack.h"

stack::stack() {
    this->stackList = new List();
};

stack::~stack() {
    delete this->stackList;
}

void stack::push(int e) {
    this->stackList->push_back(e);
}

void stack::pop() {
    if(!this->stackList->empty())  this->stackList->pop_back();
}

int stack::top() {
    return this->stackList->back();
}

bool stack::empty() {
    return (this->stackList->empty()) ? true : false;
}