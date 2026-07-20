//
// Created by ruiguo on 2026/7/20.
//

#ifndef ALGORITHM_SHIFT2DGRID_H
#define ALGORITHM_SHIFT2DGRID_H

#include "../Base.h"

namespace leetcode {
    class Shift2DGrid: public Base {
    public:
        std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>>& grid, int k);
        void test() override;
    };
}

#endif //ALGORITHM_SHIFT2DGRID_H
