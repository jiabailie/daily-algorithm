//
// Created by Ruiguo Yang on 2026/4/28.
//

#ifndef ALGORITHM_MINIMUMOPERATIONSTOMAKEUNIVALUEGRID_H
#define ALGORITHM_MINIMUMOPERATIONSTOMAKEUNIVALUEGRID_H

#include "../Base.h"

namespace leetcode {
    class MinimumOperationsToMakeUniValueGrid: public Base {
    public:
        int minOperations(std::vector<std::vector<int>>& grid, int x);
        void test() override;
    };
}

#endif //ALGORITHM_MINIMUMOPERATIONSTOMAKEUNIVALUEGRID_H