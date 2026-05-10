//
// Created by Ruiguo Yang on 2026/5/10.
//

#include "MinimumCostToBuyApplesII.h"

#include <climits>
#include <iostream>
#include <ostream>

namespace leetcode {
    std::vector<long long> MinimumCostToBuyApplesII::shortestPathDijkstra(std::vector<std::vector<std::pair<int, long long> > > &g, int start, int price) {
        std::vector<long long> dis(g.size(), LLONG_MAX / 3);
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> pq;
        dis[start] = 0;
        pq.emplace(0, start);

        while (!pq.empty()) {
            auto [disX, x] = pq.top();
            pq.pop();
            if (disX > dis[x]) {
                continue;
            }
            for (auto& [y, wt]: g[x]) {
                auto newDisY = disX + wt;
                if (newDisY < price && newDisY < dis[y]) {
                    dis[y] = newDisY;
                    pq.emplace(newDisY, y);
                }
            }
        }
        return dis;
    }

    std::vector<int> MinimumCostToBuyApplesII::minCost(int n, std::vector<int> &prices, std::vector<std::vector<int> > &roads) {
        std::vector<std::vector<std::pair<int, long long>>> g1(n);
        std::vector<std::vector<std::pair<int, long long>>> g2(n);
        for (auto& e: roads) {
            int x = e[0];
            int y = e[1];
            int cost = e[2];
            int tax = e[3];
            g1[x].emplace_back(y, cost);
            g1[y].emplace_back(x, cost);
            g2[x].emplace_back(y, 1LL * cost * tax);
            g2[y].emplace_back(x, 1LL * cost * tax);
        }

        std::vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int price = prices[i];
            std::vector<long long> dis1 = shortestPathDijkstra(g1, i, price);
            std::vector<long long> dis2 = shortestPathDijkstra(g2, i, price);
            long long res = LLONG_MAX;
            for (int j = 0; j < n; ++j) {
                res = std::min(res, prices[j] + dis1[j] + dis2[j]);
            }
            ans[i] = res;
        }
        return ans;
    }

    void MinimumCostToBuyApplesII::test() {
        std::vector<int> ns {2,3,3,9};
        std::vector<std::vector<int>> prices {
            {8,3},
            {9,4,6},
            {10,11,1},
            {81,59,57,74,69,45,81,10,77}
        };
        std::vector<std::vector<std::vector<int>>> roads {
            {{0,1,1,2}},
            {{0,1,1,3},{1,2,4,2}},
            {{0,2,1,3},{1,2,3,4},{0,1,5,2}},
            {{2,4,65,7},{8,7,31,9},{6,3,12,1},{7,1,64,9},{2,1,24,8},{5,1,76,8},{7,5,12,7},{8,4,51,4},{7,3,73,6},{2,7,40,6},{3,5,11,4},{3,4,17,4},{1,3,17,1},{4,5,1,1},{1,0,4,7},{3,8,79,6},{6,4,1,2},{2,0,6,7},{0,7,61,6},{4,7,64,5},{3,0,61,4},{0,4,62,3},{1,8,35,4},{8,5,70,5},{2,5,53,8},{5,0,31,9},{6,8,27,9},{2,8,75,5},{6,5,78,6},{1,6,29,2}}
        };
        std::vector<std::vector<int>> expect {
            {6,3},
            {8,4,6},
            {5,11,1},
            {81,59,57,71,47,45,50,10,77}
        };
        for (int i = 0; i < expect.size(); i++) {
            std::vector<int> actual = minCost(ns[i], prices[i], roads[i]);
            bool isEqual = std::equal(actual.begin(), actual.end(), expect[i].begin(), expect[i].end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }

    }
}

REGISTER_LEETCODE_SOLUTION("3928", leetcode::MinimumCostToBuyApplesII);