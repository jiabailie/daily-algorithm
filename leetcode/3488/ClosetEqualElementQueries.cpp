//
// Created by Ruiguo Yang on 2026/4/16.
//

#include "ClosetEqualElementQueries.h"

#include <iostream>
#include <ostream>
#include <unordered_map>
#include <vector>

namespace leetcode {
    std::vector<int> ClosetEqualElementQueries::solveQueries(std::vector<int>& nums, std::vector<int>& queries) {
        int n = nums.size();
        std::vector<int> secondIndex(n, 0);
        std::unordered_map<int, std::vector<int>> pos;
        for (int i = 0; i < n; ++i) {
            pos[nums[i]].push_back(i);
            secondIndex[i] = pos[nums[i]].size() - 1;
        }

        int m = queries.size();
        std::vector<int> ans(m, -1);
        for (int i = 0; i < m; ++i) {
            int idx = queries[i];
            int val = nums[idx];
            if (pos[val].size() == 1) {
                continue;
            }

            int len = pos[val].size();
            int j = secondIndex[idx];

            int prev = pos[val][(j - 1 + len) % len];
            int next = pos[val][(j + 1) % len];

            int left = std::min({abs(prev - idx), abs(prev + n - idx) % n, abs(idx + n - prev) % n});
            int right = std::min({abs(next - idx), abs(next + n - idx) % n, abs(idx + n - next) % n});
            ans[i] = std::min(left, right);
        }
        return ans;
    }

    void ClosetEqualElementQueries::test() {
        std::vector<std::vector<int>> nums {
            {1,3,1,4,1,3,2},
            {1,2,3,4},
            {14,14,4,2,19,19,14,19,14},
            {6,12,17,9,16,7,6}
        };

        std::vector<std::vector<int>> queries {
            {0,3,5},
            {0,1,2,3},
            {2,4,8,6,3},
            {5,6,0,4}
        };

        std::vector<std::vector<int>> results {
            {2,-1,3},
            {-1,-1,-1,-1},
            {-1,1,1,2,-1},
            {-1,1,1,-1}
        };

        int t = nums.size();
        for (int i = 0; i < t; ++i) {
            std::vector<int> actual = solveQueries(nums[i], queries[i]);
            std::vector<int> expected = results[i];

            if (expected.size() != actual.size()) {
                std::cout << "FAILED" << std::endl;
                continue;
            }

            bool isPassed = true;
            for (int j = 0; j < expected.size() && isPassed; ++j) {
                if (actual[j] != expected[j]) {
                    std::cout << "FAILED" << std::endl;
                    isPassed = false;
                }
            }

            if (isPassed) {
                std::cout << "PASSED" << std::endl;
            }
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3488", leetcode::ClosetEqualElementQueries);
