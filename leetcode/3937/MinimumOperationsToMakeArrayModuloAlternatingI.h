//
// Created by Ruiguo Yang on 2026/5/29.
//

#ifndef ALGORITHM_MINIMUMOPERATIONSTOMAKEARRAYMODULOALTERNATINGI_H
#define ALGORITHM_MINIMUMOPERATIONSTOMAKEARRAYMODULOALTERNATINGI_H

#include "../Base.h"

namespace leetcode {
    class MinimumOperationsToMakeArrayModuloAlternatingI: public Base {
    public:
        int minOperations(std::vector<int>& nums, int k);
        void test() override;
    };
}

#endif //ALGORITHM_MINIMUMOPERATIONSTOMAKEARRAYMODULOALTERNATINGI_H