#ifndef MAX_FLOW_HPP
#define MAX_FLOW_HPP

#include <vector>
#include <queue>

class MaxFlow {
private:
    int n;
    std::vector<std::vector<int>> capacity;
    std::vector<std::vector<int>> adj;
    
    bool bfs(int s, int t, std::vector<int>& parent);
    
public:
    MaxFlow(int vertices);
    void addEdge(int u, int v, int c);
    int calculateMaxFlow(int source, int sink);
};

#endif // MAX_FLOW_HPP