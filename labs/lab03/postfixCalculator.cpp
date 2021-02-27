/**
 *  Author: Joshua Tapp
 *  CompID: jct7bm
 *  Date: 2/27/2021 14:37
 *  File Name: postfixCalculator.h

 *  Course: UVA's CS2150 Programming and Data Representation
 *
 * Title: LAB 3
 * Description: A calculator that can handle integer inputs and the following operations:
 * addition, subtraction, multiplication, division, and unary negation. All input are in
 * reverse polish notation.
 */


 #include "postfixCalculator.h"

 postfixCalculator::postfixCalculator() {
    this->numStack = new stack<int>();
    string token;
    while (cin >> token) {
        if(!checkOperation(token)) {
            this->numStack->push(stoi(token));
        }
        else {
            this->calculate(token);
        }
    }
    cout << this->numStack->top() << endl;
 };

 postfixCalculator::~postfixCalculator() {
    delete this->numStack;
 }


void postfixCalculator::calculate(string str) {
    char ch = str[0];

    int b = this->numStack->top(); // right side
    if (ch != '~') {
        this->numStack->pop();  // if not negation, pop the top element for this next operation.
    }

    int a = this->numStack->top();
    this->numStack->pop();

    switch(ch) {
        case('+') :
            a += b;
            break;
        case('-') :
            a -= b;
            break;
        case('*') :
            a *= b;
            break;
        case('/') :
            a /= b;
            break;
        case('~') :
            a *= -1;
            break;
    }
    this->numStack->push(a);
}

bool checkOperation(const string str){
    return ( (str.find_first_not_of( "+-*/~" ) == -1) && str.size() == 1) ? true : false; // check if string is integer
}