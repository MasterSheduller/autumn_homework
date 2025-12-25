#include "mst_degree_limit.hpp"
#include <algorithm>
#include <vector>
#include <climits>

MSTDegreeLimit::DSU::DSU(int n) : parent(n), rank(n, 0) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int MSTDegreeLimit::DSU::find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool MSTDegreeLimit::DSU::unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX == rootY) return false;
    
    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
    return true;
}

MSTDegreeLimit::MSTDegreeLimit(int vertices) : n(vertices) {}

void MSTDegreeLimit::addEdge(int u, int v, int weight) {
    edges.emplace_back(u, v, weight);
}

int MSTDegreeLimit::findMSTWithDegreeLimit(int maxDegree) {
    // Сортируем ребра по весу
    std::sort(edges.begin(), edges.end());
    
    DSU dsu(n);
    std::vector<int> degree(n, 0);
    int totalWeight = 0;
    int edgesUsed = 0;
    
    // Первый проход: строим MST без учета степени
    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            degree[edge.u]++;
            degree[edge.v]++;
            totalWeight += edge.weight;
            edgesUsed++;
        }
    }
    
    // Если не получилось построить остовное дерево
    if (edgesUsed != n - 1) {
        return -1;
    }
    
    // Проверяем ограничение на степень
    for (int d : degree) {
        if (d > maxDegree) {
            return -1;
        }
    }
    
    return totalWeight;
}