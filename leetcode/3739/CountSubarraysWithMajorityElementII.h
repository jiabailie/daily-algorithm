//
// Created by ruiguo on 2026/6/26.
//

#ifndef ALGORITHM_COUNTSUBARRAYSWITHMAJORITYELEMENTII_H
#define ALGORITHM_COUNTSUBARRAYSWITHMAJORITYELEMENTII_H

#include "../Base.h"

namespace leetcode {
    class CountSubarraysWithMajorityElementII: public Base {
    public:
        long long countMajoritySubarrays(std::vector<int>& nums, int target);
        void test() override;
    };
}

#endif //ALGORITHM_COUNTSUBARRAYSWITHMAJORITYELEMENTII_H
