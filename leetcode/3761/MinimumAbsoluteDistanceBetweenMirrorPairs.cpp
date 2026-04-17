//
// Created by Ruiguo Yang on 2026/4/17.
//

#include "MinimumAbsoluteDistanceBetweenMirrorPairs.h"

#include <algorithm>
#include <climits>
#include <vector>
#include <iostream>
#include <unordered_map>

namespace leetcode {
    int MinimumAbsoluteDistanceBetweenMirrorPairs::reverse(int x) {
        if (x < 10) {
            return x;
        }
        int ans = 0;
        while (x) {
            int tail = x % 10;
            x /= 10;
            ans = ans * 10 + tail;
        }
        return ans;
    }

    int MinimumAbsoluteDistanceBetweenMirrorPairs::minMirrorPairDistance0(std::vector<int>& nums) {
        int n = nums.size();
        std::unordered_map<int, std::vector<int>> pos;
        for (int i = 0; i < n; ++i) {
            pos[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for (int i = 0; i < n && ans != 1; ++i) {
            int r = reverse(nums[i]);
            if (pos.find(r) == pos.end()) {
                continue;
            }

            auto up = std::upper_bound(pos[r].begin(), pos[r].end(), i);
            if (up == pos[r].end()) {
                continue;
            }

            ans = std::min(ans, std::abs(*up - i));
        }

        return (ans == INT_MAX ? -1 : ans);
    }

    int MinimumAbsoluteDistanceBetweenMirrorPairs::minMirrorPairDistance1(std::vector<int> &nums) {
        int n = nums.size();
        int ans = INT_MAX;
        std::unordered_map<int, int> pos;

        for (int i = n - 1; i >= 0 && ans != 1; --i) {
            int r = reverse(nums[i]);

            if (r == nums[i]) {
                if (pos.find(r) != pos.end()) {
                    ans = std::min(ans, std::abs(pos[r] - i));
                }
                pos[r] = i;
                continue;
            }

            pos[nums[i]] = i;
            if (pos.find(r) == pos.end()) {
                continue;
            }
            ans = std::min(ans, std::abs(pos[r] - i));
        }

        return (ans == INT_MAX ? -1 : ans);
    }

    void MinimumAbsoluteDistanceBetweenMirrorPairs::test() {
        std::vector<std::vector<int>> nums {
            {12,21,45,33,54},
            {120,21},
            {21,120},
            {9, 9}
        };
        std::vector<int> expects { 1, 1, -1, 1};
        int t = nums.size();

        // Test minMirrorPairDistance0
        for (int i = 0; i < t; ++i) {
            std::vector<int> v = nums[i];
            int expect = expects[i];
            int actual = minMirrorPairDistance0(v);
            std::cout << (actual == expect ? "PASS" : "FAIL") << std::endl;
        }

        // Test minMirrorPairDistance1
        for (int i = 0; i < 4; ++i) {
            std::vector<int> v = nums[i];
            int expect = expects[i];
            int actual = minMirrorPairDistance1(v);
            std::cout << (actual == expect ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3761", leetcode::MinimumAbsoluteDistanceBetweenMirrorPairs);