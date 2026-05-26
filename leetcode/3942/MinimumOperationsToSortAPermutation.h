//
// Created by Ruiguo Yang on 2026/5/26.
//

#ifndef ALGORITHM_MINIMUMOPERATIONSTOSORTAPERMUTATION_H
#define ALGORITHM_MINIMUMOPERATIONSTOSORTAPERMUTATION_H

#include "../Base.h"

namespace leetcode {
    class MinimumOperationsToSortAPermutation: public Base {
    public:
        int minOperations(std::vector<int>& nums);
        void test() override;
    };
}

#endif //ALGORITHM_MINIMUMOPERATIONSTOSORTAPERMUTATION_H