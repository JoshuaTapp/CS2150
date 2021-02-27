#include "stack.h"

stack::stack() {
    this->List = new list<int>;
};

stack::~stack() {
    delete this->List;
}

void stack::push(int e) {
    this->List->push_back(e);
}

void stack::pop() {
    if(!this->List->empty())  this->List->pop_back();
}

int stack::top() {
    return this->List->back();
}

bool stack::empty() {
    return (this->List->empty()) ? true : false;
}