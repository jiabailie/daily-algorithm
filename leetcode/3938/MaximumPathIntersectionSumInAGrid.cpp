//
// Created by Ruiguo Yang on 2026/5/30.
//

#include "MaximumPathIntersectionSumInAGrid.h"

#include <climits>
#include <iostream>
#include <ostream>

namespace leetcode {
    int MaximumPathIntersectionSumInAGrid::maxSubArray(std::vector<int> &nums) {
        int ans = INT_MIN;
        int f = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];
            ans = std::max(ans, f + x);
            f = std::max(f, 0) + x;
        }
        return ans;
    }

    int MaximumPathIntersectionSumInAGrid::maxScore(std::vector<std::vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = INT_MIN;

        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                ans = std::max(ans, grid[i][j]);
            }
        }

        for (auto& row: grid) {
            ans = std::max(ans, maxSubArray(row));
        }

        std::vector<int> col(m);
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                col[i] = grid[i][j];
            }
            ans = std::max(ans, maxSubArray(col));
        }

        return ans;
    }

    void MaximumPathIntersectionSumInAGrid::test() {
        std::vector<std::vector<std::vector<int>>> grid {
            {{1,2,0,-3},{1,-2,1,0},{-4,2,-1,3},{3,-3,3,-2},{-1,-5,0,1}},
            {{4,-2,-3},{-1,-3,-1},{-4,2,-1}}
        };
        std::vector<int> expect {4,3};
        for (int i = 0; i < expect.size(); i++) {
            int actual = maxScore(grid[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3938", leetcode::MaximumPathIntersectionSumInAGrid);