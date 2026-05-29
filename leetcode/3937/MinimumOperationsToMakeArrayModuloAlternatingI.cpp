//
// Created by Ruiguo Yang on 2026/5/29.
//

#include "MinimumOperationsToMakeArrayModuloAlternatingI.h"

#include <climits>
#include <iostream>
#include <ostream>

namespace leetcode {
    int MinimumOperationsToMakeArrayModuloAlternatingI::minOperations(std::vector<int> &nums, int k) {
        int ans = INT_MAX;

        for (int x = 0; x < k; ++x) {
            for (int y = 0; y < k; ++y) {
                if (y == x) { continue; }
                int target[2] = {x,y};

                int curr = 0;
                for (int i = 0; i < nums.size(); ++i) {
                    int d = std::abs(nums[i] % k - target[i % 2]);
                    curr += std::min(d, k - d);
                }
                ans = std::min(ans, curr);
            }
        }
        return ans;
    }

    void MinimumOperationsToMakeArrayModuloAlternatingI::test() {
        std::vector<std::vector<int>> nums {
            {1,4,2,8},
            {1,1,1}
        };
        std::vector<int> k {3,3};
        std::vector<int> expect {2,1};
        for (int i = 0; i < expect.size(); i++) {
            int actual = minOperations(nums[i], k[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3937", leetcode::MinimumOperationsToMakeArrayModuloAlternatingI);