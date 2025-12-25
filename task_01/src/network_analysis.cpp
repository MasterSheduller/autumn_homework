#include "network_analysis.hpp"
#include <algorithm>
#include <iostream>

NetworkAnalysis::NetworkAnalysis(int vertices) : n(vertices), adj(vertices),
                                                 disc(vertices, -1),
                                                 low(vertices, -1),
                                                 visited(vertices, false),
                                                 articulationPoints(vertices, false),
                                                 time(0) {}

void NetworkAnalysis::addConnection(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void NetworkAnalysis::dfsBridges(int u, int parent) {
    visited[u] = true;
    disc[u] = low[u] = ++time;
    
    for (int v : adj[u]) {
        if (v == parent) continue;
        
        if (!visited[v]) {
            dfsBridges(v, u);
            low[u] = std::min(low[u], low[v]);
            
            if (low[v] > disc[u]) {
                bridges.emplace_back(std::min(u, v), std::max(u, v));
            }
        } else {
            low[u] = std::min(low[u], disc[v]);
        }
    }
}

std::vector<std::pair<int, int>> NetworkAnalysis::findBridges() {
    bridges.clear();
    std::fill(visited.begin(), visited.end(), false);
    std::fill(disc.begin(), disc.end(), -1);
    std::fill(low.begin(), low.end(), -1);
    time = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfsBridges(i, -1);
        }
    }
    
    // Сортируем для удобства тестирования
    std::sort(bridges.begin(), bridges.end());
    return bridges;
}

void NetworkAnalysis::dfsArticulationPoints(int u, int parent) {
    visited[u] = true;
    disc[u] = low[u] = ++time;
    int children = 0;
    
    for (int v : adj[u]) {
        if (v == parent) continue;
        
        if (!visited[v]) {
            children++;
            dfsArticulationPoints(v, u);
            low[u] = std::min(low[u], low[v]);
            
            if (parent != -1 && low[v] >= disc[u]) {
                articulationPoints[u] = true;
            }
        } else {
            low[u] = std::min(low[u], disc[v]);
        }
    }
    
    if (parent == -1 && children > 1) {
        articulationPoints[u] = true;
    }
}

std::vector<int> NetworkAnalysis::findArticulationPoints() {
    articulationPoints.assign(n, false);
    std::fill(visited.begin(), visited.end(), false);
    std::fill(disc.begin(), disc.end(), -1);
    std::fill(low.begin(), low.end(), -1);
    time = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfsArticulationPoints(i, -1);
        }
    }
    
    std::vector<int> result;
    for (int i = 0; i < n; i++) {
        if (articulationPoints[i]) {
            result.push_back(i);
        }
    }
    return result;
}