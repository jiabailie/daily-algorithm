//
// Created by Ruiguo Yang on 2026/5/20.
//

#ifndef ALGORITHM_FINDTHEPREFIXCOMMONARRAYOFTWOARRAYS_H
#define ALGORITHM_FINDTHEPREFIXCOMMONARRAYOFTWOARRAYS_H

#include "../Base.h"

namespace leetcode {
    class FindThePrefixCommonArrayOfTwoArrays: public Base {
    public:
        int countOne(uint64_t x);
        std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B);
        void test() override;
    };
}

#endif //ALGORITHM_FINDTHEPREFIXCOMMONARRAYOFTWOARRAYS_H