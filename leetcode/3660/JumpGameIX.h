//
// Created by Ruiguo Yang on 2026/5/7.
//

#ifndef ALGORITHM_JUMPGAMEIX_H
#define ALGORITHM_JUMPGAMEIX_H

#include "../Base.h"

namespace leetcode {
    class JumpGameIX: public Base {
    public:
        std::vector<int> maxValue(std::vector<int>& nums);
        void test() override;
    };
}



#endif //ALGORITHM_JUMPGAMEIX_H