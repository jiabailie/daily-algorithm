//
// Created by Ruiguo Yang on 2026/6/10.
//

#ifndef ALGORITHM_SPARSETABLE_H
#define ALGORITHM_SPARSETABLE_H

#include <cstddef>
#include <vector>

namespace leetcode::common {
    class SparseTable {
    private:
        std::vector<std::vector<int>> stMin;
        std::vector<std::vector<int>> stMax;
        int getBitWidth(int x) {
            int w = 0;
            for (std::size_t i = x; i > 0; i >>= 1) {
                ++w;
            }
            return w;
        }
    public:
        SparseTable(const std::vector<int>& arr) {
            std::size_t n = arr.size();
            int w = getBitWidth(n);
            stMin.resize(w, std::vector<int>(n));
            stMax.resize(w, std::vector<int>(n));

            for (int i = 0; i < n; ++i) {
                stMin[0][i] = arr[i];
                stMax[0][i] = arr[i];
            }

            for (int i = 1; i < w; ++i) {
                for (int j = 0; j + (1 << i) <= n; ++j) {
                    stMin[i][j] = std::min(stMin[i - 1][j], stMin[i - 1][j + (1 << (i - 1))]);
                    stMax[i][j] = std::max(stMax[i - 1][j], stMax[i - 1][j + (1 << (i - 1))]);
                }
            }
        }

        int query(int l, int r) {
            int k = getBitWidth((uint32_t) r - l) - 1;
            int mn = std::min(stMin[k][l], stMin[k][r - (1 << k)]);
            int mx = std::max(stMax[k][l], stMax[k][r - (1 << k)]);
            return mx - mn;
        }
    };
}

#endif //ALGORITHM_SPARSETABLE_H
