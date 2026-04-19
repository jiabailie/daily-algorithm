//
// Created by Ruiguo Yang on 2026/4/19.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include "MaximumDistanceBetweenAPairOfValues.h"

namespace leetcode {
    int MaximumDistanceBetweenAPairOfValues::maxDistance1(std::vector<int> &nums1, std::vector<int> &nums2) {
        int ans = 0;
        int l1 = nums1.size();
        int l2 = nums2.size();
        for (int i = 0; i < l2; ++i) {
            if (i < nums1.size() && nums1[i] > nums2[i]) {
                continue;
            }

            auto end = i >= nums1.size() ? nums1.end() : nums1.begin() + i;
            auto it = std::lower_bound(nums1.begin(), end, nums2[i], [](int a, int b) { return a > b; });

            if (it == nums1.end()) {
                continue;
            }

            int j = it - nums1.begin();
            ans = std::max(ans, i - j);
        }
        return ans;
    }

    int MaximumDistanceBetweenAPairOfValues::maxDistance2(std::vector<int> &nums1, std::vector<int> &nums2) {
        int ans = 0;
        int i = 0;
        for (int j = 0; j < nums2.size(); ++j) {
            while (i < nums1.size() && nums1[i] > nums2[j]) {
                i++;
            }
            if (i == nums1.size()) {
                break;
            }
            ans = std::max(ans, j - i);
        }
        return ans;
    }

    void MaximumDistanceBetweenAPairOfValues::test() {
        std::vector<std::vector<int>> nums1 {
            {55,30,5,4,2},
            {2,2,2},
            {30,29,19,5}
        };
        std::vector<std::vector<int>> nums2 {
            {100,20,10,10,5},
            {10,10,1},
            {25,25,25,25,25}
        };
        std::vector<int> expect {2, 1, 2};

        for (int i = 0; i < expect.size(); ++i) {
            int actual = maxDistance1(nums1[i], nums2[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
        for (int i = 0; i < expect.size(); ++i) {
            int actual = maxDistance2(nums1[i], nums2[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1855", leetcode::MaximumDistanceBetweenAPairOfValues);
