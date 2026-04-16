//
// Created by 杨睿国 on 2026/1/27.
//

#ifndef ALGORITHM_MINIMUMCOSTPATHWITHEDGEREVERSALS_H
#define ALGORITHM_MINIMUMCOSTPATHWITHEDGEREVERSALS_H

#include <vector>
#include "../Base.h"

namespace  leetcode {
    class MinimumCostPathWithEdgeReversals: public Base {
    public:
        int minCost(int n, std::vector<std::vector<int>>& edges);
        void test() override;
    };
}


#endif //ALGORITHM_MINIMUMCOSTPATHWITHEDGEREVERSALS_H
