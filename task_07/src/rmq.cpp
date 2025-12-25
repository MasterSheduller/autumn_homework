#include "rmq.hpp"
#include <algorithm>
#include <climits>

RMQ::RMQ(const std::vector<int>& array) : arr(array), n(array.size()) {
    buildLogTable();
    buildSparseTable();
}

void RMQ::buildLogTable() {
    logTable.resize(n + 1);
    logTable[0] = -1; // Не используется
    for (int i = 1; i <= n; i++) {
        logTable[i] = logTable[i / 2] + 1;
    }
}

void RMQ::buildSparseTable() {
    int k = logTable[n] + 1;
    sparseTable.resize(n, std::vector<int>(k));
    
    // Инициализируем первый слой
    for (int i = 0; i < n; i++) {
        sparseTable[i][0] = i;
    }
    
    // Строим остальные слои
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            int left = sparseTable[i][j - 1];
            int right = sparseTable[i + (1 << (j - 1))][j - 1];
            
            if (arr[left] <= arr[right]) {
                sparseTable[i][j] = left;
            } else {
                sparseTable[i][j] = right;
            }
        }
    }
}

int RMQ::queryMin(int left, int right) {
    if (left > right) std::swap(left, right);
    if (left < 0 || right >= n) return -1;
    
    int j = logTable[right - left + 1];
    int idx1 = sparseTable[left][j];
    int idx2 = sparseTable[right - (1 << j) + 1][j];
    
    return (arr[idx1] <= arr[idx2]) ? idx1 : idx2;
}