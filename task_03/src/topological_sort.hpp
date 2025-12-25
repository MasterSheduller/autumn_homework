#ifndef TOPOLOGICAL_SORT_HPP
#define TOPOLOGICAL_SORT_HPP

#include <vector>
#include <queue>

class TopologicalSort {
private:
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> inDegree;
    
public:
    TopologicalSort(int vertices);
    void addEdge(int u, int v);
    std::vector<int> sort();
    bool hasCycle();
};

#endif // TOPOLOGICAL_SORT_HPP