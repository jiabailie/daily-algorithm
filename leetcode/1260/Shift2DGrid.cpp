//
// Created by ruiguo on 2026/7/20.
//

#include "Shift2DGrid.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    std::vector<std::vector<int> > Shift2DGrid::shiftGrid(std::vector<std::vector<int> > &grid, int k) {
        int h = grid.size();
        int w = grid[0].size();

        int cursor = 0;
        k = k % (h * w);
        std::vector<std::vector<int>> ans(h, std::vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int nextCursor = (cursor + k) % (h * w);

                int nextH = nextCursor / w;
                int nextW = nextCursor % w;
                ans[nextH][nextW] = grid[i][j];

                cursor = cursor + 1;
            }
        }
        return ans;
    }

    void Shift2DGrid::test() {
        std::vector<std::vector<std::vector<int>>> grid {
            {{1,2,3},{4,5,6},{7,8,9}},
            {{3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13}},
            {{1,2,3},{4,5,6},{7,8,9}}
        };
        std::vector<int> k {1,4,9};
        std::vector<std::vector<std::vector<int>>> expect {
            {{9,1,2},{3,4,5},{6,7,8}},
            {{12,0,21,13},{3,8,1,9},{19,7,2,5},{4,6,11,10}},
            {{1,2,3},{4,5,6},{7,8,9}}
        };
        for (int i = 0; i < expect.size(); i++) {
            std::vector<std::vector<int>> actual = shiftGrid(grid[i], k[i]);
            bool isEqual = std::equal(expect[i].begin(), expect[i].end(), actual.begin(), actual.end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1260", leetcode::Shift2DGrid);