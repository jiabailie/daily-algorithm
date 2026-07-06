//
// Created by ruiguo on 2026/7/6.
//

#ifndef ALGORITHM_REMOVECOVEREDINTERVALS_H
#define ALGORITHM_REMOVECOVEREDINTERVALS_H

#include "../Base.h"

namespace leetcode {
    class RemoveCoveredIntervals: public Base {
    public:
        int removeCoveredIntervals(std::vector<std::vector<int>>& intervals);
        void test() override;
    };
}

#endif //ALGORITHM_REMOVECOVEREDINTERVALS_H
