//
// Created by Ruiguo Yang on 2026/4/29.
//

#ifndef ALGORITHM_MAXIMUMSCOREFROMGRIDOPERATIONS_H
#define ALGORITHM_MAXIMUMSCOREFROMGRIDOPERATIONS_H

#include "../Base.h"

namespace leetcode {
    class MaximumScoreFromGridOperations: public Base {
    public:
        long long maximumScore(std::vector<std::vector<int>>& grid);
        void test() override;
    };
}



#endif //ALGORITHM_MAXIMUMSCOREFROMGRIDOPERATIONS_H