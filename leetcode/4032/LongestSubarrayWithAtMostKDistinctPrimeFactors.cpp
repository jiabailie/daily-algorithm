//
// Created by ruiguo on 2026/8/25.
//

#include "LongestSubarrayWithAtMostKDistinctPrimeFactors.h"

#include <iostream>

namespace leetcode {
    constexpr int LongestSubarrayWithAtMostKDistinctPrimeFactors::MX;
    std::vector<int> LongestSubarrayWithAtMostKDistinctPrimeFactors::primeFactors[LongestSubarrayWithAtMostKDistinctPrimeFactors::MX];
    int LongestSubarrayWithAtMostKDistinctPrimeFactors::init = LongestSubarrayWithAtMostKDistinctPrimeFactors::initPrimeFactors();

    int LongestSubarrayWithAtMostKDistinctPrimeFactors::longestSubarray(std::vector<int> &nums, int k) {
        int ans = 0;
        int left = 0;
        std::unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            for (int p: primeFactors[x]) {
                cnt[p]++;
            }
            while (cnt.size() > k) {
                for (int p: primeFactors[nums[left]]) {
                    auto it = cnt.find(p);
                    if (--it->second == 0) {
                        cnt.erase(it);
                    }
                }
                left++;
            }
            ans = std::max(ans, i - left + 1);
        }
        return ans;
    }

    void LongestSubarrayWithAtMostKDistinctPrimeFactors::test() {
        std::vector<std::vector<int>> nums {
            {7,6,10,12,11},
            {4,6,9,18},
            {6,10,15}
        };
        std::vector<int> k {3,4,2};
        std::vector<int> expect {3,4,1};
        for (int i = 0; i < expect.size(); ++i) {
            int actual = longestSubarray(nums[i], k[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}
REGISTER_LEETCODE_SOLUTION("4032", leetcode::LongestSubarrayWithAtMostKDistinctPrimeFactors);