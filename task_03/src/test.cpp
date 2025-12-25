#include <gtest/gtest.h>
#include "topological_sort.hpp"

TEST(TopologicalSortTest, SimpleSort) {
    TopologicalSort ts(6);
    ts.addEdge(5, 2);
    ts.addEdge(5, 0);
    ts.addEdge(4, 0);
    ts.addEdge(4, 1);
    ts.addEdge(2, 3);
    ts.addEdge(3, 1);
    
    auto order = ts.sort();
    EXPECT_EQ(order.size(), 6);
    
    // Проверяем корректность порядка
    std::vector<int> pos(6);
    for (int i = 0; i < 6; i++) {
        pos[order[i]] = i;
    }
    
    EXPECT_LT(pos[5], pos[2]);
    EXPECT_LT(pos[5], pos[0]);
    EXPECT_LT(pos[4], pos[0]);
    EXPECT_LT(pos[4], pos[1]);
    EXPECT_LT(pos[2], pos[3]);
    EXPECT_LT(pos[3], pos[1]);
}

TEST(TopologicalSortTest, CycleDetection) {
    TopologicalSort ts(3);
    ts.addEdge(0, 1);
    ts.addEdge(1, 2);
    ts.addEdge(2, 0);
    
    auto order = ts.sort();
    EXPECT_TRUE(order.empty());
    EXPECT_TRUE(ts.hasCycle());
}

TEST(TopologicalSortTest, SingleVertex) {
    TopologicalSort ts(1);
    auto order = ts.sort();
    EXPECT_EQ(order.size(), 1);
    EXPECT_EQ(order[0], 0);
}

TEST(TopologicalSortTest, MultipleSources) {
    TopologicalSort ts(5);
    ts.addEdge(0, 2);
    ts.addEdge(1, 2);
    ts.addEdge(2, 3);
    ts.addEdge(2, 4);
    
    auto order = ts.sort();
    EXPECT_EQ(order.size(), 5);
    
    std::vector<int> pos(5);
    for (int i = 0; i < 5; i++) {
        pos[order[i]] = i;
    }
    
    EXPECT_LT(pos[0], pos[2]);
    EXPECT_LT(pos[1], pos[2]);
    EXPECT_LT(pos[2], pos[3]);
    EXPECT_LT(pos[2], pos[4]);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}