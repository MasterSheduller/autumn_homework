#ifndef RMQ_HPP
#define RMQ_HPP

#include <vector>
#include <cmath>

class RMQ {
private:
    std::vector<int> arr;
    std::vector<std::vector<int>> sparseTable;
    std::vector<int> logTable;
    int n;
    
    void buildSparseTable();
    void buildLogTable();
    
public:
    RMQ(const std::vector<int>& array);
    int queryMin(int left, int right);
};

#endif // RMQ_HPP