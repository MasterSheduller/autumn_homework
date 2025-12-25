#include <gtest/gtest.h>
#include "network_analysis.hpp"

TEST(NetworkAnalysisTest, SimpleBridge) {
    NetworkAnalysis na(4);
    na.addConnection(0, 1);
    na.addConnection(1, 2);
    na.addConnection(2, 3);
    na.addConnection(3, 0);
    na.addConnection(1, 3);
    
    auto bridges = na.findBridges();
    EXPECT_EQ(bridges.size(), 0);
}

TEST(NetworkAnalysisTest, TwoBridges) {
    NetworkAnalysis na(5);
    na.addConnection(0, 1);
    na.addConnection(1, 2);
    na.addConnection(2, 3);
    na.addConnection(3, 4);
    na.addConnection(1, 3);
    
    auto bridges = na.findBridges();
    EXPECT_EQ(bridges.size(), 2);
    EXPECT_EQ(bridges[0], std::make_pair(0, 1));
    EXPECT_EQ(bridges[1], std::make_pair(3, 4));
}

TEST(NetworkAnalysisTest, ArticulationPointsSimple) {
    NetworkAnalysis na(4);
    na.addConnection(0, 1);
    na.addConnection(1, 2);
    na.addConnection(2, 3);
    
    auto points = na.findArticulationPoints();
    EXPECT_EQ(points.size(), 2);
    EXPECT_EQ(points[0], 1);
    EXPECT_EQ(points[1], 2);
}

TEST(NetworkAnalysisTest, ArticulationPointsCompleteGraph) {
    NetworkAnalysis na(4);
    na.addConnection(0, 1);
    na.addConnection(0, 2);
    na.addConnection(0, 3);
    na.addConnection(1, 2);
    na.addConnection(1, 3);
    na.addConnection(2, 3);
    
    auto points = na.findArticulationPoints();
    EXPECT_EQ(points.size(), 0);
}

TEST(NetworkAnalysisTest, ComplexGraph) {
    NetworkAnalysis na(7);
    na.addConnection(0, 1);
    na.addConnection(1, 2);
    na.addConnection(2, 0);
    na.addConnection(1, 3);
    na.addConnection(1, 4);
    na.addConnection(1, 6);
    na.addConnection(3, 5);
    na.addConnection(4, 5);
    
    auto bridges = na.findBridges();
    auto points = na.findArticulationPoints();
    
    EXPECT_EQ(bridges.size(), 1); // (1,6) - мост
    EXPECT_EQ(bridges[0], std::make_pair(1, 6));
    EXPECT_EQ(points.size(), 1); // 1 - точка сочленения
    EXPECT_EQ(points[0], 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}