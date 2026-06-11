//
// Created by Ruiguo Yang on 2026/6/11.
//

#ifndef ALGORITHM_NUMBEROFWAYSTOASSIGNEDGEWEIGHTSI_H
#define ALGORITHM_NUMBEROFWAYSTOASSIGNEDGEWEIGHTSI_H

#include "../Base.h"

typedef long long ll;

namespace leetcode {
    class NumberOfWaysToAssignEdgeWeightsI: public Base {
    public:
        const int MOD = 1'000'000'007;
        ll pow(ll x, int n);
        int assignEdgeWeights(std::vector<std::vector<int>>& edges);
        void test() override;
    };
}

#endif //ALGORITHM_NUMBEROFWAYSTOASSIGNEDGEWEIGHTSI_H