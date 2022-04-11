#ifndef ALGORITHMS_BSTTEST_H
#define ALGORITHMS_BSTTEST_H


#include <fstream>
#include <string>
#include <vector>
#include <chrono>

#include "Random.h"
#include "BST.h"


class BSTTest {
public:
    void testBSTPush();
    void testBSTFindRandom();
    void testBSTRemoveRandom();
};


#endif //ALGORITHMS_BSTTEST_H
