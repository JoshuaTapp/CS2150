


#include "List.h"

List::List() {}

List::List(const List& source) {}

List::~List() {}

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

bool List::isEmpty() const {return true;}

void List::makeEmpty() {}

ListItr List::first(){ return NULL;}

ListItr List::last(){ return NULL;}

void List::insertAfter(int x, ListItr position) {}

void List::insertBefore(int x, ListItr position) {}

void List::insertAtTail(int x) {}

ListItr List::find(int x) { return NULL;}

void List::remove(int x) {}

int List::size() const { return 1; }

void printList(List& source, bool forward){}
