//
// Created by Ruiguo Yang on 2026/5/26.
//

#include "MinimumOperationsToSortAPermutation.h"

#include <climits>
#include <iostream>
#include <ostream>

namespace leetcode {
    int MinimumOperationsToSortAPermutation::minOperations(std::vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) { return 0; }

        int idxZero = -1;
        for (int i = 0; i < n && idxZero == -1; ++i) {
            if (nums[i] == 0) {
                idxZero = i;
            }
        }

        bool isIncreasing = true;
        for (int i = 0; i < n && isIncreasing; ++i) {
            if (nums[(idxZero + i) % n] != i) {
                isIncreasing = false;
            }
        }

        bool isDecreasing = true;
        for (int i = 0; i < n && isDecreasing; ++i) {
            int e = i == 0 ? 0 : n - i;
            if (nums[(idxZero + i) % n] != e) {
                isDecreasing = false;
            }
        }

        if (!isIncreasing && !isDecreasing) { return -1; }

        int ans = INT_MAX;
        if (isIncreasing) {
            ans = idxZero;

            int zeroPosAfterReverse = n - 1 - idxZero;
            int shifts = (zeroPosAfterReverse - (n - 1) + n) % n;
            ans = std::min(ans, 2 + shifts);
        }

        if (isDecreasing) {
            int shifts = (idxZero - (n - 1) + n) % n;
            ans = std::min(ans, shifts + 1);

            int zeroPosAfterReverse = n - 1 - idxZero;
            ans = std::min(ans, 1 + zeroPosAfterReverse);
        }

        return ans;
    }

    void MinimumOperationsToSortAPermutation::test() {
        std::vector<std::vector<int>> nums {
            {0,2,1},
            {1,0,2},
            {2,0,1,3}
        };
        std::vector<int> expect {2,2,-1};
        for (int i = 0; i < expect.size(); i++) {
            int actual = minOperations(nums[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3942", leetcode::MinimumOperationsToSortAPermutation);
