//
// Created by Ruiguo on 2/8/2026.
//

#ifndef ALGORITHM_COUNTSUBARRAYSWITHEVENODDRATIOI_H
#define ALGORITHM_COUNTSUBARRAYSWITHEVENODDRATIOI_H

#include "../Base.h"

namespace leetcode {
    class CountSubarraysWithEvenOddRatioI: public Base {
    public:
        int countRatioSubarrays(std::vector<int>& nums, int a, int b);
        void test() override;
    };
}

#endif //ALGORITHM_COUNTSUBARRAYSWITHEVENODDRATIOI_H
