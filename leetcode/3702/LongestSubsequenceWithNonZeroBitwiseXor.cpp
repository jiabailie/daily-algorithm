//
// Created by ruiguo on 2026/8/20.
//

#include "LongestSubsequenceWithNonZeroBitwiseXor.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>

namespace leetcode {
    int LongestSubsequenceWithNonZeroBitwiseXor::longestSubsequence(std::vector<int> &nums) {
        int isAllZero = std::ranges::all_of(nums, [](int x) { return x == 0; });
        if (isAllZero) {
            return 0;
        }

        int xorSum = std::reduce(nums.begin(), nums.end(), 0, std::bit_xor());
        if (xorSum != 0) {
            return nums.size();
        }
        return nums.size() - 1;
    }

    void LongestSubsequenceWithNonZeroBitwiseXor::test() {
        std::vector<std::vector<int>> nums {
            {1,2,3},
            {2,3,4}
        };
        std::vector<int> expect {2,3};
        for (int i = 0; i < expect.size(); i++) {
            int actual = longestSubsequence(nums[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}
REGISTER_LEETCODE_SOLUTION("3702", leetcode::LongestSubsequenceWithNonZeroBitwiseXor);