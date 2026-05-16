//
// Created by Ruiguo Yang on 2026/5/16.
//

#ifndef ALGORITHM_FINDMINIMUMINROTATEDSORTEDARRAYII_H
#define ALGORITHM_FINDMINIMUMINROTATEDSORTEDARRAYII_H

#include "../Base.h"

namespace leetcode {
    class FindMinimumInRotatedSortedArrayII: public Base {
    public:
        int findMin(std::vector<int>& nums);
        void test() override;
    };
}

#endif //ALGORITHM_FINDMINIMUMINROTATEDSORTEDARRAYII_H