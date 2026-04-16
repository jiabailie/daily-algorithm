//
// Created by 杨睿国 on 2026/1/27.
//

#include "MinimumCostPathWithEdgeReversals.h"

#include <iostream>
#include <unordered_map>
#include <vector>

typedef long long ll;

namespace leetcode {
    int MinimumCostPathWithEdgeReversals::minCost(int n, std::vector<std::vector<int> > &edges) {
        std::unordered_map<int, std::vector<int>> from;
        std::unordered_map<int, std::vector<int>> to;
        std::unordered_map<ll, int> cost;
        for (std::vector<int>& e: edges) {
            int x = e[0];
            int y = e[1];
            int w = e[2];

            from[x].push_back(y);
            to[y].push_back(x);
            cost[x * 100000 * 1LL + y] = w;
        }

        return 0;
    }

    void MinimumCostPathWithEdgeReversals::test() {
        int n = 4;
        std::vector<std::vector<int>> edges = {{0,1,3},{3,1,1},{2,3,4},{0,2,2}};
        int actual = minCost(n, edges);
        int expect = 0;

        std::cout << (actual == expect ? "PASS" : "FAIL") << std::endl;
    }
}

REGISTER_LEETCODE_SOLUTION("3650", leetcode::MinimumCostPathWithEdgeReversals);
