#include "scc_analysis.hpp"
#include <algorithm>
#include <stack>

SCCAnalysis::SCCAnalysis(int vertices) : n(vertices), adj(vertices), adjRev(vertices) {}

void SCCAnalysis::addRoad(int u, int v) {
    adj[u].push_back(v);
    adjRev[v].push_back(u);
}

void SCCAnalysis::dfs1(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs1(u);
        }
    }
    order.push_back(v);
}

void SCCAnalysis::dfs2(int v) {
    visited[v] = true;
    component.push_back(v);
    for (int u : adjRev[v]) {
        if (!visited[u]) {
            dfs2(u);
        }
    }
}

int SCCAnalysis::minRoadsToConnect() {
    // Первый проход - получаем порядок выхода
    visited.assign(n, false);
    order.clear();
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }
    
    // Второй проход - находим компоненты сильной связности
    visited.assign(n, false);
    std::reverse(order.begin(), order.end());
    
    std::vector<int> compId(n, -1);
    int compCount = 0;
    
    for (int v : order) {
        if (!visited[v]) {
            component.clear();
            dfs2(v);
            
            for (int u : component) {
                compId[u] = compCount;
            }
            compCount++;
        }
    }
    
    if (compCount == 1) {
        return 0;
    }
    
    // Считаем полустепени
    std::vector<int> inDegree(compCount, 0);
    std::vector<int> outDegree(compCount, 0);
    
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            if (compId[u] != compId[v]) {
                outDegree[compId[u]]++;
                inDegree[compId[v]]++;
            }
        }
    }
    
    int sources = 0;
    int sinks = 0;
    
    for (int i = 0; i < compCount; i++) {
        if (inDegree[i] == 0) sources++;
        if (outDegree[i] == 0) sinks++;
    }
    
    return std::max(sources, sinks);
}