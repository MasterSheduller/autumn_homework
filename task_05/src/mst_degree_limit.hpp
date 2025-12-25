#ifndef MST_DEGREE_LIMIT_HPP
#define MST_DEGREE_LIMIT_HPP

#include <vector>

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int w) : u(u), v(v), weight(w) {}
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class MSTDegreeLimit {
private:
    int n;
    std::vector<Edge> edges;
    
    class DSU {
    private:
        std::vector<int> parent;
        std::vector<int> rank;
        
    public:
        DSU(int n);
        int find(int x);
        bool unite(int x, int y);
    };
    
public:
    MSTDegreeLimit(int vertices);
    void addEdge(int u, int v, int weight);
    int findMSTWithDegreeLimit(int maxDegree);
};

#endif // MST_DEGREE_LIMIT_HPP