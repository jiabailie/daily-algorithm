//
// Created by Ruiguo Yang on 2026/5/15.
//

#ifndef ALGORITHM_FINDMINIMUMINROTATEDSORTEDARRAY_H
#define ALGORITHM_FINDMINIMUMINROTATEDSORTEDARRAY_H

#include "../Base.h"

namespace leetcode {
    class FindMinimumInRotatedSortedArray: public Base {
    public:
        int findMin(std::vector<int>& nums);
        void test() override;
    };
}

#endif //ALGORITHM_FINDMINIMUMINROTATEDSORTEDARRAY_H