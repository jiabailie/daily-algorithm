//
// Created by Ruiguo Yang on 2026/6/28.
//

#ifndef ALGORITHM_FILTEROCCUPIEDINTERVALS_H
#define ALGORITHM_FILTEROCCUPIEDINTERVALS_H

#include "../Base.h"

namespace leetcode {
    class FilterOccupiedIntervals: public Base {
    public:
        std::vector<std::vector<int>> filterOccupiedIntervals(std::vector<std::vector<int>>& intervals, int freeStart, int freeEnd);
        void test() override;
    };
}

#endif //ALGORITHM_FILTEROCCUPIEDINTERVALS_H