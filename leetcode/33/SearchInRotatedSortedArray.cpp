//
// Created by Ruiguo Yang on 2026/5/22.
//

#include "SearchInRotatedSortedArray.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int SearchInRotatedSortedArray::search(std::vector<int> &nums, int target) {
        int n = nums.size();
        if (n == 0) { return -1; }
        if (n == 1) { return nums[0] == target ? 0 : -1; }

        int s = 0, e = n - 1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (nums[m] == target) { return m; }
            if (nums[0] <= nums[m]) {
                if (nums[0] <= target && target < nums[m]) {
                    e = m - 1;
                } else {
                    s = m + 1;
                }
            } else {
                if (nums[m] < target && target <= nums[n - 1]) {
                    s = m + 1;
                } else {
                    e = m - 1;
                }
            }
        }
        return -1;
    }

    void SearchInRotatedSortedArray::test() {
        std::vector<std::vector<int>> nums {
            {4,5,6,7,0,1,2},
            {4,5,6,7,0,1,2},
            {1}
        };
        std::vector<int> target { 0,3,0 };
        std::vector<int> expect { 4,-1,-1 };
        for (int i = 0; i < expect.size(); i++) {
            int actual = search(nums[i], target[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("33", leetcode::SearchInRotatedSortedArray);