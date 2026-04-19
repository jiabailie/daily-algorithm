//
// Created by Ruiguo Yang on 2026/4/19.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include "SmallestStableIndexII.h"

namespace leetcode {
    int SmallestStableIndexII::firstStableIndex(std::vector<int> &nums, int k) {
        int n = nums.size();

        std::vector<int> preMax(n, nums[0]);
        for (int i = 1; i < n; i++) {
            preMax[i] = std::max(preMax[i - 1], nums[i]);
        }

        std::vector<int> posMin(n, nums[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            posMin[i] = std::min(posMin[i + 1], nums[i]);
        }

        for (int i = 0; i < n; ++i) {
            int d = preMax[i] - posMin[i];
            if (d <= k) {
                return i;
            }
        }
        return -1;
    }

    void SmallestStableIndexII::test() {
        std::vector<std::vector<int>> nums {
            {5,0,1,4},
            {3,2,1},
            {0}
        };
        std::vector<int> k {3, 1, 0};
        std::vector<int> expect {3, -1, 0};
        for (int i = 0; i < expect.size(); i++) {
            int actual = firstStableIndex(nums[i], k[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("101047", leetcode::SmallestStableIndexII);