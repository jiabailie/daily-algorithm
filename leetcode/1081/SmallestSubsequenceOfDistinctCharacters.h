//
// Created by Ruiguo on 19/7/2026.
//

#ifndef ALGORITHM_SMALLESTSUBSEQUENCEOFDISTINCTCHARACTERS_H
#define ALGORITHM_SMALLESTSUBSEQUENCEOFDISTINCTCHARACTERS_H

#include "../Base.h"

namespace leetcode {
    class SmallestSubsequenceOfDistinctCharacters: public Base {
    public:
        std::string smallestSubsequence(std::string s);
        void test() override;
    };
}

#endif //ALGORITHM_SMALLESTSUBSEQUENCEOFDISTINCTCHARACTERS_H
