//
// Created by ruiguo on 2026/7/17.
//

#include "SortedGCDPairQueries.h"

#include <iostream>
#include <ostream>
#include <numeric>

namespace leetcode {
    std::vector<int> SortedGCDPairQueries::gcdValues(std::vector<int> &nums, std::vector<long long> &queries) {
        int mx = *std::max_element(nums.begin(), nums.end());
        std::vector<int> cntX(mx + 1);
        for (int x: nums) {
            cntX[x]++;
        }

        std::vector<long long> cntGcd(mx + 1);
        for (int i = mx; i > 0; --i) {
            int c = 0;
            for (int j = i; j <= mx; j += i) {
                c += cntX[j];
                cntGcd[i] -= cntGcd[j];
            }
            cntGcd[i] += (long long)c * (c - 1) / 2;
        }

        std::partial_sum(cntGcd.begin(), cntGcd.end(), cntGcd.begin());
        std::vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = std::upper_bound(cntGcd.begin(), cntGcd.end(), queries[i]) - cntGcd.begin();
        }
        return ans;
    }

    void SortedGCDPairQueries::test() {
        std::vector<std::vector<int>> nums {
            {2,3,4},
            {4,4,2,1},
            {2,2}
        };
        std::vector<std::vector<long long>> queries {
            {0,2,2},
            {5,3,1,0},
            {0,0}
        };
        std::vector<std::vector<int>> expect {
            {1,2,2},
            {4,2,1,1},
            {2,2}
        };
        for (int i = 0; i < expect.size(); i++) {
            std::vector<int> actual = gcdValues(nums[i], queries[i]);
            bool isEqual = std::equal(actual.begin(), actual.end(), expect[i].begin(), expect[i].end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3312", leetcode::SortedGCDPairQueries);