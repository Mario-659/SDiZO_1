#ifndef ALGORITHMS_HEAP_H
#define ALGORITHMS_HEAP_H

#include <iostream>
#include <string>

// reading file
#include <fstream>

//random numbers
#include <algorithm>
#include <random>
#include <bits/stdc++.h>

/*
 * Maximum type
 */
class Heap {
private:
    int* arr;
    int maxSize;
    int currSize;
    int getParent(int index);
    int getLeft(int index);
    int getRight(int index);

    // Used for printing heap
    void printBT(const std::string& prefix, int index, bool isLeft);

    // Restores structure of heap for given index
    void heapify(int index);

    // Restores structure of heap for current array, uses floyd algorithm
    void makeHeap();
public:
    // Makes new empty heap with maximum size of maxSize
    Heap(int maxSize);

    // Makes heap from existing array, uses floyd algorithm
    Heap(int* start, int size, int maxSize);

    // Removes element, returns true if removed successfully
    bool remove(int index);

    // Adds element, returns true if added successfully
    bool push(int value);

    // Returns true if contains given value
    bool contains(int value);

    // Removes and returns max (root) element from heap
    int extractMax();

    // Returns string representation of array used to store heap
    std::string toString();

    // Prints heap (https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c)
    void print();

    // Clears heap, and inserts new random elements
    void makeRandom(int n);

    // Reads from filename.txt, first number as size
    void readFromFile(std::string filename);

    // Returns array used to store data (for testing only)
    int* getArray();

    // Returns current size
    int getSize();

    ~Heap();
};

#endif //ALGORITHMS_HEAP_H
