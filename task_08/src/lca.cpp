#include "lca.hpp"
#include <algorithm>

LCA::LCA(int vertices) : n(vertices), adj(vertices), 
                         depth(vertices), tin(vertices),
                         tout(vertices), timer(0) {
    logN = std::ceil(std::log2(n)) + 1;
    up.resize(n, std::vector<int>(logN + 1));
}

void LCA::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void LCA::dfs(int u, int parent) {
    tin[u] = ++timer;
    up[u][0] = parent;
    
    for (int i = 1; i <= logN; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    
    for (int v : adj[u]) {
        if (v != parent) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
    
    tout[u] = ++timer;
}

void LCA::preprocess(int root) {
    depth[root] = 0;
    dfs(root, root);
}

bool LCA::isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int LCA::findLCA(int u, int v) {
    if (isAncestor(u, v)) return u;
    if (isAncestor(v, u)) return v;
    
    for (int i = logN; i >= 0; i--) {
        if (!isAncestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    
    return up[u][0];
}

int LCA::getDepth(int u) {
    return depth[u];
}