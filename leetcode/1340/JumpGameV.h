//
// Created by Ruiguo Yang on 2026/5/24.
//

#ifndef ALGORITHM_JUMPGAMEV_H
#define ALGORITHM_JUMPGAMEV_H

#include "../Base.h"

namespace leetcode {
    class JumpGameV: public Base {
    public:
        int maxJumps(std::vector<int>& arr, int d);
        void test() override;
    };
}

#endif //ALGORITHM_JUMPGAMEV_H