//
// Created by Ruiguo Yang on 2026/6/27.
//

#ifndef ALGORITHM_FINDTHEMAXIMUMNUMBEROFELEMENTSINSUBSET_H
#define ALGORITHM_FINDTHEMAXIMUMNUMBEROFELEMENTSINSUBSET_H

#include "../Base.h"

namespace leetcode {
    class FindTheMaximumNumberOfElementsInSubset: public Base {
    public:
        int maximumLength(std::vector<int>& nums);
        void test() override;
    };
}

#endif //ALGORITHM_FINDTHEMAXIMUMNUMBEROFELEMENTSINSUBSET_H