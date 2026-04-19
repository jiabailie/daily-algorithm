//
// Created by Ruiguo Yang on 2026/4/19.
//

#include "MultiSourceFloodFill.h"

#include <algorithm>
#include <iostream>
#include <ostream>
#include <queue>
#include <utility>
#include <unordered_set>
#include <vector>

typedef long long ll;

namespace leetcode {
    std::vector<std::vector<int>> MultiSourceFloodFill::colorGrid1(int n, int m, std::vector<std::vector<int> > &sources) {
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,1,-1};

        std::vector g(2, std::vector(n, std::vector(m, 0)));
        std::queue<std::pair<int, int>> q[2];
        for (const std::vector<int>& s: sources) {
            g[0][s[0]][s[1]] = s[2];
            g[1][s[0]][s[1]] = s[2];
            q[0].push({s[0], s[1]});
        }

        int curr = 0;
        int next = 1;
        while (!q[curr].empty()) {
            std::unordered_set<ll> pending;
            while (!q[curr].empty()) {
                auto f = q[curr].front();
                q[curr].pop();

                int cx = f.first;
                int cy = f.second;
                for (int i = 0; i < 4; ++i) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || g[curr][nx][ny] != 0) {
                        continue;
                    }

                    ll t = nx * 100000LL + ny;
                    pending.insert(t);
                }
            }

            for (ll p: pending) {
                int x = p / 100000;
                int y = p % 100000;

                for (int i = 0; i < 4; ++i) {
                    int tx = x + dx[i];
                    int ty = y + dy[i];
                    if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
                        continue;
                    }
                    g[next][x][y] = std::max(g[next][x][y], g[curr][tx][ty]);
                }
                q[next].push({x, y});
            }

            for (ll p: pending) {
                int x = p / 100000;
                int y = p % 100000;

                g[curr][x][y] = g[next][x][y];
            }

            curr = next;
            next = 1 - curr;
        }
        return g[curr];
    }

    std::vector<std::vector<int>> MultiSourceFloodFill::colorGrid2(int n, int m, std::vector<std::vector<int> > &sources) {
        std::sort(sources.begin(), sources.end(), [](const auto& a, const auto& b) { return a[2] > b[2]; });
        std::vector<std::vector<int>> ans(n, std::vector<int>(m));
        std::queue<std::pair<int, int>> q;
        for (auto& p: sources) {
            ans[p[0]][p[1]] = p[2];
            q.emplace(p[0], p[1]);
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto [dx, dy]: DIR) {
                int x = i + dx;
                int y = j + dy;
                if (0 <= x && x < n && 0 <= y && y < m && ans[x][y] == 0) {
                    ans[x][y] = ans[i][j];
                    q.emplace(x, y);
                }
            }
        }

        return ans;
    }

    void MultiSourceFloodFill::test() {
        std::vector<int> n {3, 3, 2};
        std::vector<int> m {3, 3, 2};
        std::vector<std::vector<std::vector<int>>> sources {
            {{0,0,1},{2,2,2}},
            {{0,1,3},{1,1,5}},
            {{1,1,5}}
        };
        std::vector<std::vector<std::vector<int>>> expects {
            {{1,1,2},{1,2,2},{2,2,2}},
            {{3,3,3},{5,5,5},{5,5,5}},
            {{5,5},{5,5}}
        };
        for (int i = 0; i < sources.size(); ++i) {
            std::vector actual = colorGrid1(n[i], m[i], sources[i]);
            std::vector expect = expects[i];

            bool isMatch = true;
            for (int x = 0; isMatch && x < actual.size(); ++x) {
                for (int y = 0; isMatch && y < actual[x].size(); ++y) {
                    isMatch = actual[x][y] == expect[x][y];
                }
            }
            std::cout << (isMatch ? "PASS" : "FAIL") << std::endl;
        }
        for (int i = 0; i < sources.size(); ++i) {
            std::vector actual = colorGrid2(n[i], m[i], sources[i]);
            std::vector expect = expects[i];

            bool isMatch = true;
            for (int x = 0; isMatch && x < actual.size(); ++x) {
                for (int y = 0; isMatch && y < actual[x].size(); ++y) {
                    isMatch = actual[x][y] == expect[x][y];
                }
            }
            std::cout << (isMatch ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("101045", leetcode::MultiSourceFloodFill);
