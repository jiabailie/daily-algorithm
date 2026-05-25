//
// Created by Ruiguo Yang on 2026/5/25.
//

#ifndef ALGORITHM_JUMPGAMEVII_H
#define ALGORITHM_JUMPGAMEVII_H

#include "../Base.h"

namespace leetcode {
    class JumpGameVII: public Base {
    public:
        bool canReach(std::string s, int minJump, int maxJump);
        void test() override;
    };
}

#endif //ALGORITHM_JUMPGAMEVII_H