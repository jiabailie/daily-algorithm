//
// Created by Ruiguo Yang on 2026/7/4.
//

#include "MinimumScoreOfAPathBetweenTwoCities.h"

#include <climits>
#include <iostream>
#include <ostream>

namespace leetcode {
    int MinimumScoreOfAPathBetweenTwoCities::minScore(int n, std::vector<std::vector<int> > &roads) {
        std::vector<std::vector<std::pair<int, int>>> g(n + 1);
        for (auto& e: roads) {
            int x = e[0];
            int y = e[1];
            int dis = e[2];
            g[x].emplace_back(y, dis);
            g[y].emplace_back(x, dis);
        }

        int ans = INT_MAX;
        std::vector<int8_t> vis(n + 1);
        auto dfs = [&](auto&& dfs, int x) -> void {
            vis[x] = true;
            for (auto& [y, dis]: g[x]) {
                ans = std::min(ans, dis);
                if (!vis[y]) {
                    dfs(dfs, y);
                }
            }
        };

        dfs(dfs, 1);
        return ans;
    }

    void MinimumScoreOfAPathBetweenTwoCities::test() {
        std::vector<int> n {4,4};
        std::vector<std::vector<std::vector<int>>> roads {
            {{1,2,9},{2,3,6},{2,4,5},{1,4,7}},
            {{1,2,2},{1,3,4},{3,4,7}}
        };
        std::vector<int> expect {5,2};
        for (int i = 0; i < expect.size(); i++) {
            int actual = minScore(n[i], roads[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("2492", leetcode::MinimumScoreOfAPathBetweenTwoCities);