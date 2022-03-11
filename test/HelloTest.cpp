#include "gtest/gtest.h"

#include "Hello.cpp"

TEST(this_is_my_test_suit, this_is_my_unit_test){
    Hello* hello = new Hello;

    EXPECT_EQ(hello->getHelloValue(), 333);
}

