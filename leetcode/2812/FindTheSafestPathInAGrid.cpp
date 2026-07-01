//
// Created by Ruiguo Yang on 2026/7/1.
//

#include "FindTheSafestPathInAGrid.h"

#include <iostream>
#include <ostream>
#include <numeric>

namespace leetcode {
    int FindTheSafestPathInAGrid::maximumSafenessFactor(std::vector<std::vector<int> > &grid) {
        int n = grid.size();
        std::vector<std::vector<int>> dis(n, std::vector<int>(n, -1));
        std::vector<std::pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    dis[i][j] = 0;
                    q.emplace_back(i, j);
                }
            }
        }

        std::vector<std::vector<std::pair<int, int>>> groups = {q};
        while (!q.empty()) {
            auto tmp = move(q);
            for (auto& [i, j]: tmp) {
                for (auto& [dx, dy]: dirs) {
                    int x = i + dx;
                    int y = j + dy;
                    if (0 <= x && x < n && 0 <= y && y < n && dis[x][y] < 0) {
                        dis[x][y] = groups.size();
                        q.emplace_back(x, y);
                    }
                }
            }
            groups.push_back(q);
        }

        std::vector<int> fa(n * n);
        std::iota(fa.begin(), fa.end(), 0);
        auto find = [&](auto&& find, int x) -> int {
            return fa[x] == x ? x : fa[x] = find(find, fa[x]);
        };

        for (int ans = (int)groups.size() - 2; ans > 0; --ans) {
            for (auto& [i, j]: groups[ans]) {
                for (auto& [dx, dy]: dirs) {
                    int x = i + dx;
                    int y = j + dy;
                    if (0 <= x && x < n && 0 <= y && y < n && dis[x][y] >= ans) {
                        fa[find(find, x * n + y)] = find(find, i * n + j);
                    }
                }
            }
            if (find(find, 0) == find(find, n * n - 1)) {
                return ans;
            }
        }
        return 0;
    }

    void FindTheSafestPathInAGrid::test() {
        std::vector<std::vector<std::vector<int>>> grid {
            {{1,0,0},{0,0,0},{0,0,1}},
            {{0,0,1},{0,0,0},{0,0,0}},
            {{0,0,0,1},{0,0,0,0},{0,0,0,0},{1,0,0,0}}
        };
        std::vector<int> expect {0,2,2};
        for (int i = 0; i < expect.size(); i++) {
            int actual = maximumSafenessFactor(grid[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("2812", leetcode::FindTheSafestPathInAGrid);