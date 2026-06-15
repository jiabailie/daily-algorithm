//
// Created by Ruiguo Yang on 2026/6/15.
//

#include "FindKPairsWithSmallestSums.h"

#include <iostream>
#include <queue>

namespace leetcode {
    std::vector<std::vector<int> > FindKPairsWithSmallestSums::kSmallestPairs(std::vector<int> &nums1, std::vector<int> &nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        std::priority_queue<std::tuple<int, int, int>> pq;
        for (int i = 0; i < std::min(k, n); ++i) {
            pq.emplace(-nums1[i]-nums2[0], i, 0);
        }

        std::vector<std::vector<int>> res;
        while (k--) {
            auto [_, i, j] = pq.top();
            pq.pop();
            res.push_back({nums1[i], nums2[j]});
            if (j + 1 < m) {
                pq.emplace(-nums1[i]-nums2[j+1], i, j+1);
            }
        }
        return res;
    }

    void FindKPairsWithSmallestSums::test() {
        std::vector<std::vector<int>> nums1 {
            {1,7,11},
            {1,1,2}
        };
        std::vector<std::vector<int>> nums2 {
            {2,4,6},
            {1,2,3}
        };
        std::vector<int> k {3,2};
        std::vector<std::vector<std::vector<int>>> expect {
            {{1,2},{1,4},{1,6}},
            {{1,1,},{1,1}}
        };
        for (int i = 0; i < expect.size(); ++i) {
            std::vector<std::vector<int>> actual = kSmallestPairs(nums1[i], nums2[i], k[i]);
            bool isEqual = true;
            if (actual.size() != expect[i].size()) {
                isEqual = false;
            }

            for (int j = 0; j < actual.size() && isEqual; ++j) {
                isEqual = std::equal(actual.begin(), actual.end(), expect[i].begin(), expect[i].end());
            }

            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("373", leetcode::FindKPairsWithSmallestSums);
