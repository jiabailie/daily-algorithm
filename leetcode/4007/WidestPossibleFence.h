//
// Created by ruiguo on 2026/8/4.
//

#ifndef ALGORITHM_WIDESTPOSSIBLEFENCE_H
#define ALGORITHM_WIDESTPOSSIBLEFENCE_H

#include "../Base.h"

namespace leetcode {
    class WidestPossibleFence: public Base {
    public:
        int maximumWidth(std::vector<int>& planks);
        void test() override;
    };
}

#endif //ALGORITHM_WIDESTPOSSIBLEFENCE_H
