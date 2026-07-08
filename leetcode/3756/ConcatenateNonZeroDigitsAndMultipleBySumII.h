//
// Created by ruiguo on 2026/7/8.
//

#ifndef ALGORITHM_CONCATENATENONZERODIGITSANDMULTIPLEBYSUMII_H
#define ALGORITHM_CONCATENATENONZERODIGITSANDMULTIPLEBYSUMII_H

#include "../Base.h"

namespace leetcode {
    constexpr  int MOD = 1'000'000'007;
    constexpr int MAX_N = 100'001;
    int pow10[MAX_N];
    class ConcatenateNonZeroDigitsAndMultipleBySumII: public Base {
    private:
        int init = [] {
            pow10[0] = 1;
            for (int i = 1; i < MAX_N; i++) {
                pow10[i] = (pow10[i - 1] * 10LL) % MOD;
            }
            return 0;
        }();
    public:
        std::vector<int> sumAndMultiply(std::string s, std::vector<std::vector<int>>& queries);
        void test() override;
    };
}

#endif //ALGORITHM_CONCATENATENONZERODIGITSANDMULTIPLEBYSUMII_H
