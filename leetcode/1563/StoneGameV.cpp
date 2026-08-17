//
// Created by ruiguo on 2026/8/17.
//

#include "StoneGameV.h"

#include <iostream>
#include <numeric>

namespace leetcode {
    int StoneGameV::stoneGameV(std::vector<int> &stoneValue) {
        int n = stoneValue.size();
        std::vector<int> sum(n + 1);
        std::partial_sum(stoneValue.begin(), stoneValue.end(), sum.begin() + 1);
        std::vector<std::vector<int>> f(n, std::vector<int>(n + 1));
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 2; j <= n; j++) {
                for (int k = i + 1; k < j; k++) {
                    int left = sum[k] - sum[i];
                    int right = sum[j] - sum[k];

                    int score = 0;
                    if (left < right) {
                        score = f[i][k] + left;
                    } else if (left > right) {
                        score = f[k][j] + right;
                    } else {
                        score = std::max(f[i][k], f[k][j]) + left;
                    }
                    f[i][j] = std::max(f[i][j], score);
                }
            }
        }
        return f[0][n];
    }

    void StoneGameV::test() {
        std::vector<std::vector<int>> stoneValue {
            {6,2,3,4,5,5},
            {7,7,7,7,7,7,7},
            {4}
        };
        std::vector<int> expect {18,28,0};
        for (int i = 0; i < expect.size(); i++) {
            int actual = stoneGameV(stoneValue[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}
REGISTER_LEETCODE_SOLUTION("1563", leetcode::StoneGameV);