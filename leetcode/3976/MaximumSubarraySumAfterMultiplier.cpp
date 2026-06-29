//
// Created by ruiguo on 2026/6/29.
//

#include "MaximumSubarraySumAfterMultiplier.h"

#include <climits>
#include <iostream>
#include <ostream>

namespace leetcode {
    long long MaximumSubarraySumAfterMultiplier::maxSubarraySum(std::vector<int> &nums, int k) {
        auto solve = [&](bool isMul) -> long long {
            long long res = LLONG_MIN;
            int n = nums.size();
            std::vector<std::array<long long, 3>> f(n + 1);

            for (int i = 0; i < n; ++i) {
                long long x = nums[i];
                long long y = isMul ? x * k : x / k;

                f[i + 1][0] = std::max(f[i][0], 0LL) + x;
                f[i + 1][1] = std::max(std::max(f[i][0], f[i][1]), 0LL) + y;
                f[i + 1][2] = std::max(f[i][1], f[i][2]) + x;
                res = std::max(res, std::max(f[i + 1][1], f[i + 1][2]));
            }
            return res;
        };

        return std::max(solve(true), solve(false));
    }

    void MaximumSubarraySumAfterMultiplier::test() {
        std::vector<std::vector<int>> nums {
            {1,-2,3,4,-5},
            {-5,-4,-3}
        };
        std::vector<int> k {2,2};
        std::vector<long long> expect {14,-1};
        for (int i = 0; i < expect.size(); i++) {
            long long actual = maxSubarraySum(nums[i], k[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3976", leetcode::MaximumSubarraySumAfterMultiplier);