// intlist.cpp
// Implements class IntList
// Cory Zhao; 1/30/22

#include "intlist.h"

#include <iostream>
using std::cout;
using std::endl;

// copy constructor
IntList::IntList(const IntList& source) {
    if (source.first == nullptr) {
        this->first = nullptr;
    }
    else {
        Node* n = new Node;
        first = n;
        for (Node* i = source.first; i != nullptr; i = i->next) {
            if (i->next == nullptr) {
                n->info = i->info;
                n->next = nullptr;
            }
            else {
                n->info = i->info;
                Node *p = new Node;
                n->next = p;
                n = p;
            }
        }
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* n;

    while (first != nullptr) {
        n = first->next;
        delete first;
        first = n;
    }
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;

    for (Node* i = first; i != nullptr; i = i->next) {
        sum += i->info;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    for (Node* i = first; i != nullptr; i = i->next) {
        if (i->info == value) {
            return true;
        }
    }
    return false; 
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    int max;

    if (first == nullptr) {
        return 0;
    }
    max = first->info;

    for (Node* i = first; i != nullptr; i = i->next) {
        if (i->info > max) {
            max = i->info;
        }
    }
    return max; 

}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    double sum = 0;
    int count = 0;

    if (first == nullptr) {
        return 0;
    }

    for (Node* i = first; i != nullptr; i = i->next) {
        sum += i->info;
        count++;
    }

    return sum / count; 
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    if (first == nullptr) {
        Node* n = new Node;
        n->info = value;
        n->next = nullptr;
        first = n;
    }
    else {
        Node* n = new Node;
        n->info = value;
        n->next = first;
        first = n;
    }
    
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (source.first == nullptr) {
        this->first = nullptr;
    }
    else {
        Node* n = new Node;
        this->first = n;
        for (Node* i = source.first; i != nullptr; i = i->next) {
            if (i->next == nullptr) {
                n->info = i->info;
                n->next = nullptr;
            }
            else {
                n->info = i->info;
                Node *p = new Node;
                n->next = p;
                n = p;
            }
        }
    }
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
