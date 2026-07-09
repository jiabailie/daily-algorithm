//
// Created by ruiguo on 2026/7/9.
//

#include "PathExistenceQueriesInAGraphI.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    std::vector<bool> PathExistenceQueriesInAGraphI::pathExistenceQueries(int n, std::vector<int> &nums, int maxDiff, std::vector<std::vector<int> > &queries) {
        int cnt = 1;

        std::vector<int> p(n, 0);
        p[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                p[i] = cnt;
                continue;
            }
            cnt = cnt + 1;
            p[i] = cnt;
        }

        int m = queries.size();
        std::vector<bool> ans(m, false);
        for (int i = 0; i < m; ++i) {
            int x = queries[i][0];
            int y = queries[i][1];
            ans[i] = p[x] == p[y];
        }
        return ans;
    }

    void PathExistenceQueriesInAGraphI::test() {
        std::vector<int> n {2,4};
        std::vector<std::vector<int>> nums {{1,3},{2,5,6,8}};
        std::vector<int> maxDiff {1,2};
        std::vector<std::vector<std::vector<int>>> queries {
            {{0,0},{0,1}},
            {{0,1},{0,2},{1,3},{2,3}},
        };
        std::vector<std::vector<int>> expect {
            {true, false},
            {false, false,true,true}
        };
        for (int i = 0; i < expect.size(); ++i) {
            std::vector<bool> actual = pathExistenceQueries(n[i], nums[i], maxDiff[i], queries[i]);
            bool isEqual = std::equal(expect[i].begin(), expect[i].end(), actual.begin(), actual.end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3532", leetcode::PathExistenceQueriesInAGraphI);