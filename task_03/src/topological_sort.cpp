#include "topological_sort.hpp"

TopologicalSort::TopologicalSort(int vertices) : n(vertices), adj(vertices), inDegree(vertices, 0) {}

void TopologicalSort::addEdge(int u, int v) {
    adj[u].push_back(v);
    inDegree[v]++;
}

std::vector<int> TopologicalSort::sort() {
    std::vector<int> result;
    std::queue<int> q;
    
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        
        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    if (result.size() != n) {
        return {}; // Есть цикл
    }
    
    return result;
}

bool TopologicalSort::hasCycle() {
    return sort().size() != n;
}