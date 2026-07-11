//
// Created by Ruiguo on 11/7/2026.
//

#include "CountTheNumberOfCompleteComponents.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int CountTheNumberOfCompleteComponents::countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> g(n);
        for (auto& edge: edges) {
            int x = edge[0];
            int y = edge[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        std::vector<int8_t> visit(n, false);
        int v = 0;
        int e = 0;

        auto dfs = [&](auto&& dfs, int x) -> void {
            v++;
            e += g[x].size();
            visit[x] = true;
            for (int y: g[x]) {
                if (!visit[y]) {
                    dfs(dfs, y);
                }
            }
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                v = 0;
                e = 0;
                dfs(dfs, i);
                ans += e == v * (v - 1);
            }
        }
        return ans;
    }

    void CountTheNumberOfCompleteComponents::test() {
        std::vector<int> n {6,6};
        std::vector<std::vector<std::vector<int>>> edges {
            {{0,1},{0,2},{1,2},{3,4}},
            {{0,1},{0,2},{1,2},{3,4},{3,5}}
        };
        std::vector<int> expect {3,1};
        for (int i = 0; i < expect.size(); i++) {
            int actual = countCompleteComponents(n[i], edges[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("2685", leetcode::CountTheNumberOfCompleteComponents);
