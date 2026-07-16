//
// Created by Ruiguo on 16/7/2026.
//

#ifndef ALGORITHM_SUMOFGCDOFFORMEDPAIRS_H
#define ALGORITHM_SUMOFGCDOFFORMEDPAIRS_H

#include "../Base.h"

namespace leetcode {
    class SumOfGCDOfFormedPairs: public Base {
    public:
        int gcd(int a, int b);
        long long gcdSum(std::vector<int>& nums);
        void test() override;
    };
}

#endif //ALGORITHM_SUMOFGCDOFFORMEDPAIRS_H
