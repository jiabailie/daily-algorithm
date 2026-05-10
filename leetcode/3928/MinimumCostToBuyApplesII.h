//
// Created by Ruiguo Yang on 2026/5/10.
//

#ifndef ALGORITHM_MINIMUMCOSTTOBUYAPPLESII_H
#define ALGORITHM_MINIMUMCOSTTOBUYAPPLESII_H

#include "../Base.h"

namespace leetcode {
    class MinimumCostToBuyApplesII: public Base {
    public:
        std::vector<long long> shortestPathDijkstra(std::vector<std::vector<std::pair<int, long long>>>& g, int start, int price);
        std::vector<int> minCost(int n, std::vector<int>& prices, std::vector<std::vector<int>>& roads);
        void test() override;
    };
}

#endif //ALGORITHM_MINIMUMCOSTTOBUYAPPLESII_H