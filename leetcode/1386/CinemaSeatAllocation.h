//
// Created by ruiguo on 2026/8/19.
//

#ifndef ALGORITHM_CINEMASEATALLOCATION_H
#define ALGORITHM_CINEMASEATALLOCATION_H

#include "../Base.h"

namespace leetcode {
    class CinemaSeatAllocation: public Base {
    public:
        int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats);
        void test() override;
    };
}

#endif //ALGORITHM_CINEMASEATALLOCATION_H
