//
// Created by Ruiguo Yang on 2026/4/26.
//

#include "DetectCyclesIn2DGrid.h"

#include <iostream>
#include <ostream>
#include <vector>

namespace leetcode {
    bool DetectCyclesIn2DGrid::containsCycle(std::vector<std::vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector visited(m, std::vector<int8_t>(n));

        auto dfs = [&](auto&& dfs, int x, int y, int px, int py) -> bool {
            visited[x][y] = true;
            for (const auto& dir: DIRS) {
                int i = x + dir[0];
                int j = y + dir[1];
                if ((i != px || j != py) && // not its previous point
                    0 <= i && i < m && 0 <= j && j < n && // point in the grid
                    grid[i][j] == grid[x][y] && // contains the same character
                    (visited[i][j] || dfs(dfs, i, j, x, y))) { // has visited current point
                    return true;
                }
            }
            return false;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && dfs(dfs, i, j, -1, -1)) {
                    return true;
                }
            }
        }

        return false;
    }

    void DetectCyclesIn2DGrid::test() {
        std::vector<std::vector<std::vector<char>>> grids {
            {{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}},
            {{'c','c','c','a'},{'c','d','c','c'},{'c','c','e','c'},{'f','c','c','c'}},
            {{'a','b','b'},{'b','z','b'},{'b','b','a'}}
        };
        std::vector<bool> expect { true, true, false};
        for (int i = 0; i < expect.size(); i++) {
            bool actual = containsCycle(grids[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1559", leetcode::DetectCyclesIn2DGrid);
