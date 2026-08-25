//
// Created by ruiguo on 2026/8/25.
//

#ifndef ALGORITHM_LONGESTSUBARRAYWITHATMOSTKDISTINCTPRIMEFACTORS_H
#define ALGORITHM_LONGESTSUBARRAYWITHATMOSTKDISTINCTPRIMEFACTORS_H

#include "../Base.h"

namespace leetcode {
    class LongestSubarrayWithAtMostKDistinctPrimeFactors: public Base {
    private:
        static constexpr int MX = 100'001;
        static std::vector<int> primeFactors[MX];
        static int init;

        static int initPrimeFactors() {
            for (int i = 2; i < MX; ++i) {
                if (primeFactors[i].empty()) {
                    for (int j = i; j < MX; j += i) {
                        primeFactors[j].push_back(i);
                    }
                }
            }
            return 0;
        }
    public:
        int longestSubarray(std::vector<int>& nums, int k);
        void test() override;
    };
}

#endif //ALGORITHM_LONGESTSUBARRAYWITHATMOSTKDISTINCTPRIMEFACTORS_H
