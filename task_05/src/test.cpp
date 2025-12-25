#include <gtest/gtest.h>
#include "mst_degree_limit.hpp"

TEST(MSTDegreeLimitTest, SimpleGraph) {
    MSTDegreeLimit mst(4);
    mst.addEdge(0, 1, 1);
    mst.addEdge(1, 2, 2);
    mst.addEdge(2, 3, 3);
    mst.addEdge(3, 0, 4);
    mst.addEdge(0, 2, 5);
    
    int weight = mst.findMSTWithDegreeLimit(2);
    EXPECT_EQ(weight, 6); // 1 + 2 + 3
}

TEST(MSTDegreeLimitTest, DegreeLimitViolated) {
    MSTDegreeLimit mst(3);
    mst.addEdge(0, 1, 1);
    mst.addEdge(0, 2, 1);
    mst.addEdge(1, 2, 1);
    
    int weight = mst.findMSTWithDegreeLimit(1);
    EXPECT_EQ(weight, -1); // Невозможно при ограничении степени 1
}

TEST(MSTDegreeLimitTest, SingleVertex) {
    MSTDegreeLimit mst(1);
    int weight = mst.findMSTWithDegreeLimit(0);
    EXPECT_EQ(weight, 0);
}

TEST(MSTDegreeLimitTest, CompleteGraph) {
    MSTDegreeLimit mst(4);
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            mst.addEdge(i, j, i + j + 1);
        }
    }
    
    int weight = mst.findMSTWithDegreeLimit(3);
    EXPECT_GT(weight, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}