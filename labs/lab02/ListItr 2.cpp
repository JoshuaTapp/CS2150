/**
Author: Joshua Tapp
CompID: jct7bm
Date: 2/20/2021 14:19
File Name: ListItr.cpp

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 2
**/
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"


ListItr::ListItr() {}

ListItr::ListItr(ListNode* theNode){
    this->current = theNode;
}

bool ListItr::isPastEnd() const {
    if(this->current->next == NULL && this->current->previous != NULL){
        return true;
    }
    else return false;
}

bool ListItr::isPastBeginning() const {
    if(this->current->previous == NULL && this->current->next != NULL){
        return true;
    }
    else return false;
}
void ListItr::moveForward(){
    if( !( this->isPastEnd() ) ) {
        this->current = this->current->next;
    }
}

void ListItr::moveBackward(){
    if( !( this->isPastBeginning() ) ) {
        this->current = this->current->previous;
    }
}

int ListItr::retrieve() const {
    return current->value;
}

    
  
