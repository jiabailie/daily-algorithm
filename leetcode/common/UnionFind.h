//
// Created by Ruiguo Yang on 2026/4/21.
//

#ifndef ALGORITHM_UNIONFIND_H
#define ALGORITHM_UNIONFIND_H
#include <vector>

namespace leetcode::common {
    class UnionFind {
    private:
        int count;
        std::vector<int> parent;
    public:
        UnionFind(int n) {
            count = n;
            parent.resize(n);
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        int find(int x) {
            int t = x;
            while (t != parent[t]) {
                t = parent[t];
            }
            parent[x] = t;
            return parent[x];
        }

        void unite(int x, int y) {
            int rx = find(x);
            int ry = find(y);
            if (rx == ry) {
                return;
            }
            parent[x] = std::min(rx, ry);
            parent[y] = std::min(rx, ry);
        }

        bool isConnected(int x, int y) {
            return (find(x) == find(y));
        }
    };
};

#endif //ALGORITHM_UNIONFIND_H