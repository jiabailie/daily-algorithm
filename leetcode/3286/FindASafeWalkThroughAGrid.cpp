//
// Created by ruiguo on 2026/7/2.
//

#include "FindASafeWalkThroughAGrid.h"

#include <climits>
#include <iostream>
#include <ostream>
#include <deque>

namespace leetcode {
    bool FindASafeWalkThroughAGrid::findSafeWalk(std::vector<std::vector<int> > &grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> dis(m, std::vector<int>(n, INT_MAX));
        dis[0][0] = grid[0][0];
        std::deque<std::pair<int, int>> q;
        q.emplace_front(0, 0);;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop_front();
            for (auto& [dx, dy]: DIRS) {
                int x = i + dx;
                int y = j + dy;
                if (0 <= x && x < m && 0 <= y && y < n) {
                    int cost = grid[x][y];
                    if (dis[i][j] + cost < dis[x][y]) {
                        dis[x][y] = dis[i][j] + cost;
                        cost == 0 ? q.emplace_front(x, y) : q.emplace_back(x, y);
                    }
                }
            }
        }
        return dis[m - 1][n - 1] < health;
    }

    void FindASafeWalkThroughAGrid::test() {
        std::vector<std::vector<std::vector<int>>> grid {
                {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}},
                {{0,1,1,0,0,0},{1,0,1,0,0,0},{0,1,1,1,0,1},{0,0,1,0,1,0}},
                {{1,1,1},{1,0,1},{1,1,1}}
        };
        std::vector<int> health {1,3,5};
        std::vector<bool> expect {true,false,true};
        for (int i = 0; i < expect.size(); i++) {
            bool actual = findSafeWalk(grid[i], health[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3286", leetcode::FindASafeWalkThroughAGrid);