#include <gtest/gtest.h>
#include "max_flow.hpp"

TEST(MaxFlowTest, SimpleFlow) {
    MaxFlow mf(4);
    mf.addEdge(0, 1, 3);
    mf.addEdge(0, 2, 2);
    mf.addEdge(1, 2, 5);
    mf.addEdge(1, 3, 2);
    mf.addEdge(2, 3, 3);
    
    int flow = mf.calculateMaxFlow(0, 3);
    EXPECT_EQ(flow, 5);
}

TEST(MaxFlowTest, ClassicExample) {
    MaxFlow mf(6);
    mf.addEdge(0, 1, 16);
    mf.addEdge(0, 2, 13);
    mf.addEdge(1, 2, 10);
    mf.addEdge(1, 3, 12);
    mf.addEdge(2, 1, 4);
    mf.addEdge(2, 4, 14);
    mf.addEdge(3, 2, 9);
    mf.addEdge(3, 5, 20);
    mf.addEdge(4, 3, 7);
    mf.addEdge(4, 5, 4);
    
    int flow = mf.calculateMaxFlow(0, 5);
    EXPECT_EQ(flow, 23);
}

TEST(MaxFlowTest, NoPath) {
    MaxFlow mf(4);
    mf.addEdge(0, 1, 5);
    mf.addEdge(2, 3, 5);
    
    int flow = mf.calculateMaxFlow(0, 3);
    EXPECT_EQ(flow, 0);
}

TEST(MaxFlowTest, SingleEdge) {
    MaxFlow mf(2);
    mf.addEdge(0, 1, 10);
    
    int flow = mf.calculateMaxFlow(0, 1);
    EXPECT_EQ(flow, 10);
}

TEST(MaxFlowTest, MultipleEdges) {
    MaxFlow mf(3);
    mf.addEdge(0, 1, 5);
    mf.addEdge(0, 1, 5); // Кратное ребро
    mf.addEdge(1, 2, 10);
    
    int flow = mf.calculateMaxFlow(0, 2);
    EXPECT_EQ(flow, 10);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}