


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
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List() {
    this->makeEmpty();
    delete this->head;
    delete this->tail;
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
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const {
    if(count == 2) {return true;}
    else {return false;}
}

void List::makeEmpty() {
    if(this->isEmpty()) {}
    else {
        ListItr iter = this->first();
        for(int i = 0; i < this->size(); i++) {
            iter.moveForward();
            delete iter.current->previous;
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
    ListItr iter = this->first();
    // Loop through the list looking for 'x'. If we find it, return current location
    // of iter. This loop terminates when iter == this->tail.
    while( !( iter.isPastEnd()) ) { 
        if(iter.current->value == x) {
            return iter;
        }
        else {
            iter.moveForward();
        }
    }
    return iter; // If we get here, then iter is pointing at this->tail.
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
        ListItr iter = source.first();
        while (!( iter.isPastEnd() ) ) { // if iter.current->next != NULL (ie dummy tail) 
            cout << iter.retrieve() << " " ;
            iter.moveForward();
        }
        cout << endl;
    }
    if(forward == false) {
        ListItr iter = source.last();
        while (!( iter.isPastBeginning() ) ) { // if iter.current->previous != NULL (ie dummy head) 
            cout << iter.retrieve() << " " ;
            iter.moveBackward();
        }
        cout << endl;
    }
}
