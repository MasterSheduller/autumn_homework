#include <gtest/gtest.h>
#include "rmq.hpp"

TEST(RMQTest, SimpleQuery) {
    std::vector<int> arr = {2, 5, 1, 8, 3, 9, 4};
    RMQ rmq(arr);
    
    EXPECT_EQ(rmq.queryMin(0, 2), 2); // Минимальный в [0,2] на позиции 2
    EXPECT_EQ(rmq.queryMin(1, 4), 2); // Минимальный в [1,4] на позиции 2
    EXPECT_EQ(rmq.queryMin(3, 6), 6); // Минимальный в [3,6] на позиции 6
}

TEST(RMQTest, AllEqual) {
    std::vector<int> arr = {5, 5, 5, 5, 5};
    RMQ rmq(arr);
    
    // При равных значениях возвращается первый минимум
    EXPECT_EQ(rmq.queryMin(0, 4), 0);
    EXPECT_EQ(rmq.queryMin(2, 3), 2);
}

TEST(RMQTest, SingleElement) {
    std::vector<int> arr = {42};
    RMQ rmq(arr);
    
    EXPECT_EQ(rmq.queryMin(0, 0), 0);
}

TEST(RMQTest, DecreasingSequence) {
    std::vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    RMQ rmq(arr);
    
    EXPECT_EQ(rmq.queryMin(0, 9), 9);
    EXPECT_EQ(rmq.queryMin(2, 5), 5);
    EXPECT_EQ(rmq.queryMin(0, 4), 4);
}

TEST(RMQTest, IncreasingSequence) {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    RMQ rmq(arr);
    
    EXPECT_EQ(rmq.queryMin(0, 9), 0);
    EXPECT_EQ(rmq.queryMin(3, 7), 3);
    EXPECT_EQ(rmq.queryMin(5, 9), 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}