//
// Created by ruiguo on 2026/6/30.
//

#ifndef ALGORITHM_NUMBEROFSUBSTRINGSCONTAININGALLTHREECHARACTERS_H
#define ALGORITHM_NUMBEROFSUBSTRINGSCONTAININGALLTHREECHARACTERS_H

#include "../Base.h"

namespace leetcode {
    class NumberOfSubstringsContainingAllThreeCharacters: public Base {
    public:
        int numberOfSubstrings(std::string s);
        void test() override;
    };
}

#endif //ALGORITHM_NUMBEROFSUBSTRINGSCONTAININGALLTHREECHARACTERS_H
