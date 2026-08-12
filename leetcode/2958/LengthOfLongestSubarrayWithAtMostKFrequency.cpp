//
// Created by Ruiguo on 12/8/2026.
//

#include "LengthOfLongestSubarrayWithAtMostKFrequency.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int LengthOfLongestSubarrayWithAtMostKFrequency::maxSubarrayLength(std::vector<int>& nums, int k) {
        int ans = 0;
        int left = 0;
        std::unordered_map<int, int> cnt;
        for (int right = 0; right < nums.size(); ++right) {
            cnt[nums[right]]++;
            while (cnt[nums[right]] > k) {
                cnt[nums[left]]--;
                left++;
            }
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }

    void LengthOfLongestSubarrayWithAtMostKFrequency::test() {
        std::vector<std::vector<int>> nums {
            {1,2,3,1,2,3,1,2},
            {1,2,1,2,1,2,1,2},
            {5,5,5,5,5,5,5}
        };
        std::vector<int> k {2,1,4};
        std::vector<int> expect {6,2,4};
        for (int i = 0; i < expect.size(); i++) {
            int actual = maxSubarrayLength(nums[i], k[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}
REGISTER_LEETCODE_SOLUTION("2958", leetcode::LengthOfLongestSubarrayWithAtMostKFrequency);