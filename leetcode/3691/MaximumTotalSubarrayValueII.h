//
// Created by Ruiguo Yang on 2026/6/10.
//

#ifndef ALGORITHM_MAXIMUMTOTALSUBARRAYVALUEII_H
#define ALGORITHM_MAXIMUMTOTALSUBARRAYVALUEII_H

#include "../Base.h"

namespace leetcode {
    class MaximumTotalSubarrayValueII: public Base {
    public:
        long long maxTotalValue(std::vector<int>& nums, int k);
        void test() override;
    };
}

#endif //ALGORITHM_MAXIMUMTOTALSUBARRAYVALUEII_H