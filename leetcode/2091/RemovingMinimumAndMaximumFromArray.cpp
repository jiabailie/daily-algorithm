//
// Created by Ruiguo on 30/8/2026.
//

#include "RemovingMinimumAndMaximumFromArray.h"

#include <climits>
#include <iostream>

namespace leetcode {
    int RemovingMinimumAndMaximumFromArray::minimumDeletions(std::vector<int>& nums) {
        int n = nums.size();

        int minVal = INT_MAX;
        int minIndex = -1;
        int maxVal = INT_MIN;
        int maxIndex = -1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < minVal) {
                minVal = nums[i];
                minIndex = i;
            }
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxIndex = i;
            }
        }

        int f1 = std::min(minIndex, maxIndex);
        int f2 = std::max(minIndex, maxIndex);
        int ans = std::min({n + f1 - f2 + 1, f2 + 1, n - f1});
        return ans;
    }

    void RemovingMinimumAndMaximumFromArray::test() {
        std::vector<std::vector<int>> nums {{2,10,7,5,4,1,8,6},{0,-4,19,1,8,-2,-3,5},{101}};
        std::vector<int> expect {5,3,1};
        for (int i = 0; i < expect.size(); ++i) {
            int actual = minimumDeletions(nums[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}
REGISTER_LEETCODE_SOLUTION("2091", leetcode::RemovingMinimumAndMaximumFromArray);