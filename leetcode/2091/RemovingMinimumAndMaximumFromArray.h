//
// Created by Ruiguo on 30/8/2026.
//

#ifndef ALGORITHM_REMOVINGMINIMUMANDMAXIMUMFROMARRAY_H
#define ALGORITHM_REMOVINGMINIMUMANDMAXIMUMFROMARRAY_H

#include "../Base.h"

namespace leetcode {
    class RemovingMinimumAndMaximumFromArray: public Base {
    public:
        int minimumDeletions(std::vector<int>& nums);
        void test() override;
    };
}

#endif //ALGORITHM_REMOVINGMINIMUMANDMAXIMUMFROMARRAY_H
