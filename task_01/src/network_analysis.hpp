#ifndef NETWORK_ANALYSIS_HPP
#define NETWORK_ANALYSIS_HPP

#include <vector>
#include <utility>

class NetworkAnalysis {
private:
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> disc;
    std::vector<int> low;
    std::vector<bool> visited;
    std::vector<std::pair<int, int>> bridges;
    std::vector<bool> articulationPoints;
    int time;
    
    void dfsBridges(int u, int parent);
    void dfsArticulationPoints(int u, int parent);
    
public:
    NetworkAnalysis(int vertices);
    void addConnection(int u, int v);
    std::vector<std::pair<int, int>> findBridges();
    std::vector<int> findArticulationPoints();
};

#endif // NETWORK_ANALYSIS_HPP