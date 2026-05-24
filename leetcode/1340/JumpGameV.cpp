//
// Created by Ruiguo Yang on 2026/5/24.
//

#include "JumpGameV.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int JumpGameV::maxJumps(std::vector<int> &arr, int d) {
        int n = arr.size();
        std::vector<int> memo(n);

        auto dfs = [&](auto&& dfs, int i) -> int {
            int& res = memo[i];
            if (res) { return res; }

            res = 1;

            // to left
            for (int j = i - 1; j >= std::max(i - d, 0) && arr[j] < arr[i]; --j) {
                res = std::max(res, dfs(dfs, j) + 1);
            }

            // to right
            for (int j = i + 1; j <= std::min(i + d, n - 1) && arr[j] < arr[i]; ++j) {
                res = std::max(res, dfs(dfs, j) + 1);
            }
            return res;
        };

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = std::max(ans, dfs(dfs, i));
        }
        return ans;
    }

    void JumpGameV::test() {
        std::vector<std::vector<int>> arr {
            {6,4,14,6,8,13,9,7,10,6,12},
            {3,3,3,3,3},
            {7,6,5,4,3,2,1}
        };
        std::vector<int> d { 2, 3, 1 };
        std::vector<int> expect { 4, 1, 7 };
        for (int i = 0; i < expect.size(); i++) {
            int actual = maxJumps(arr[i], d[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1340", leetcode::JumpGameV);