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
    this->stack1 = new stack<string>();
    this->stack2 = new stack<string>();
    string token;
    while (cin >> token) {
        if(checkInteger(token)) { 
            this->stack1->push(token); // this is numbers only stack
        }

        else {
            this->stack2->push(token);
        }

    }

 };

 postfixCalculator::~postfixCalculator() {
    delete this->stack1;
    delete this->stack2;
 }

void postfixCalculator::calculate() {

}


bool checkInteger(const string str){
  return str.find_first_not_of( "-0123456789" ) == -1; // check if string is integer
}