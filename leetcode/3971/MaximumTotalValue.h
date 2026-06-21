//
// Created by Ruiguo Yang on 2026/6/21.
//

#ifndef ALGORITHM_MAXIMUMTOTALVALUE_H
#define ALGORITHM_MAXIMUMTOTALVALUE_H

#include "../Base.h"

namespace leetcode {
    class MaximumTotalValue: public Base {
    public:
        int maxTotalValue(std::vector<int>& value, std::vector<int>& decay, int m);
        void test() override;
    };
}

#endif //ALGORITHM_MAXIMUMTOTALVALUE_H