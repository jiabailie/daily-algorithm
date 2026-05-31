//
// Created by Ruiguo Yang on 2026/5/31.
//

#include "LexicographicallyMaximumMEXArray.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    std::vector<int> LexicographicallyMaximumMEXArray::maximumMEX(std::vector<int> &nums) {
        int n = nums.size();

        int maxVal = 0;
        for (int x: nums) {
            maxVal = std::max(maxVal, x);
        }

        std::vector<int> cnt(maxVal + 2, 0);
        for (int x: nums) {
            cnt[x]++;
        }

        int i = 0;
        std::vector<int> result;
        std::vector<bool> seen(maxVal + 2, false);
        while (i < n) {
            int maxMex = 0;
            while (cnt[maxMex] > 0) {
                maxMex++;
            }

            if (maxMex == 0) {
                result.push_back(0);
                cnt[nums[i]]--;
                i++;

                continue;
            }

            int countDistance = 0;
            int j = i;
            while (j < n && countDistance < maxMex) {
                int val = nums[j];
                if (val < maxMex && !seen[val]) {
                    seen[val] = true;
                    countDistance++;
                }
                j++;
            }

            result.push_back(maxMex);

            for (int k = i; k < j; ++k) {
                cnt[nums[k]]--;
                if (nums[k] < maxMex) {
                    seen[nums[k]] = false;
                }
            }
            i = j;
        }
        return result;
    }

    void LexicographicallyMaximumMEXArray::test() {
        std::vector<std::vector<int>> nums {
            {0,1,0},
            {1,0,2},
            {3,1}
        };
        std::vector<std::vector<int>> expect {
            {2,1},
            {3},
            {0,0}
        };
        for (int i = 0; i < expect.size(); i++) {
            std::vector<int> actual = maximumMEX(nums[i]);
            bool isEqual = std::equal(expect[i].begin(), expect[i].end(), actual.begin(), actual.end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("100947", leetcode::LexicographicallyMaximumMEXArray);