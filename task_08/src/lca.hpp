#ifndef LCA_HPP
#define LCA_HPP

#include <vector>
#include <cmath>

class LCA {
private:
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<std::vector<int>> up;
    std::vector<int> depth;
    std::vector<int> tin, tout;
    int timer;
    int logN;
    
    void dfs(int u, int parent);
    bool isAncestor(int u, int v);
    
public:
    LCA(int vertices);
    void addEdge(int u, int v);
    void preprocess(int root);
    int findLCA(int u, int v);
    int getDepth(int u);
};

#endif // LCA_HPP