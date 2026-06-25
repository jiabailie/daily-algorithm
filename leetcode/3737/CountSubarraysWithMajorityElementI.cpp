//
// Created by ruiguo on 2026/6/25.
//

#include "CountSubarraysWithMajorityElementI.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int CountSubarraysWithMajorityElementI::countMajoritySubarrays(std::vector<int> &nums, int target) {
        int n = nums.size();
        std::vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i];
            if (nums[i] == target) {
                cnt[i + 1]++;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int cntTarget = cnt[j + 1] - cnt[i];
                if (cntTarget * 2 > j - i + 1) {
                    ans++;
                }
            }
        }
        return ans;
    }

    void CountSubarraysWithMajorityElementI::test() {
        std::vector<std::vector<int>> nums {
            {1,2,2,3},
            {1,1,1,1},
            {1,2,3}
        };
        std::vector<int> target {2,1,4};
        std::vector<int> expect {5,10,0};
        for (int i = 0; i < expect.size(); i++) {
            int actual = countMajoritySubarrays(nums[i], target[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3737", leetcode::CountSubarraysWithMajorityElementI);
