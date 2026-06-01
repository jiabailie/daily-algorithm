//
// Created by Ruiguo Yang on 2026/6/1.
//

#include "MaximumNumberOfItemsFromSaleI.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int MaximumNumberOfItemsFromSaleI::maximumSaleItems(std::vector<std::vector<int> > &items, int budget) {
        int n = items.size();

        std::vector<int> factor(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (items[i][0] % items[j][0] == 0) {
                    factor[j]++;
                }
                if (items[j][0] % items[i][0] == 0) {
                    factor[i]++;
                }
            }
        }

        std::vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; ++i) {
            int price = items[i][1];
            int bought = 1 + factor[i];
            for (int j = budget; j >= price; --j) {
                dp[j] = std::max(dp[j], dp[j - price] + bought);
            }
        }

        for (int i = 0; i < n; ++i) {
            int price = items[i][1];
            for (int j = price; j <= budget; ++j) {
                dp[j] = std::max(dp[j], dp[j - price] + 1);
            }
        }
        return dp[budget];
    }

    void MaximumNumberOfItemsFromSaleI::test() {
        std::vector<std::vector<std::vector<int>>> items {
            {{6,2},{2,6},{3,4}},
            {{2,4},{3,2},{4,1},{6,4},{12,4}}
        };
        std::vector<int> budget {9,8};
        std::vector<int> expect {4,10};
        for (int i = 0; i < expect.size(); i++) {
            int actual = maximumSaleItems(items[i], budget[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3946", leetcode::MaximumNumberOfItemsFromSaleI);