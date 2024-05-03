// If you change anything in this file, your changes will be ignored
// in your homework submission.
// Chekout TEST_F functions bellow to learn what is being tested.
#include <cmath>
#include <ctime>
#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <math.h>
#include <string>

// in order to access private members, we have to defeat the safety
// mechanisms. This is acceptable for unit testing, but not much
// else. It is also not portable because it is not supported by the
// C++ spec, and therefore might not work with all compilers.
#define private public
#include "../Node.h"
#include "../SkipList.h"


class SkipListTest : public ::testing::Test {
protected:
    SkipList list;

    void SetUp() override {
        list.insert(std::make_pair("AAPL", 150));
        list.insert(std::make_pair("GOOGL", 2800));
        list.insert(std::make_pair("TSLA", 700));
    }
};

TEST_F(SkipListTest, SkipListInitialization) {
    ASSERT_EQ(list.getHighestPrice(), 2800);
}


TEST_F(SkipListTest, Insertion) {
    list.insert(std::make_pair("MSFT", 300));
    ASSERT_EQ(list.getHighestPrice(), 2800);
    ASSERT_TRUE(list.search("MSFT"));
}


TEST_F(SkipListTest, Deletion) {
    ASSERT_TRUE(list.deleteNode("AAPL"));
    ASSERT_FALSE(list.search("AAPL"));
    ASSERT_EQ(list.getHighestPrice(), 2800);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}