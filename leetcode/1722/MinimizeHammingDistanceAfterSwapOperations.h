//
// Created by Ruiguo Yang on 2026/4/21.
//

#ifndef ALGORITHM_MINIMIZEHAMMINGDISTANCEAFTERSWAPOPERATIONS_H
#define ALGORITHM_MINIMIZEHAMMINGDISTANCEAFTERSWAPOPERATIONS_H

#include <vector>
#include "../Base.h"

namespace leetcode {
    class MinimizeHammingDistanceAfterSwapOperations: public Base {
    public:
        int minimumHammingDistance(std::vector<int>& source, std::vector<int>& target, std::vector<std::vector<int>>& allowedSwaps);
        void test() override;
    };
}


#endif //ALGORITHM_MINIMIZEHAMMINGDISTANCEAFTERSWAPOPERATIONS_H
