#ifndef SCC_ANALYSIS_HPP
#define SCC_ANALYSIS_HPP

#include <vector>

class SCCAnalysis {
private:
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<std::vector<int>> adjRev;
    std::vector<bool> visited;
    std::vector<int> order;
    std::vector<int> component;
    
    void dfs1(int v);
    void dfs2(int v);
    
public:
    SCCAnalysis(int vertices);
    void addRoad(int u, int v);
    int minRoadsToConnect();
};

#endif // SCC_ANALYSIS_HPP