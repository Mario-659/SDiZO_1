#include "gtest/gtest.h"

#include "Heap.h"
#include <algorithm>
#include <vector>

#include "Random.h"

void insertValues(Heap* heap, int* start, int* end){
    int* p = start;
    while(p != end+1){
        EXPECT_TRUE(heap->push(*p));
        p++;
    }
}

// Tests heap using std::is_heap
void testHeap(Heap* heap){
    int size = heap->getSize();
    int* array = heap->getArray();
    EXPECT_TRUE(std::is_heap(array, array+size)) << "not a heap structure: " << heap->toString();
}


TEST(HeapTest, push){
    auto heap = new Heap(20);
    int values[] = {10, 20, 30, 8, 5, 5, 11};
    insertValues(heap, values, values+7);

    auto array = heap->getArray();
    EXPECT_EQ(array[0], 30);
    EXPECT_EQ(array[1], 10);
    EXPECT_EQ(array[2], 20);
    EXPECT_EQ(array[3], 8);
    EXPECT_EQ(array[4], 5);
    EXPECT_EQ(array[5], 5);
    EXPECT_EQ(array[6], 11);

    testHeap(heap);
}

TEST(HeapTest, extractMax){
    auto heap = new Heap(20);
    int values[] = {12, 37, 9, 203, 0, 1, 999};
    insertValues(heap, values, values+6);
    testHeap(heap);

    EXPECT_EQ(999, heap->extractMax());
    testHeap(heap);

    EXPECT_EQ(203, heap->extractMax());
    testHeap(heap);

    EXPECT_EQ(37, heap->extractMax());
    testHeap(heap);

    EXPECT_EQ(12, heap->extractMax());
    testHeap(heap);

    EXPECT_EQ(9, heap->extractMax());
    testHeap(heap);

    EXPECT_EQ(1, heap->extractMax());
    testHeap(heap);

    EXPECT_EQ(0, heap->extractMax());
}

TEST(HeapTest, remove){
    auto heap = new Heap(20);
    int values[] = {11, 37, 9, 203, 0, 1, 999};
    insertValues(heap, values, values+6);

    EXPECT_FALSE(heap->remove(-12));
    EXPECT_FALSE(heap->remove(222));
    EXPECT_FALSE(heap->remove(7));
    testHeap(heap);
    EXPECT_EQ(7, heap->getSize());

    EXPECT_TRUE(heap->remove(1));
    EXPECT_FALSE(heap->contains(37));
    EXPECT_EQ(6, heap->getSize());
    testHeap(heap);
}

TEST(HeapTest, HeapConstr){
    int values1[] = {839, 22, 0, 273, 89, 102, 281, 291};
    auto heap1 = new Heap(values1, 8, 8);
    testHeap(heap1);

    int values[] = {839, 22, 273, 89, 8931};
    auto heap = new Heap(values, 5, 21);
    testHeap(heap);
}

TEST(HeapTest, makeRandom){
    std::default_random_engine generator(std::time(0));
    std::uniform_int_distribution<int> distribution(0, 500);

    auto heap = new Heap(500);
    for(int i=0; i<100; i++){
        int n = Random::getRandom(0, 500);
        heap->makeRandom(n);
        testHeap(heap);
    }
}

TEST(HeapTest, handlesInvalidOperations){
    auto heap = new Heap(100);
    EXPECT_FALSE(heap->remove(0));
    heap->extractMax();
    heap->makeRandom(99);
    EXPECT_TRUE(heap->push(11));
    EXPECT_FALSE(heap->push(99));
}