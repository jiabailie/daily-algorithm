//
// Created by ruiguo on 2026/7/13.
//

#ifndef ALGORITHM_SEQUENTIALDIGITS_H
#define ALGORITHM_SEQUENTIALDIGITS_H

#include "../Base.h"

namespace leetcode {
    class SequentialDigits: public Base {
    public:
        std::vector<int> sequentialDigits(int low, int high);
        void test() override;
    };
}

#endif //ALGORITHM_SEQUENTIALDIGITS_H
