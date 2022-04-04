#include "gtest/gtest.h"

#include "Array.h"

TEST(ArrayTest, WhenEmpty){
    auto array = new Array();
    EXPECT_EQ(0, array->size()) << "Size not 0";
    EXPECT_FALSE(array->contains(6));
}

TEST(ArrayTest, pushFront){
    auto array = new Array();
    array->pushFront(890);

    EXPECT_TRUE(array->contains(890));
    EXPECT_EQ(1, array->size());

    array->pushFront(111);
    EXPECT_TRUE(array->contains(111));
    EXPECT_TRUE(array->contains(890));
    EXPECT_EQ(2, array->size());
}

TEST(ArrayTest, pushBack){
    auto array = new Array();
    array->pushBack(890);

    EXPECT_TRUE(array->contains(890));
    EXPECT_EQ(1, array->size());

    array->pushBack(111);
    EXPECT_TRUE(array->contains(111));
    EXPECT_TRUE(array->contains(890));
    EXPECT_EQ(2, array->size());
}

TEST(ArrayTest, insert){
    auto array = new Array();

    EXPECT_FALSE(array->insert(-1, 111));
    EXPECT_FALSE(array->insert(1, 111));
    EXPECT_FALSE(array->insert(20, 111));
    EXPECT_EQ(0, array->size());

    EXPECT_TRUE(array->insert(0, 111));
    EXPECT_EQ(1, array->size());
    EXPECT_TRUE(array->contains(111));

    EXPECT_TRUE(array->insert(0, 222));
    EXPECT_EQ(2, array->size());
    EXPECT_TRUE(array->contains(111));
    EXPECT_TRUE(array->contains(222));

    EXPECT_TRUE(array->insert(2, 333));
    EXPECT_EQ(3, array->size());
    EXPECT_TRUE(array->contains(111));
    EXPECT_TRUE(array->contains(222));
    EXPECT_TRUE(array->contains(333));
}


TEST(ArrayTest, remove){
    auto array = new Array();

    array->pushFront(111);
    array->pushFront(222);
    array->pushFront(333);
    array->pushFront(111);
    EXPECT_EQ(4, array->size());

    EXPECT_FALSE(array->remove(4));
    EXPECT_EQ(4, array->size());

    EXPECT_FALSE(array->remove(-1));
    EXPECT_EQ(4, array->size());


    EXPECT_TRUE(array->remove(0));
    EXPECT_EQ(3, array->size());

    EXPECT_TRUE(array->remove(2));
    EXPECT_EQ(2, array->size());

    EXPECT_TRUE(array->remove(0));
    EXPECT_EQ(1, array->size());

    EXPECT_TRUE(array->remove(0));
    EXPECT_EQ(0, array->size());
}