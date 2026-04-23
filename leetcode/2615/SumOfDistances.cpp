//
// Created by Ruiguo Yang on 2026/4/23.
//

#include "SumOfDistances.h"

#include <iostream>
#include <ostream>
#include <unordered_map>

namespace leetcode {
    std::vector<long long> SumOfDistances::distance(std::vector<int> &nums) {
        int n = nums.size();
        std::unordered_map<int, std::vector<int>> groups;
        for (int i = 0; i < n; ++i) {
            groups[nums[i]].push_back(i);
        }

        std::vector<long long> ans(n);
        for (auto& [_, a]: groups) {
            int m = a.size();
            long long s = 0;
            for (int x: a) {
                s += x - a[0];
            }
            ans[a[0]] = s;
            for (int i = 1; i < m; ++i) {
                s += (long long) (i * 2 - m) * (a[i] - a[i - 1]);
                ans[a[i]] = s;
            }
        }

        return ans;
    }

    void SumOfDistances::test() {
        std::vector<std::vector<int>> nums {
            {1,3,1,1,2},
            {0,5,3}
        };
        std::vector<std::vector<long long>> expect {
            {5,0,3,4,0},
            {0,0,0}
        };
        for (int i = 0; i < expect.size(); i++) {
            std::vector<long long> actual = distance(nums[i]);
            bool isEqual = true;
            if (actual.size() != expect[i].size()) {
                isEqual = false;
            }
            for (int j = 0; isEqual && j < actual.size(); j++) {
                if (actual[j] != expect[i][j]) {
                    isEqual = false;
                }
            }
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("2615", leetcode::SumOfDistances);