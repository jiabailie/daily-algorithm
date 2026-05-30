//
// Created by Ruiguo Yang on 2026/5/30.
//

#ifndef ALGORITHM_MAXIMUMPATHINTERSECTIONSUMINAGRID_H
#define ALGORITHM_MAXIMUMPATHINTERSECTIONSUMINAGRID_H

#include "../Base.h"

namespace leetcode {
    class MaximumPathIntersectionSumInAGrid: public Base {
    public:
        int maxSubArray(std::vector<int>& nums);
        int maxScore(std::vector<std::vector<int>>& grid);
        void test() override;
    };
}

#endif //ALGORITHM_MAXIMUMPATHINTERSECTIONSUMINAGRID_H