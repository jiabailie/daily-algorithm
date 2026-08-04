//
// Created by ruiguo on 2026/8/4.
//

#include "WidestPossibleFence.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int WidestPossibleFence::maximumWidth(std::vector<int> &planks) {
        std::unordered_map<int, int> cnt;
        for (int x: planks) {
            cnt[x]++;
        }

        std::unordered_map<int, int> cntPair;
        for (auto& [x, c1]: cnt) {
            cntPair[x] += c1;
            cntPair[x * 2] += c1 / 2;

            for (auto& [y, c2]: cnt) {
                if (x < y) {
                    cntPair[x + y] += std::min(c1, c2);
                }
            }
        }

        int ans = 0;
        for (auto& [_, c]: cntPair) {
            ans = std::max(ans, c);
        }
        return ans;
    }

    void WidestPossibleFence::test() {
        std::vector<std::vector<int>> planks {
            {1,3,2,5,7,5,4,2,1},
            {2,3,7},
            {59,37,55,90,94}
        };
        std::vector<int> expect {4,1,2};
        for (int i = 0; i < expect.size(); i++) {
            int actual = maximumWidth(planks[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}
REGISTER_LEETCODE_SOLUTION("4007", leetcode::WidestPossibleFence);