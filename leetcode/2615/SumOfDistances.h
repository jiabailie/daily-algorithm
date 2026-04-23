//
// Created by Ruiguo Yang on 2026/4/23.
//

#ifndef ALGORITHM_SUMOFDISTANCES_H
#define ALGORITHM_SUMOFDISTANCES_H

#include <vector>
#include "../Base.h"

namespace leetcode {
    class SumOfDistances: public Base {
    public:
        std::vector<long long> distance(std::vector<int>& nums);
        void test() override;
    };
}

#endif //ALGORITHM_SUMOFDISTANCES_H