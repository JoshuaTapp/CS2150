/**
Author: Joshua Tapp
CompID: jct7bm
Date: 2/20/2021 14:19
File Name: List.cpp

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 2
**/


#include "List.h"

List::List() {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;   
}

List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr last(source.head->next);
    while (!last.isPastEnd()) {
        insertAtTail(last.retrieve());
        last.moveForward();
    }
}

List::~List() {
    this->makeEmpty();
    delete this->head;
    delete this->tail;
}

void List::push_back(int e) {
    this->insertAtTail(e);    
}

void List::pop_back() {
    if(this->size() > 0) {
        ListItr last = this->last();
        ListNode *prev      = last.current->previous;
        ListNode *next      = last.current->next;
        
        prev->next          = next;
        next->previous      = prev;

        this->count = this->count - 1;
        delete last.current;
    }
}

int List::back() {
    ListItr last = this->last();
    return last.current->value;
}

bool List::empty() {
    return this->isEmpty();
}


List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr last(source.head->next);
        while (!last.isPastEnd()) {
            insertAtTail(last.retrieve());
            last.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const {
    if(count == 0) {return true;}
    else {return false;}
}

void List::makeEmpty() {
    if(this->isEmpty()) {}
    else {
        ListItr last = this->first();
        for(int i = 0; i < this->size(); i++) {
            last.moveForward();
            delete last.current->previous;
        }
        this->head->next = this->tail;
        this->tail->previous = this->head;
        this->count = 0;
    }
}

ListItr List::first(){ 
    return ListItr(this->head->next);
}

ListItr List::last(){ 
    return ListItr(this->tail->previous);
}

void List::insertAfter(int x, ListItr position) {

    // Create new ListNode for the insert and set value to 'x'.
    ListNode* newNode = new ListNode();
    newNode->value = x;
    // Handle the pointer swaps 
    ListNode* temp = position.current;
    newNode->previous = temp;       // fix the two pointer of newNode
    newNode->next = temp->next;

    temp->next->previous = newNode; // this is pointing position->next to newNode
    temp->next = newNode;          // poition->next = newNode
    this->count++;                 // increase the count of list
}

void List::insertBefore(int x, ListItr position) {
    // Create new ListNode for the insert and set value to 'x'.
    ListNode* newNode = new ListNode();
    newNode->value = x;
    // Handle the pointer swaps 
    ListNode* temp = position.current;
    newNode->next = temp;       // fix the two pointer of newNode
    newNode->previous = temp->previous;

    temp->previous->next = newNode; // point position->previous's next to newNode
    temp->previous = newNode;          // poition->previous = newNode
    this->count++;                 // increase the count of list
}

void List::insertAtTail(int x) {
    // Create new ListNode for the insert and set value to 'x'.
    ListNode* newNode = new ListNode();
    newNode->value = x;
    // This is the previous last node before Tail;
    ListNode* lastNode = this->tail->previous;
    
    // Fix the pointer of all the ListNodes now
    lastNode->next = newNode;
    newNode->previous = lastNode;
    this->tail->previous = newNode;
    newNode->next = this->tail;

    // adjust List::Count for the new ListNode
    this->count++;
}

ListItr List::find(int x) { 
    ListItr last = this->first();
    // Loop through the list looking for 'x'. If we find it, return current location
    // of last. This loop terminates when last == this->tail.
    while( !( last.isPastEnd()) ) { 
        if(last.current->value == x) {
            return last;
        }
        else {
            last.moveForward();
        }
    }
    return last; // If we get here, then last is pointing at this->tail.
}

void List::remove(int x) {
    ListItr found = this->find(x);
    if(found.current == this->tail) {}
    else {
        // Set previous->next to current->next
        found.current->previous->next = found.current->next;
        // Set next->previous to current->previous
        found.current->next->previous = found.current->previous;
        delete found.current;
        this->count--;
    }
}

int List::size() const { return this->count; }

void printList(List& source, bool forward){
    if(forward == true) {
        ListItr last = source.first();
        while (!( last.isPastEnd() ) ) { // if last.current->next != NULL (ie dummy tail) 
            cout << last.retrieve() << " " ;
            last.moveForward();
        }
        cout << endl;
    }
    if(forward == false) {
        ListItr last = source.last();
        while (!( last.isPastBeginning() ) ) { // if last.current->previous != NULL (ie dummy head) 
            cout << last.retrieve() << " " ;
            last.moveBackward();
        }
        cout << endl;
    }
}
