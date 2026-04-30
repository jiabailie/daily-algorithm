//
// Created by Ruiguo Yang on 2026/4/30.
//

#ifndef ALGORITHM_MAXIMUMPATHSCOREINAGRID_H
#define ALGORITHM_MAXIMUMPATHSCOREINAGRID_H

#include "../Base.h"

namespace leetcode {
    class MaximumPathScoreInAGrid: public Base {
    public:
        int maxPathScore(std::vector<std::vector<int>>& grid, int k);
        void test() override;
    };
}

#endif //ALGORITHM_MAXIMUMPATHSCOREINAGRID_H