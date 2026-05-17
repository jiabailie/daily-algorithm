//
// Created by Ruiguo Yang on 2026/5/17.
//

#include "JumpGameIII.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    bool JumpGameIII::canReach(std::vector<int> &arr, int start) {
        int n = arr.size();
        std::vector<bool> v(n, false);

        auto dfs = [&](auto&& dfs, int i) -> bool {
            if (i < 0 || i >= n || v[i]) {
                return false;
            }

            if (arr[i] == 0) {
                return true;
            }

            v[i] = true;
            return dfs(dfs, i - arr[i]) || dfs(dfs, i + arr[i]);
        };
        return dfs(dfs, start);
    }

    void JumpGameIII::test() {
        std::vector<std::vector<int>> arr {
            {4,2,3,0,3,1,2},
            {4,2,3,0,3,1,2},
            {3,0,2,1,2}
        };
        std::vector<int> start {5,0,2};
        std::vector<bool> expect {true,true,false};
        for (int i = 0; i < expect.size(); i++) {
            bool actual = canReach(arr[i], start[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1306", leetcode::JumpGameIII);
