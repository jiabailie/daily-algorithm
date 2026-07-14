//
// Created by Ruiguo on 14/7/2026.
//

#include "FindTheNumberOfSubsequencesWithEqualGCD.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ostream>

namespace leetcode {
    int FindTheNumberOfSubsequencesWithEqualGCD::subsequencePairCount(std::vector<int>& nums) {
        int m = *std::max_element(nums.begin(), nums.end());
        int n = nums.size();

        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(m + 1, 0));
        dp[0][0] = 1;

        for (int x: nums) {
            std::vector<std::vector<int>> sdp(m + 1, std::vector<int>(m + 1, 0));
            for (int i = 0; i <= m; ++i) {
                int divisor1 = std::gcd(i, x);
                for (int k = 0; k <= m; ++k) {
                    int val = dp[i][k];
                    if (val == 0) {
                        continue;
                    }
                    int divisor2 = std::gcd(k, x);
                    sdp[i][k] = (sdp[i][k] + val) % MOD;
                    sdp[divisor1][k] = (sdp[divisor1][k] + val) % MOD;
                    sdp[i][divisor2] = (sdp[i][divisor2] + val) % MOD;
                }
            }
            dp.swap(sdp);
        }

        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            ans = (ans + dp[i][i]) % MOD;
        }
        return ans;
    }

    void FindTheNumberOfSubsequencesWithEqualGCD::test() {
        std::vector<std::vector<int>> nums {
            {1,2,3,4},
            {10,20,30},
            {1,1,1,1}
        };
        std::vector<int> expect {10,2,50};
        for (int i = 0; i < expect.size(); i++) {
            int actual = subsequencePairCount(nums[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3336", leetcode::FindTheNumberOfSubsequencesWithEqualGCD);