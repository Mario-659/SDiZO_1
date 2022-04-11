#ifndef ALGORITHMS_HEAPTEST_H
#define ALGORITHMS_HEAPTEST_H

#include <fstream>
#include <string>
#include <vector>
#include <chrono>

#include "Random.h"
#include "Heap.h"

class HeapTest {
public:
    void testHeapPush();
    void testHeapFindRandom();
    void testHeapRemoveRandom();
};


#endif //ALGORITHMS_HEAPTEST_H
