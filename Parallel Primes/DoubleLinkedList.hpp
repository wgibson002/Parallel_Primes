//
//  DoubleLinkedList.hpp
//  Airline Ticket Reservations
//
//  Created by Will Gibson on 10/6/22.
//

#ifndef DoubleLinkedList_hpp
#define DoubleLinkedList_hpp

#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

// The Nodes! Doubly Linked and all Templated up for ease of use.
template<class T>
class DLLNode{
public:
    T info;
    DLLNode *next, *prev;
    
    DLLNode(){ //Creates an empty node
        next = prev = 0;
    }
    DLLNode(const T& el, DLLNode *n = nullptr, DLLNode *p = nullptr){ //Creates a node with a value el
        info = el;
        next = n;
        prev = p;
    }
};


// The list itslef
template<class T>
class DoublyLinkedList{
public:
    DoublyLinkedList(){ //Constructor!
        head = tail = 0;
    }
    
    void addToDLLTail(const T&);    // Adds to tail
    T deleteFromDLLTail();          // Deletes from tail
    void addInOrder(const T&);      // Adds in order
    void printDLList();             // Prints list in order
    void printBack();               // Prints list in reverse order
    DLLNode<T> findNode(const T&);  // Finds a specific node, returns nullptr if it doesn't exist
    void deleteSpecific(const T&);  // Deletes a specific node
    bool isInList(const T&);        // Checks to see if a node exists in the list with the matching info
    int numElements;
    void outputToFile(string, int);
    
    DLLNode<T> *head, *tail;        // The Head and Tail pointers. Cannot be private or protected since this list is currently linked under a seperate list.
};


#endif /* DoubleLinkedList_hpp */
