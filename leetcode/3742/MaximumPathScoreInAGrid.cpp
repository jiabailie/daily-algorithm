//
// Created by Ruiguo Yang on 2026/4/30.
//

#include "MaximumPathScoreInAGrid.h"

#include <iostream>

namespace leetcode {
    int MaximumPathScoreInAGrid::maxPathScore(std::vector<std::vector<int> > &grid, int k) {
        int h = grid.size();
        int w = grid[0].size();
        std::vector memo(h, std::vector(w, std::vector(k + 1, -1)));

        auto dfs = [&](auto&& dfs, int i, int j, int k) -> int {
            if (i < 0 || j < 0 || k < 0) {
                return INT_MIN;
            }
            if (i == 0 && j == 0) {
                return 0;
            }

            int& res = memo[i][j][k];
            if (res != -1) {
                return res;
            }

            int x = grid[i][j];
            if (x > 0) {
                k--;
            }
            res = std::max(dfs(dfs, i - 1, j, k), dfs(dfs, i, j - 1, k)) + x;
            return res;
        };

        int ans = dfs(dfs, h - 1, w - 1, k);
        return (ans < 0 ? -1 : ans);
    }

    void MaximumPathScoreInAGrid::test() {
        std::vector<std::vector<std::vector<int>>> grids {
            {{0,1},{2,0}},
            {{0,1},{1,2}}
        };
        std::vector<int> ks {1,1};
        std::vector<int> expect {2,-1};
        for (int i = 0; i < expect.size(); i++) {
            int actual = maxPathScore(grids[i], ks[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3742", leetcode::MaximumPathScoreInAGrid);
