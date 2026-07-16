//
// Created by Ruiguo on 16/7/2026.
//

#include "SumOfGCDOfFormedPairs.h"

#include <algorithm>
#include <iostream>

namespace leetcode {
    int SumOfGCDOfFormedPairs::gcd(int a, int b) {
        if (a == 1 || b == 1) {
            return 1;
        }
        if (a < b) {
            return gcd(b, a);
        }

        while (b != 0) {
            int c = a % b;
            a = b;
            b = c;
        }
        return a;
    }

    long long SumOfGCDOfFormedPairs::gcdSum(std::vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        std::vector<int> pairs(n);
        for (int i = 0; i < n; i++) {
            mx = std::max(mx, nums[i]);
            pairs[i] = gcd(nums[i], mx);
        }

        std::sort(pairs.begin(), pairs.end());
        long long ans = 0;
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            ans += gcd(pairs[i], pairs[j]);
        }
        return ans;
    }

    void SumOfGCDOfFormedPairs::test() {
        std::vector<std::vector<int>> nums {
            {2,6,4},
            {3,6,2,8}
        };
        std::vector<long long> expect {2,5};
        for (int i = 0; i < expect.size(); i++) {
            long long actual = gcdSum(nums[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3867", leetcode::SumOfGCDOfFormedPairs);
