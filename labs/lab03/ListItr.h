/**
Author: Joshua Tapp
CompID: jct7bm
Date: 2/20/2021 14:19
File Name: ListItr.h

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 2
**/
#ifndef LISTITR_H
#define LISTITR_H

#include "ListNode.h"
#include "List.h"

class ListItr {
public:
    // Constructors
    ListItr();
    ListItr(ListNode* theNode);

    // Returns true if the iterator is currently pointing past the end position
    // in the list (i.e., it's pointing to the dummy tail), else false
    bool isPastEnd() const;

    // Returns true if the iterator is currently pointing past (before) the first position
    // in list (i.e., it's pointing to the dummy head), else false
    bool isPastBeginning() const;

    // Advances `current` to the next position in the list (unless already past the end of the list)
    void moveForward();

    // Moves `current` back to the previous position in the list (unless already past the beginning of the list)
    void moveBackward();

    // Returns the value of the item in the current position of the list
    int retrieve() const;

private:
    ListNode* current; // Holds the position in the list

    friend class List; // List class needs access to "current"
};

#endif
