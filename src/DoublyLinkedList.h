#ifndef ALGORITHMS_DOUBLYLINKEDLIST_H
#define ALGORITHMS_DOUBLYLINKEDLIST_H


#include <fstream>
#include<conio.h>
#include<string>
#include<iostream>

//For random numbers
#include <algorithm>
#include <random>
#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedList {
private:
    class Node{
    public:
        // data
        int data;
        // pointer to next node
        Node* next;
        // pointer to previous node
        Node* prev;

        Node(int object, Node* nextNode, Node* prevNode){
            data = object;
            next = nextNode;
            prev = prevNode;
        }
        ~Node() {}
    };
    // first node
    Node* head;
    // last node
    Node* tail;

public:

    DoublyLinkedList();

    ~DoublyLinkedList();

    // True if empty
    bool isEmpty();

    // Returns size (number of nodes)
    int size();

    // Adds element to the back
    void pushBack(int val);

    // Adds element to the front
    void pushFront(int val);

    // Inserts element on a given index
    bool insert(int val, int index);

    // Returns true if value is in list
    bool contains(int val);

    // Removes first element
    bool pop_head();

    // Removes last element
    bool pop_tail();

    // Clears all elements of the list
    void clear();

    // Returns true if object with index was deleted, false if index out of range
    bool remove(int index);

    // Removes first occurance of a value. Returns true if value was deleted, false if value not found
    bool removeValue(int value);

    // Reads data from given .txt file, first value interpreted as size, \n as a separator
    void readFromFile(std::string filename);

    // Clears all elements of the list and fills it with random numbers
    void makeRandom(int size);

    // String representation from head to tail
    std::string toString();

    // String representation from tail to head
    std::string toStringInv();
};


#endif //ALGORITHMS_DOUBLYLINKEDLIST_H
