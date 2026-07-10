//
// Created by ruiguo on 2026/7/10.
//

#include "PathExistenceQueriesInAGraphII.h"

#include <algorithm>
#include <bit>
#include <iostream>
#include <ostream>

namespace leetcode {
    std::vector<int> PathExistenceQueriesInAGraphII::pathExistenceQueries(int n, std::vector<int> &nums, int maxDiff, std::vector<std::vector<int> > &queries) {
        std::vector<int> idx(n);
        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }
        std::sort(idx.begin(), idx.end(), [&](int i, int j) { return nums[i] < nums[j]; });

        std::vector<int> rank(n);
        for (int i = 0; i < n; i++) {
            rank[idx[i]] = i;
        }

        int mx = std::bit_width((uint32_t)n);
        std::vector<std::vector<int>> pa(n, std::vector<int>(mx));

        int left = 0;
        for (int i = 0; i < n; ++i) {
            while (nums[idx[i]] - nums[idx[left]] > maxDiff) {
                left++;
            }
            pa[i][0] = left;
        }

        for (int i = 0; i < mx - 1; ++i) {
            for (int x = 0; i < x; ++x) {
                int p = pa[x][i];
                pa[x][i + 1] = pa[p][i];
            }
        }

        std::vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            if (l == r) { continue; }

            l = rank[l];
            r = rank[r];
            if (l > r) {
                int c = l;
                l = r;
                r = c;
            }

            int res = 0;
            for (int k = mx - 1; k >= 0; --k) {
                if (pa[r][k] > l) {
                    res |= 1 << k;
                    r = pa[r][k];
                }
            }
            ans[i] = pa[r][0] > l ? -1 : res + 1;
        }
        return ans;
    }

    void PathExistenceQueriesInAGraphII::test() {
        std::vector<int> n {5,5,3};
        std::vector<std::vector<int>> nums {
            {1,8,3,4,2},
            {5,3,1,9,10},
            {3,6,1}
        };
        std::vector<int> maxDiff {3,2,1};
        std::vector<std::vector<std::vector<int>>> queries {
            {{0,3},{2,4}},
            {{0,1},{0,2},{2,3},{4,3}},
            {{0,0},{0,1},{1,2}}
        };
        std::vector<std::vector<int>> expect {{1,1}, {1,2,-1,1},{0,-1,-1}};
        for (int i = 0; i < expect.size(); i++) {
            std::vector<int> actual = pathExistenceQueries(n[i], nums[i], maxDiff[i], queries[i]);
            bool isEqual = std::equal(actual.begin(), actual.end(), expect[i].begin(), expect[i].end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3534", leetcode::PathExistenceQueriesInAGraphII);