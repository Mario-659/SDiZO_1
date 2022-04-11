#ifndef ALGORITHMS_BST_H
#define ALGORITHMS_BST_H

#include <iostream>
#include <string>
#include <vector>

// reading file
#include <fstream>

//random numbers
#include <algorithm>
#include <random>
#include <bits/stdc++.h>

struct BSTNode{
    int key;
    BSTNode* left;
    BSTNode* right;
    BSTNode* parent;

    BSTNode(int key);
    ~BSTNode() = default;
};

class BST {
public:
    BST();

    // Remove value from the tree, return true if found and deleted
    bool remove(int value);

    // Add new element
    bool push(int value);

    // Return true if contains given value
    bool contains(int value);

    // Return values in BST sorted in ascending order
    std::vector<int> toInorder();

    // Clear all values and push every element from collection
    bool replaceAll(const std::vector<int>& collection);

    // Clear all values and push every element from start pointer
    bool replaceAll(int* start, int size);

    // Remove all elements from the tree
    void clear();

    // Return values in BST as an array representation in ascending order
    std::string toString();

    // Clear values and reads from file
    void readFromFile(std::string filename);

    // Clear values and fill with random, resulting size might not be equal n
    void makeRandom(int n, int min, int max);

    void print();

    ~BST();
private:
    // Replaces one subtree in place of other subtree
    void transplant(BSTNode* parent, BSTNode* child);

    // Removes given node from tree
    void remove(BSTNode* node);

    // Returns node with minimal value starting from node
    BSTNode* minNode(BSTNode* node);

    // Top element of the tree
    BSTNode* top;
};


#endif //ALGORITHMS_BST_H
