//
// Created by Ruiguo Yang on 2026/5/11.
//

#ifndef ALGORITHM_THREESUMCLOSEST_H
#define ALGORITHM_THREESUMCLOSEST_H

#include "../Base.h"

namespace leetcode {
    class ThreeSumClosest: public Base {
    public:
        int threeSumClosest(std::vector<int>& nums, int target);
        void test() override;
    };
}

#endif //ALGORITHM_THREESUMCLOSEST_H