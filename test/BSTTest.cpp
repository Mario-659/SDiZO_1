#include "gtest/gtest.h"

#include "BST.h"

#include <algorithm>
#include "Random.h"

TEST(BSTTest, push){
    BST* tree = new BST();
    EXPECT_TRUE(tree->push(11));
    EXPECT_TRUE(tree->push(47));
    std::vector<int> arr = tree->toInorder();
    EXPECT_EQ(2, arr.size());
    EXPECT_EQ(47, arr[0]);
    EXPECT_EQ(11, arr[1]);

    for(int i=0; i<100; i++) {
        std::vector<int> randVal = Random::getRandomVector(Random::getRandom(0, 100), -100, 100);
        tree->replaceAll(randVal);
        std::vector<int> inOrder = tree->toInorder();
        std::reverse(inOrder.begin(), inOrder.end());
        EXPECT_TRUE(std::is_sorted(inOrder.begin(), inOrder.end())) << tree->toString();
    }
}

TEST(BSTTest, remove){
    auto tree = new BST();
    EXPECT_TRUE(tree->push(784));
    EXPECT_TRUE(tree->push(100));
    EXPECT_TRUE(tree->push(900));
    EXPECT_TRUE(tree->push(2));

    EXPECT_TRUE(tree->contains(784));
    EXPECT_TRUE(tree->contains(100));
    EXPECT_TRUE(tree->contains(900));
    EXPECT_TRUE(tree->contains(2));

    tree->remove(784);
//    EXPECT_TRUE(tree->remove(784));
    EXPECT_FALSE(tree->contains(784));

    EXPECT_TRUE(tree->remove(900));
    EXPECT_FALSE(tree->contains(900));

    EXPECT_TRUE(tree->remove(2));
    EXPECT_FALSE(tree->contains(2));

    EXPECT_TRUE(tree->remove(100));
    EXPECT_FALSE(tree->contains(100));
}