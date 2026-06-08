//
// Created by Ruiguo Yang on 2026/6/8.
//

#include "PartitionArrayAccordingToGivenPivot.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    std::vector<int> PartitionArrayAccordingToGivenPivot::pivotArray(std::vector<int> &nums, int pivot) {
        int n = nums.size();
        std::vector<int> ans(n, pivot);

        int s = 0, e = n - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                ans[s++] = nums[i];
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (pivot < nums[i]) {
                ans[e--] = nums[i];
            }
        }

        return ans;
    }

    void PartitionArrayAccordingToGivenPivot::test() {
        std::vector<std::vector<int>> nums {
            {9,12,5,10,14,3,10},
            {-3,4,3,2}
        };
        std::vector<int> pivot {10, 2};
        std::vector<std::vector<int>> expect {
            {9,5,3,10,10,12,14},
            {-3,2,4,3}
        };
        for (int i = 0; i < expect.size(); i++) {
            std::vector<int> actual = pivotArray(nums[i], pivot[i]);
            bool isEqual = std::equal(expect[i].begin(), expect[i].end(), actual.begin(), actual.end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("2161", leetcode::PartitionArrayAccordingToGivenPivot);