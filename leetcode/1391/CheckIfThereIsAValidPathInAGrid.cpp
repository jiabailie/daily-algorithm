//
// Created by Ruiguo Yang on 2026/4/27.
//

#include "CheckIfThereIsAValidPathInAGrid.h"
#include <cstring>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace leetcode {
    bool CheckIfThereIsAValidPathInAGrid::hasValidPath(std::vector<std::vector<int> > &grid) {
        std::unordered_map<int, std::unordered_set<int>> left;
        std::unordered_map<int, std::unordered_set<int>> right;
        std::unordered_map<int, std::unordered_set<int>> up;
        std::unordered_map<int, std::unordered_set<int>> down;

        left[1] = {1,4,6};
        right[1] = {1,3,5};

        up[2] = {2,3,4};
        down[2] = {2,5,6};

        left[3] = {1,4,6};
        down[3] = {2,5,6};

        right[4] = {1,3,5};
        down[4] = {2,5,6};

        left[5] = {1,4,6};
        up[5] = {2,3,4};

        right[6] = {1,3,5};
        up[6] = {2,3,4};

        int h = grid.size();
        int w = grid[0].size();

        std::string d[4] = {"left", "right", "up", "down" };
        int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
        std::unordered_map<int, std::unordered_set<int>> path[4] = {left, right, up, down};

        std::queue<int> que;
        std::vector<std::vector<bool>> visited(h, std::vector<bool>(w, false));

        que.push(0);
        visited[0][0] = true;
        while (!que.empty()) {
            int front = que.front();
            que.pop();

            int x = front / 1000;
            int y = front % 1000;

            int idx = grid[x][y];
            std::cout << idx << std::endl;
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w || visited[nx][ny]) {
                    continue;
                }

                std::cout << "|-" << d[i] << " " << grid[nx][ny] << std::endl;

                if (path[i][idx].count(grid[nx][ny]) > 0) {
                    que.push(nx * 1000 + ny);
                    visited[nx][ny] = true;
                }
            }

            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) {
                    std::cout << (visited[i][j] ? 1 : 0) << " ";
                }
                std::cout << std::endl;
            }
            std::cout << "-----------" << std::endl;
        }

        return visited[h - 1][w - 1];
    }

    void CheckIfThereIsAValidPathInAGrid::test() {
        std::vector<std::vector<std::vector<int>>> grid {
            {{2,4,3},{6,5,2}},
            {{1,2,1},{1,2,1}},
            {{1,1,2}},
            {{1,1,1,1,1,1,3}}
        };
        std::vector<bool> expect { true, false, false, true };
        for (int i = 0; i < expect.size(); i++) {
            std::cout << "Case #" << i << ": " << std::endl;
            bool actual = hasValidPath(grid[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1391", leetcode::CheckIfThereIsAValidPathInAGrid);