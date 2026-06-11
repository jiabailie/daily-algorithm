//
// Created by Ruiguo Yang on 2026/6/11.
//

#include "NumberOfWaysToAssignEdgeWeightsI.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    ll NumberOfWaysToAssignEdgeWeightsI::pow(ll x, int n) {
        ll res = 1;
        for (; n > 0; n /= 2) {
            if (n % 2 == 1) {
                res = (res * x) % MOD;
            }
            x = (x * x) % MOD;
        }
        return res;
    }

    int NumberOfWaysToAssignEdgeWeightsI::assignEdgeWeights(std::vector<std::vector<int> > &edges) {
        int n = edges.size() + 1;
        std::vector<std::vector<int>> g(n + 1, std::vector<int>());
        for (auto& e: edges) {
            int x = e[0];
            int y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        auto dfs = [&](auto&& dfs, int x, int fa) -> int {
            int d = 0;
            for (int y: g[x]) {
                if (y == fa) { continue; }
                d = std::max(d, dfs(dfs, y, x) + 1);
            }
            return d;
        };

        int h = dfs(dfs, 1, 0);
        return pow(2, h - 1);
    }

    void NumberOfWaysToAssignEdgeWeightsI::test() {
        std::vector<std::vector<std::vector<int>>> edges {
            {{1,2}},
            {{1,2},{1,3},{3,4},{3,5}}
        };
        std::vector<int> expect {1,2};
        for (int i = 0; i < expect.size(); i++) {
            int actual = assignEdgeWeights(edges[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3558", leetcode::NumberOfWaysToAssignEdgeWeightsI);