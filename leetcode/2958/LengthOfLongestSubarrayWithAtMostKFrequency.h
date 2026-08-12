//
// Created by Ruiguo on 12/8/2026.
//

#ifndef ALGORITHM_LENGTHOFLONGESTSUBARRAYWITHATMOSTKFREQUENCY_H
#define ALGORITHM_LENGTHOFLONGESTSUBARRAYWITHATMOSTKFREQUENCY_H

#include "../Base.h"

namespace leetcode {
    class LengthOfLongestSubarrayWithAtMostKFrequency: public Base {
    public:
        int maxSubarrayLength(std::vector<int>& nums, int k);
        void test() override;
    };
}

#endif //ALGORITHM_LENGTHOFLONGESTSUBARRAYWITHATMOSTKFREQUENCY_H
