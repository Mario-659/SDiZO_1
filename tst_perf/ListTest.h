#ifndef ALGORITHMS_LISTTEST_H
#define ALGORITHMS_LISTTEST_H

#include <fstream>
#include <string>
#include <vector>
#include <chrono>

#include "Random.h"
#include "DoublyLinkedList.h"

class ListTest {
public:
    void testPushFront();
    void testPushBack();
    void testPushRandom();
    void testFindRandom();
};


#endif //ALGORITHMS_LISTTEST_H
