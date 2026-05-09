//
// Created by Ruiguo Yang on 2026/5/9.
//

#include "CyclicallyRotatingAGrid.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    std::vector<std::vector<int> > CyclicallyRotatingAGrid::rotateGrid(std::vector<std::vector<int> > &grid, int k) {
        int h = grid.size();
        int w = grid[0].size();
        int c = std::min(h / 2, w / 2);
        std::vector<std::vector<int>> ans(h, std::vector<int>(w));
        for (int i = 0; i < c; ++i) {
            std::vector<std::pair<int, int>> pos;

            // (i,i) -> (h-i-1,i) -> (h-i-1,w-i-1)->(i,w-i-1)->(i,i)
            for (int j = i; j < h - i - 1; ++j) {
                pos.push_back({j, i});
            }
            for (int j = i; j < w - i - 1; ++j) {
                pos.push_back({h - i - 1, j});
            }
            for (int j = h - i - 1; j > i; --j) {
                pos.push_back({j, w - i - 1});
            }
            for (int j = w - i - 1; j > i; --j) {
                pos.push_back({i, j});
            }

            int move = k % pos.size();
            for (int j = 0; j < pos.size(); ++j) {
                int source = (j + pos.size() - move) % pos.size();
                ans[pos[j].first][pos[j].second] = grid[pos[source].first][pos[source].second];
            }
        }
        return ans;
    }

    void CyclicallyRotatingAGrid::test() {
        std::vector<std::vector<std::vector<int>>> grids {
            {{40,10},{30,20}},
            {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}
        };
        std::vector<int> ks {1,2};
        std::vector<std::vector<std::vector<int>>> expect {
                {{10,20},{40,30}},
            {{3,4,8,12},{2,11,10,16},{1,7,6,15},{5,9,13,14}}
        };
        for (int i = 0; i < expect.size(); i++) {
            std::vector<std::vector<int>> actual = rotateGrid(grids[i], ks[i]);
            bool isEqual = true;
            if (actual.size() != grids[i].size() || actual[0].size() != grids[i][0].size()) {
                isEqual = false;
            }
            for (int x = 0; x < actual.size() && isEqual; ++x) {
                for (int y = 0; y < actual[0].size() && isEqual; ++y) {
                    if (actual[x][y] != expect[i][x][y]) {
                        isEqual = false;
                    }
                }
            }
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1914", leetcode::CyclicallyRotatingAGrid);