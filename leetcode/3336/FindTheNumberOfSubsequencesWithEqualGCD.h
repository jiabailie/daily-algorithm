//
// Created by Ruiguo on 14/7/2026.
//

#ifndef ALGORITHM_FINDTHENUMBEROFSUBSEQUENCESWITHEQUALGCD_H
#define ALGORITHM_FINDTHENUMBEROFSUBSEQUENCESWITHEQUALGCD_H

#include "../Base.h"

namespace leetcode {
    class FindTheNumberOfSubsequencesWithEqualGCD: public Base {
    private:
        static constexpr int MOD = 1'000'000'007;
    public:
        int subsequencePairCount(std::vector<int>& nums);
        void test() override;
    };
}

#endif //ALGORITHM_FINDTHENUMBEROFSUBSEQUENCESWITHEQUALGCD_H
