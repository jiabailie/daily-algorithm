//
// Created by Ruiguo Yang on 2025/12/17.
//

#include "BestTimeToBuyandSellStockV.h"

#include <array>
#include <climits>
#include <iostream>
#include <vector>

namespace leetcode {
    long long BestTimeToBuyandSellStockV::maximumProfit(std::vector<int> &prices, int k) {
        int n = prices.size();
        std::vector f(n + 1, std::vector<std::array<long long, 3>>(k + 2, {LLONG_MIN / 2, LLONG_MIN / 2, LLONG_MIN / 2}));
        for (int j = 1; j <= k + 1; ++j) {
            f[0][j][0] = 0;
        }

        for (int i = 0; i < n; ++i) {
            int p = prices[i];
            for (int j = 1; j <= k + 1; ++j) {
                f[i + 1][j][0] = std::max({f[i][j][0], f[i][j][1] + p, f[i][j][2] - p});
                f[i + 1][j][1] = std::max(f[i][j][1], f[i][j - 1][0] - p);
                f[i + 1][j][2] = std::max(f[i][j][2], f[i][j - 1][0] + p);
            }
        }
        return f[n][k + 1][0];
    }

    void BestTimeToBuyandSellStockV::test() {
        std::vector<int> prices = {1,7,8,9,2};
        int k = 2;
        long long actual = maximumProfit(prices, k);
        long long expect = 14;

        std::cout << (actual == expect ? "PASS" : "FAIL") << std::endl;
    }
} // leetcode

REGISTER_LEETCODE_SOLUTION("3573", leetcode::BestTimeToBuyandSellStockV);
