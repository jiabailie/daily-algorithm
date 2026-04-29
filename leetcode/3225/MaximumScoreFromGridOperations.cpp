//
// Created by Ruiguo Yang on 2026/4/29.
//

#include "MaximumScoreFromGridOperations.h"

#include <iostream>

namespace leetcode {
    long long MaximumScoreFromGridOperations::maximumScore(std::vector<std::vector<int> > &grid) {
        int n = grid.size();
        std::vector<std::vector<long long>> colSum(n, std::vector<long long>(n + 1));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                colSum[j][i + 1] = colSum[j][i] + grid[i][j];
            }
        }

        std::vector<std::vector<std::array<long long, 2>>> f(n, std::vector<std::array<long long, 2>>(n + 1));
        for (int j = 0; j < n - 1; ++j) {
            for (int pre = 0; pre <= n; ++pre) {
                for (int dec = 0; dec < 2; ++dec) {
                    auto& res = f[j + 1][pre][dec];
                    for (int cur = 0; cur <= n; ++cur) {
                        if (cur == pre) {
                            res = std::max(res, f[j][cur][0]);
                        } else if (cur < pre) {
                            res = std::max(res, f[j][cur][1] + colSum[j][pre] - colSum[j][cur]);
                        } else if (dec == 0) {
                            res = std::max(res, f[j][cur][0] + colSum[j + 1][cur] - colSum[j + 1][pre]);
                        } else if (pre == 0) {
                            res = std::max(res, f[j][cur][0]);
                        }
                    }
                }
            }
        }

        long long ans = 0;
        for (auto& row: f[n - 1]) {
            ans = std::max(ans, row[0]);
        }
        return ans;
    }

    void MaximumScoreFromGridOperations::test() {
        std::vector<std::vector<std::vector<int>>> grid {
            {{0,0,0,0,0},{0,0,3,0,0},{0,1,0,0,0},{5,0,0,3,0},{0,0,0,0,2}},
            {{10,9,0,0,15},{7,1,0,8,0},{5,20,0,11,0},{0,0,0,1,2},{8,12,1,10,3}}
        };
        std::vector<long long> expect {11,94};
        for (int i = 0; i < expect.size(); i++) {
            long long actual = maximumScore(grid[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3225", leetcode::MaximumScoreFromGridOperations);