#include <gtest/gtest.h>
#include "scc_analysis.hpp"

TEST(SCCAnalysisTest, Example1) {
    SCCAnalysis scc(2);
    scc.addRoad(0, 1);
    EXPECT_EQ(scc.minRoadsToConnect(), 1);
}

TEST(SCCAnalysisTest, Example2) {
    SCCAnalysis scc(4);
    scc.addRoad(0, 1);
    scc.addRoad(2, 1);
    scc.addRoad(1, 3);
    EXPECT_EQ(scc.minRoadsToConnect(), 2);
}

TEST(SCCAnalysisTest, Example3) {
    SCCAnalysis scc(5);
    scc.addRoad(0, 1);
    scc.addRoad(2, 1);
    scc.addRoad(1, 3);
    scc.addRoad(1, 4);
    EXPECT_EQ(scc.minRoadsToConnect(), 2);
}

TEST(SCCAnalysisTest, AlreadyConnected) {
    SCCAnalysis scc(4);
    scc.addRoad(0, 1);
    scc.addRoad(1, 2);
    scc.addRoad(2, 3);
    scc.addRoad(3, 0);
    EXPECT_EQ(scc.minRoadsToConnect(), 0);
}

TEST(SCCAnalysisTest, MultipleComponents) {
    SCCAnalysis scc(6);
    scc.addRoad(0, 1);
    scc.addRoad(1, 0);
    scc.addRoad(2, 3);
    scc.addRoad(3, 2);
    scc.addRoad(4, 5);
    scc.addRoad(5, 4);
    EXPECT_EQ(scc.minRoadsToConnect(), 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}