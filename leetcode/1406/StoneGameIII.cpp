//
// Created by ruiguo on 2026/8/3.
//

#include "StoneGameIII.h"

#include <climits>
#include <iostream>
#include <ostream>

namespace leetcode {
    std::string StoneGameIII::stoneGameIII(std::vector<int> &stoneValue) {
        int n = stoneValue.size();
        std::vector<int> f(n + 1);

        for (int i = n - 1; i >= 0; --i) {
            f[i] = INT_MIN;
            int sum = 0;
            for (int j = i; j < std::min(i + 3, n); ++j) {
                sum += stoneValue[j];
                f[i] = std::max(f[i], sum - f[j + 1]);
            }
        }

        int diff = f[0];
        if (diff == 0) {
            return "Tie";
        }
        return diff > 0 ? "Alice" : "Bob";
    }

    void StoneGameIII::test() {
        std::vector<std::vector<int>> stoneValues = {
            {1,2,3,7},
            {1,2,3,-9},
            {1,2,3,6}
        };
        std::vector<std::string> expect {"Bob", "Alice", "Tie"};
        for (int i = 0; i < expect.size(); i++) {
            std::string actual = stoneGameIII(stoneValues[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}
REGISTER_LEETCODE_SOLUTION("1406", leetcode::StoneGameIII);