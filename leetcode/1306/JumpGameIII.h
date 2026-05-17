//
// Created by Ruiguo Yang on 2026/5/17.
//

#ifndef ALGORITHM_JUMPGAMEIII_H
#define ALGORITHM_JUMPGAMEIII_H

#include "../Base.h"

namespace leetcode {
    class JumpGameIII: public Base {
    public:
        bool canReach(std::vector<int>& arr, int start);
        void test() override;
    };
}


#endif //ALGORITHM_JUMPGAMEIII_H