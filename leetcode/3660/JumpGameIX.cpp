//
// Created by Ruiguo Yang on 2026/5/7.
//

#include "JumpGameIX.h"

#include <iostream>

namespace leetcode {
    std::vector<int> JumpGameIX::maxValue(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> preMax(n, nums[0]);
        for (int i = 1; i < n; ++i) {
            preMax[i] = std::max(preMax[i - 1], nums[i]);
        }

        int posMin = INT_MAX;
        std::vector<int> ans(n);
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = preMax[i] <= posMin ? preMax[i] : ans[i + 1];
            posMin = std::min(posMin, nums[i]);
        }
        return ans;
    }

    void JumpGameIX::test() {
        std::vector<std::vector<int>> nums {
            {2,1,3},
            {2,3,1}
        };
        std::vector<std::vector<int>> expect {
            {2,2,3},
            {3,3,3}
        };
        for (int i = 0; i < expect.size(); i++) {
            std::vector<int> actual = maxValue(nums[i]);
            bool isEqual = std::equal(expect[i].begin(), expect[i].end(), actual.begin(), actual.end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3660", leetcode::JumpGameIX);