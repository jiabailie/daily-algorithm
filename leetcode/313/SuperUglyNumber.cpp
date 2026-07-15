//
// Created by ruiguo on 2026/7/15.
//

#include "SuperUglyNumber.h"

#include <iostream>

namespace leetcode {
    int SuperUglyNumber::nthSuperUglyNumber(int n, std::vector<int> &primes) {
        std::vector<long> dp(n + 1);

        int m = primes.size();
        std::vector<long> nums(m, 1);
        std::vector<int> pointers(m, 0);
        for (int i = 1; i <= n; ++i) {
            int minIndex = 0;
            for (int j = 1; j < m; ++j) {
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }
            dp[i] = nums[minIndex];

            int minNum = nums[minIndex];
            for (int j = 0; j < m; ++j) {
                if (nums[j] == minNum) {
                    pointers[j]++;
                    nums[j] = dp[pointers[j]] * primes[j];
                }
            }
        }
        return dp[n];
    }

    void SuperUglyNumber::test() {
        std::vector<int> n {12,1};
        std::vector<std::vector<int>> primes {
            {2,7,13,19},
            {2,3,5}
        };
        std::vector<int> expect {32,1};
        for (int i = 0; i < expect.size(); i++) {
            int actual = nthSuperUglyNumber(n[i], primes[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}
REGISTER_LEETCODE_SOLUTION("313", leetcode::SuperUglyNumber);