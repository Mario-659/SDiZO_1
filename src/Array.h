#ifndef ALGORITHMS_ARRAY_H
#define ALGORITHMS_ARRAY_H

#include <iostream>
#include <string>

// reading file
#include <fstream>

//random numbers
#include <algorithm>
#include <random>
#include <bits/stdc++.h>

class Array{
private:
    // Pointer to the beginning of the array
    int* array;

    // Current size of an array
    int currSize;

    void copyValues(int source[], int sourceSize, int* destination);

public:
    Array();

    ~Array();

    // Returns current size
    int size();

    // Adds element to the front
    void pushFront(int val);

    // Adds element to the back
    void pushBack(int val);

    // Adds element on given index
    bool insert(int index, int value);

    // Removes element with given index
    bool remove(int index);

    // Returns true if contains given value
    bool contains(int value);

    // Returns string representation
    std::string toString();

    // Reads from filename.txt, first number as size
    void readFromFile(std::string filename);

    void makeRandom(int size);
};

#endif //ALGORITHMS_ARRAY_H
