//
// Created by ruiguo on 2026/6/26.
//

#include "CountSubarraysWithMajorityElementII.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    long long CountSubarraysWithMajorityElementII::countMajoritySubarrays(std::vector<int> &nums, int target) {
        std::unordered_map<int, int> cnt = {{0, 1}};
        long long ans = 0;
        int s = 0, f = 0;
        for (int x: nums) {
            if (x == target) {
                f += cnt[s];
                s++;
            } else {
                s--;
                f -= cnt[s];
            }
            ans += f;
            cnt[s]++;
        }
        return ans;
    }

    void CountSubarraysWithMajorityElementII::test() {
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

REGISTER_LEETCODE_SOLUTION("3739", leetcode::CountSubarraysWithMajorityElementII);