#include <gtest/gtest.h>
#include "lca.hpp"

TEST(LCATest, SimpleTree) {
    LCA lca(9);
    lca.addEdge(0, 1);
    lca.addEdge(0, 2);
    lca.addEdge(1, 3);
    lca.addEdge(1, 4);
    lca.addEdge(2, 5);
    lca.addEdge(2, 6);
    lca.addEdge(3, 7);
    lca.addEdge(3, 8);
    
    lca.preprocess(0);
    
    EXPECT_EQ(lca.findLCA(7, 8), 3);
    EXPECT_EQ(lca.findLCA(7, 5), 0);
    EXPECT_EQ(lca.findLCA(4, 6), 0);
    EXPECT_EQ(lca.findLCA(1, 4), 1);
}

TEST(LCATest, LinearTree) {
    LCA lca(5);
    lca.addEdge(0, 1);
    lca.addEdge(1, 2);
    lca.addEdge(2, 3);
    lca.addEdge(3, 4);
    
    lca.preprocess(0);
    
    EXPECT_EQ(lca.findLCA(0, 4), 0);
    EXPECT_EQ(lca.findLCA(2, 4), 2);
    EXPECT_EQ(lca.findLCA(1, 3), 1);
    EXPECT_EQ(lca.findLCA(4, 4), 4);
}

TEST(LCATest, StarTree) {
    LCA lca(5);
    lca.addEdge(0, 1);
    lca.addEdge(0, 2);
    lca.addEdge(0, 3);
    lca.addEdge(0, 4);
    
    lca.preprocess(0);
    
    EXPECT_EQ(lca.findLCA(1, 2), 0);
    EXPECT_EQ(lca.findLCA(3, 4), 0);
    EXPECT_EQ(lca.findLCA(1, 4), 0);
    EXPECT_EQ(lca.findLCA(2, 3), 0);
}

TEST(LCATest, DepthTest) {
    LCA lca(7);
    lca.addEdge(0, 1);
    lca.addEdge(0, 2);
    lca.addEdge(1, 3);
    lca.addEdge(1, 4);
    lca.addEdge(2, 5);
    lca.addEdge(5, 6);
    
    lca.preprocess(0);
    
    EXPECT_EQ(lca.getDepth(0), 0);
    EXPECT_EQ(lca.getDepth(1), 1);
    EXPECT_EQ(lca.getDepth(3), 2);
    EXPECT_EQ(lca.getDepth(6), 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}