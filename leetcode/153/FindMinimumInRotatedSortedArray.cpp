//
// Created by Ruiguo Yang on 2026/5/15.
//

#include "FindMinimumInRotatedSortedArray.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int FindMinimumInRotatedSortedArray::findMin(std::vector<int> &nums) {
        int n = nums.size();

        if (n == 1) { return nums[0]; }
        if (nums[0] < nums[n - 1]) { return nums[0]; }
        if (nums[n - 2] > nums[n - 1]) { return nums[n - 1]; }

        int s = 0, e = n - 1;
        int m = 0;
        while (s <= e) {
            m = s + (e - s) / 2;
            if (nums[0] < nums[m]) {
                if (m + 1 < n && nums[m] > nums[m + 1]) {
                    return nums[m + 1];
                }
                s = m;
                continue;
            }

            // nums[0] > nums[m]
            if (1 <= m && nums[m - 1] > nums[n - 1]) {
                return nums[m];
            }
            e = m;
        }
        return 0;
    }

    void FindMinimumInRotatedSortedArray::test() {
        std::vector<std::vector<int>> nums {
            {3,4,5,1,2},
            {4,5,6,7,0,1,2},
            {11,13,15,17},
            {1,2,3,4,5},
            {2,3,4,5,1},
            {5,1,2,3,4},
            {1},
            {2,1}
        };
        std::vector<int> expect {1,0,11,1,1,1,1,1};
        for (int i = 0; i < expect.size(); i++) {
            int actual = findMin(nums[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("153", leetcode::FindMinimumInRotatedSortedArray);