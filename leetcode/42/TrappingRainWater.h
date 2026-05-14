//
// Created by Ruiguo Yang on 2026/5/14.
//

#ifndef ALGORITHM_TRAPPINGRAINWATER_H
#define ALGORITHM_TRAPPINGRAINWATER_H

#include "../Base.h"

namespace leetcode {
    class TrappingRainWater: public Base {
    public:
        int trap1(std::vector<int>& height);
        int trap2(std::vector<int>& height);
        void test() override;
    };
}


#endif //ALGORITHM_TRAPPINGRAINWATER_H