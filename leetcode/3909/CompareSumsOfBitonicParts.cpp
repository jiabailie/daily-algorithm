//
// Created by Ruiguo Yang on 2026/5/3.
//

#include "CompareSumsOfBitonicParts.h"

#include <iostream>

namespace leetcode {
    int CompareSumsOfBitonicParts::compareBitonicSums(std::vector<int> &nums) {
        int peak = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i == 0 && (i + 1 < n && nums[i] > nums[i + 1])) {
                peak = 0;
                break;
            }
            if (i == n - 1 && (i - 1 >= 0 && nums[i - 1] < nums[i])) {
                peak = n - 1;
                break;
            }
            if (0 < i && i + 1 < n && nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
                peak = i;
                break;
            }
        }

        long long preSum = 0;
        for (int i = 0; i <= peak; ++i) {
            preSum += nums[i];
        }

        long long postSum = 0;
        for (int i = peak; i < n; ++i) {
            postSum += nums[i];
        }

        if (preSum > postSum) {
            return 0;
        } else if (preSum < postSum) {
            return 1;
        }
        return -1;
    }

    void CompareSumsOfBitonicParts::test() {
        std::vector<std::vector<int>> nums {
            {1,3,2,1},
            {2,4,5,2},
            {1,2,4,3}
        };
        std::vector<int> expect {1,0,-1};
        for (int i = 0; i < expect.size(); i++) {
            int actual = compareBitonicSums(nums[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3909", leetcode::CompareSumsOfBitonicParts);
