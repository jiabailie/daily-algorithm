//
// Created by ruiguo on 2026/8/20.
//

#ifndef ALGORITHM_LONGESTSUBSEQUENCEWITHNONZEROBITWISEXOR_H
#define ALGORITHM_LONGESTSUBSEQUENCEWITHNONZEROBITWISEXOR_H

#include "../Base.h"

namespace leetcode {
    class LongestSubsequenceWithNonZeroBitwiseXor: public Base {
    public:
        int longestSubsequence(std::vector<int>& nums);
        void test() override;
    };
}

#endif //ALGORITHM_LONGESTSUBSEQUENCEWITHNONZEROBITWISEXOR_H
