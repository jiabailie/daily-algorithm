//
// Created by Ruiguo Yang on 2026/5/1.
//

#include "RotateFunction.h"

#include <iostream>

namespace leetcode {
    int RotateFunction::maxRotateFunction(std::vector<int> &nums) {
        int n = nums.size();
        int s = 0;
        int f = 0;
        for (int i = 0; i < n; ++i) {
            s += nums[i];
            f += i * nums[i];
        }

        int ans = f;
        for (int i = 1; i < n; ++i) {
            int next = f + n * nums[i - 1] - s;
            f = next;
            ans = std::max(ans, f);
        }
        return ans;
    }

    void RotateFunction::test() {
        std::vector<std::vector<int>> nums {
                {4,3,2,6},
                {100}
        };
        std::vector<int> expect {26,0};
        for (int i = 0; i < expect.size(); i++) {
            int actual = maxRotateFunction(nums[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("396", leetcode::RotateFunction);