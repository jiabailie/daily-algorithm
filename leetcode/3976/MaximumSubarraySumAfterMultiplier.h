//
// Created by ruiguo on 2026/6/29.
//

#ifndef ALGORITHM_MAXIMUMSUBARRAYSUMAFTERMULTIPLIER_H
#define ALGORITHM_MAXIMUMSUBARRAYSUMAFTERMULTIPLIER_H

#include "../Base.h"

namespace leetcode {
    class MaximumSubarraySumAfterMultiplier: public Base {
    public:
        long long maxSubarraySum(std::vector<int>& nums, int k);
        void test() override;
    };
}



#endif //ALGORITHM_MAXIMUMSUBARRAYSUMAFTERMULTIPLIER_H
