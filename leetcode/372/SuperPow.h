//
// Created by ruiguo on 2026/7/27.
//

#ifndef ALGORITHM_SUPERPOW_H
#define ALGORITHM_SUPERPOW_H

#include "../Base.h"

namespace leetcode {
    class SuperPow: public Base {
    public:
        const int MOD = 1337;
        int pow(int x, int n);
        int superPow(int a, std::vector<int>& b);
        void test() override;
    };
}

#endif //ALGORITHM_SUPERPOW_H
