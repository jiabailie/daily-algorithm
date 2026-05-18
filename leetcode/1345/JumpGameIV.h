//
// Created by Ruiguo Yang on 2026/5/18.
//

#ifndef ALGORITHM_JUMPGAMEIV_H
#define ALGORITHM_JUMPGAMEIV_H

#include "../Base.h"

namespace leetcode {
    class JumpGameIV: public Base {
    public:
        int minJumps(std::vector<int>& arr);
        void test() override;
    };
}

#endif //ALGORITHM_JUMPGAMEIV_H