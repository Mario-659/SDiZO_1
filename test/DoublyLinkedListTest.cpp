#include "gtest/gtest.h"

#include "DoublyLinkedList.h"

TEST(DoublyLinkedListTest, WhenEmpty){
    auto list = new DoublyLinkedList();
    EXPECT_TRUE(list->isEmpty()) << "Not empty after creation";
    EXPECT_EQ(0, list->size()) << "Size not 0";
    EXPECT_FALSE(list->contains(6));
}

TEST(DoublyLinkedListTest, pushFront){
    auto list = new DoublyLinkedList();
    list->pushFront(890);

    EXPECT_FALSE(list->isEmpty());
    EXPECT_TRUE(list->contains(890));
    EXPECT_EQ(1, list->size());

    list->pushFront(111);
    EXPECT_FALSE(list->isEmpty());
    EXPECT_TRUE(list->contains(111));
    EXPECT_EQ(2, list->size());
}

TEST(DoublyLinkedListTest, pushBack){
    auto list = new DoublyLinkedList();
    list->pushBack(890);

    EXPECT_FALSE(list->isEmpty());
    EXPECT_TRUE(list->contains(890));
    EXPECT_EQ(1, list->size());

    list->pushBack(111);
    EXPECT_FALSE(list->isEmpty());
    EXPECT_TRUE(list->contains(111));
    EXPECT_EQ(2, list->size());
}

TEST(DoublyLinkedListTest, popHead){
    auto list = new DoublyLinkedList();
    list->pushBack(111);
    list->pushFront(222);

    EXPECT_EQ(2, list->size()) << list->toString();
    list->pop_head();
    EXPECT_EQ(1, list->size());
    list->pop_head();
    EXPECT_EQ(0, list->size());
}

TEST(DoublyLinkedListTest, popTail){
    auto list = new DoublyLinkedList();
    list->pushBack(111);
    list->pushFront(222);

    EXPECT_EQ(2, list->size());
    list->pop_tail();
    EXPECT_EQ(1, list->size());
    list->pop_tail();
    EXPECT_EQ(0, list->size());
}

TEST(DoublyLinkedListTest, removeValue){
    auto list = new DoublyLinkedList();
    list->pushBack(111);
    list->pushFront(222);
    list->pushFront(123);

    EXPECT_TRUE(list->removeValue(222));
    EXPECT_EQ(2, list->size());
    EXPECT_TRUE(list->contains(111));
    EXPECT_TRUE(list->contains(123));
    EXPECT_FALSE(list->contains(222));

    EXPECT_TRUE(list->removeValue(123));
    EXPECT_EQ(1, list->size());
    EXPECT_TRUE(list->contains(111));
    EXPECT_FALSE(list->contains(123));

    EXPECT_TRUE(list->removeValue(111));
    EXPECT_EQ(0, list->size());
    EXPECT_FALSE(list->contains(111));
}

TEST(DoublyLinkedListTest, insert){
    auto list = new DoublyLinkedList();

    EXPECT_FALSE(list->insert(111, 1)) << "Index out of range, should return false";
    EXPECT_FALSE(list->insert(111, -1)) << "Index out of range, should return false";
    EXPECT_FALSE(list->insert(111, 111)) << "Index out of range, should return false";
    EXPECT_TRUE(list->isEmpty());

    // insert when empty
    EXPECT_TRUE(list->insert(111, 0));
    EXPECT_EQ(1, list->size());
    EXPECT_TRUE(list->contains(111));

    // insert before
    EXPECT_TRUE(list->insert(222, 0));
    EXPECT_EQ(2, list->size());
    EXPECT_TRUE(list->contains(222));
    EXPECT_TRUE(list->contains(111));

    // insert after (at the end)
    EXPECT_TRUE(list->insert(333, 2));
    EXPECT_EQ(3, list->size());
    EXPECT_TRUE(list->contains(222));
    EXPECT_TRUE(list->contains(111));
    EXPECT_TRUE(list->contains(333));
}

TEST(DoublyLinkedListTest, clearList){
    auto list = new DoublyLinkedList;
    list->makeRandom(88);
    EXPECT_EQ(88, list->size());
    list->clear();
    EXPECT_EQ(0, list->size());
}