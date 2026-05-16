//
// Created by Ruiguo Yang on 2026/5/16.
//

#include "FindMinimumInRotatedSortedArrayII.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int FindMinimumInRotatedSortedArrayII::findMin(std::vector<int> &nums) {
        int left = -1;
        int right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == nums[right]) {
                right--;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return nums[right];
    }

    void FindMinimumInRotatedSortedArrayII::test() {
        std::vector<std::vector<int>> nums {
            {1,3,5},
            {2,2,2,0,1},
            {1,1},
            {3,1,1},
            {3,1,3},
            {1}
        };
        std::vector<int> expect {1,0,1,1,1,1};
        for (int i = 0; i < expect.size(); i++) {
            int actual = findMin(nums[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("154", leetcode::FindMinimumInRotatedSortedArrayII);
