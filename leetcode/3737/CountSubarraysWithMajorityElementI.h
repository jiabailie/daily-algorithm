//
// Created by ruiguo on 2026/6/25.
//

#ifndef ALGORITHM_COUNTSUBARRAYSWITHMAJORITYELEMENTI_H
#define ALGORITHM_COUNTSUBARRAYSWITHMAJORITYELEMENTI_H

#include "../Base.h"

namespace leetcode {
    class CountSubarraysWithMajorityElementI: public Base {
    public:
        int countMajoritySubarrays(std::vector<int>& nums, int target);
        void test() override;
    };
}

#endif //ALGORITHM_COUNTSUBARRAYSWITHMAJORITYELEMENTI_H
