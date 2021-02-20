


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

void List::insertAfter(int x, ListItr position) {}

void List::insertBefore(int x, ListItr position) {}

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

ListItr List::find(int x) { return NULL;}

void List::remove(int x) {}

int List::size() const { return this->count; }

void printList(List& source, bool forward){
    ListItr iter = source.first();
    while (!( iter.isPastEnd() ) ) { // if iter.current->next != NULL (ie dummy tail) 
        cout << iter.retrieve() << " " ;
        iter.moveForward();
    }
    cout << endl;
}
