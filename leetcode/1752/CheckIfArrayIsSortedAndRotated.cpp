//
// Created by Ruiguo Yang on 2026/5/23.
//

#include "CheckIfArrayIsSortedAndRotated.h"

#include <iostream>

namespace leetcode {
    bool CheckIfArrayIsSortedAndRotated::check(std::vector<int> &nums) {
        int n = nums.size();
        int cnt = 0;
        int p = -1;
        for (int i = 0; i + 1 < n; ++i) {
            if (nums[i] <= nums[i + 1]) { continue; }

            cnt++;
            if (p == -1) { p = i; }
            if (cnt >= 2) { return false; }
        }

        if (cnt == 1) {
            for (int i = 0; i <= p; ++i) {
                if (nums[i] < nums[n - 1]) { return false; }
                if (i > 0 && nums[i - 1] > nums[i]) { return false; }
            }
        }
        return true;
    }

    void CheckIfArrayIsSortedAndRotated::test() {
        std::vector<std::vector<int>> nums {
            {3,4,5,1,2},
            {2,1,3,4},
            {1,2,3}
        };
        std::vector<bool> expect {true,false,true};
        for (int i = 0; i < expect.size(); i++) {
            bool actual = check(nums[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1752", leetcode::CheckIfArrayIsSortedAndRotated);