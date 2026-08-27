//
// Created by ruiguo on 2026/8/27.
//

#ifndef ALGORITHM_LEXICOGRAPHICALLYSMALLESTPERMUTATIONGREATERTHANTARGET_H
#define ALGORITHM_LEXICOGRAPHICALLYSMALLESTPERMUTATIONGREATERTHANTARGET_H

#include "../Base.h"

namespace leetcode {
    class LexicographicallySmallestPermutationGreaterThanTarget: public Base {
    public:
        std::string lexGreaterPermutation(std::string s, std::string target);
        void test() override;
    };
}

#endif //ALGORITHM_LEXICOGRAPHICALLYSMALLESTPERMUTATIONGREATERTHANTARGET_H
