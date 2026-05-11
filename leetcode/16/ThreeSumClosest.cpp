//
// Created by Ruiguo Yang on 2026/5/11.
//

#include "ThreeSumClosest.h"

#include <climits>
#include <iostream>

namespace leetcode {
    int ThreeSumClosest::threeSumClosest(std::vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = INT_MAX / 2;
        for (int i = 0; i < n - 2; ++i) {
            int x = nums[i];
            if (i > 0 && x == nums[i - 1]) {
                continue;
            }

            int s = x + nums[i + 1] + nums[i + 2];
            if (s > target) {
                if (s - target < abs(ans - target)) {
                    ans = s;
                }
                break;
            }

            s = x + nums[n - 2] + nums[n - 1];
            if (s < target) {
                if (target - s < abs(ans - target)) {
                    ans = s;
                }
                continue;
            }

            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                s = x + nums[j] + nums[k];
                if (s == target) {
                    return target;
                }
                if (abs(s - target) < abs(ans - target)) {
                    ans = s;
                }
                if (s > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        return ans;
    }

    void ThreeSumClosest::test() {
        std::vector<std::vector<int>> nums {
            {-1,2,1,-4},
            {0,0,0}
        };
        std::vector<int> targets {1,1};
        std::vector<int> expect {2,0};
        for (int i = 0; i < expect.size(); i++) {
            int actual = threeSumClosest(nums[i], targets[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("16", leetcode::ThreeSumClosest);