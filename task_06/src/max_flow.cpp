#include "max_flow.hpp"
#include <algorithm>
#include <climits>

MaxFlow::MaxFlow(int vertices) : n(vertices), 
                                 capacity(vertices, std::vector<int>(vertices, 0)),
                                 adj(vertices) {}

void MaxFlow::addEdge(int u, int v, int c) {
    capacity[u][v] += c; // Добавляем пропускную способность (разрешаем кратные ребра)
    adj[u].push_back(v);
    adj[v].push_back(u); // Для обратных ребер
}

bool MaxFlow::bfs(int s, int t, std::vector<int>& parent) {
    std::vector<bool> visited(n, false);
    std::queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (!visited[v] && capacity[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    
    return false;
}

int MaxFlow::calculateMaxFlow(int source, int sink) {
    int maxFlow = 0;
    std::vector<int> parent(n);
    
    while (bfs(source, sink, parent)) {
        int pathFlow = INT_MAX;
        
        // Находим минимальную пропускную способность на пути
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = std::min(pathFlow, capacity[u][v]);
        }
        
        // Обновляем пропускные способности
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            capacity[u][v] -= pathFlow;
            capacity[v][u] += pathFlow; // Добавляем обратное ребро
        }
        
        maxFlow += pathFlow;
    }
    
    return maxFlow;
}