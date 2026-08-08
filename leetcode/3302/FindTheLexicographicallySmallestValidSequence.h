//
// Created by Ruiguo on 8/8/2026.
//

#ifndef ALGORITHM_FINDTHELEXICOGRAPHICALLYSMALLESTVALIDSEQUENCE_H
#define ALGORITHM_FINDTHELEXICOGRAPHICALLYSMALLESTVALIDSEQUENCE_H

#include "../Base.h"

namespace leetcode {
    class FindTheLexicographicallySmallestValidSequence: public Base {
    public:
        std::vector<int> validSequence(std::string s, std::string t);
        void test() override;
    };
}

#endif //ALGORITHM_FINDTHELEXICOGRAPHICALLYSMALLESTVALIDSEQUENCE_H
