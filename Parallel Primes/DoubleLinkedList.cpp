//
//  DoubleLinkedList.cpp
//  Airline Ticket Reservations
//
//  Created by Will Gibson on 10/6/22.
//

#include "DoubleLinkedList.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// Adds a node to the tail of the list. Not as useful as the addInOrder
template<class T>
void DoublyLinkedList<T>::addToDLLTail(const T& el){
    if (tail != nullptr){
        tail = new DLLNode<T>(el, nullptr, tail);
        tail -> prev -> next = tail;
    }else
        head = tail = new DLLNode<T>(el);
    numElements++;
    return;
}


// Removes a node from the tail
template<class T>
T DoublyLinkedList<T>::deleteFromDLLTail(){
    T el = tail -> info;
    if (head == tail){
        delete head;
        head = tail = nullptr;
    }else {
        tail = tail -> prev;
        delete tail -> next;
        tail -> next = nullptr;
    }
    numElements--;
    return el;
}


// Adds a new node in a specific spot in the list, based on what the other elements are
template<class T>
void DoublyLinkedList<T>::addInOrder(const T& el){
    if(head == nullptr){
        head = tail = new DLLNode<T>(el);
        numElements++;
        return;
    }
    if (head -> info > el){
        DLLNode<T>* insert = new DLLNode<T>(el);
        insert -> next = head;
        head -> prev = insert;
        head = insert;
        numElements++;
        return;
    }
    DLLNode<T>* current = head;
    while (current -> info < el && current -> next != nullptr) {
        current = current->next;
    }
    if (current -> info < el){
        tail = new DLLNode<T>(el);
        tail -> prev = current;
        current->next = tail;
    }else{
        DLLNode<T>* insert = new DLLNode<T>(el);
        insert -> next = current;
        insert -> prev = current -> prev;
        current -> prev -> next = insert;
        current -> prev = insert;
    }
    numElements++;
    return;
}


// Prints the entire list, currrently printing names
template<class T>
void DoublyLinkedList<T>::printDLList(){
    DLLNode<T> *current;
    current = head;
    while (current != nullptr){
        cout << current -> info << endl;
        current = current -> next;
    }
}


// Prints the entire list in reverse order
template<class T>
void DoublyLinkedList<T>::printBack(){
    DLLNode<T> *current;
    current = tail;
    while (current != head->prev){
        cout << current -> info << endl;
        current = current -> prev;
    }
}


// Finds a specific node, useful in certain circumstances, not as useful as the isInList function for validation. Returns a specific node itself
template<class T>
DLLNode<T> DoublyLinkedList<T>::findNode(const T& el){
    DLLNode<T> *tmp;
    for (tmp = head; tmp != nullptr && !(tmp->info == el);)
        tmp = tmp->next;
    return *tmp;
}


// Deletes a specific node from the list. In hindsight, maybe I could have used the findNode function here, but I didn't, so oh well.
template<class T>
void DoublyLinkedList<T>::deleteSpecific(const T& el){
    if(head != nullptr){
        if (head == tail && el == head -> info){
            delete head;
            head = tail = nullptr;
        }else if (el == head->info){
            DLLNode<T> *tmp = head;
            head = head->next;
            delete tmp;
        }else{
            DLLNode<T> *pred, *tmp;
            for (pred = head, tmp = head->next; tmp != nullptr && !(tmp->info == el); pred = pred->next, tmp = tmp->next);
            if(tmp != nullptr){
                pred->next = tmp -> next;
                if (tmp == tail)
                    tail = pred;
                delete tmp;
            }
        }
        numElements--;
        return;
    }
}


// Checks to see if a specific node exists in the list at all.
template<class T>
bool DoublyLinkedList<T>::isInList(const T& el){
    DLLNode<T> *tmp;
    for (tmp = head; tmp != nullptr && !(tmp->info == el); tmp = tmp->next);
    if (tmp == nullptr)
        return false;
    return true;
}


// Print entire list to outfile
template<class T>
void DoublyLinkedList<T>::outputToFile(string outFile, int upperLimit){
    ofstream outputFile;
    outputFile.open(outFile);
    
    DLLNode<T> *current;
    current = head;
    
    cout << "Writing to file: " << outFile << endl;
    cout << "Test write: " << current -> info << endl;
    
    if (outputFile.is_open()) {
        cout << "Successfully opened the file." << endl;
    } else {
        cerr << "Failed to open the file." << endl;
    }

    
    outputFile << "Primes between 1 and " << upperLimit << endl;
    outputFile << "Number of primes: " << numElements << endl;
    outputFile << "-------------------------" << endl;
    while (current != nullptr){
        outputFile << current -> info << endl;
        current = current -> next;
    }
    outputFile << "Primes between 1 and " << upperLimit << endl;
    outputFile << "Number of primes: " << numElements << endl;
    outputFile << "-------------------------" << endl;
    outputFile.close();
    cout << "Written to file successfully" << endl;
    return;
}
