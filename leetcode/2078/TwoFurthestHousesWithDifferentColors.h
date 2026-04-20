//
// Created by Ruiguo Yang on 2026/4/20.
//

#ifndef ALGORITHM_TWUFURTHESTHOUSESWITHDIFFERENTCOLORS_H
#define ALGORITHM_TWUFURTHESTHOUSESWITHDIFFERENTCOLORS_H

#include "../Base.h"

namespace leetcode {
    class TwoFurthestHousesWithDifferentColors: public Base {
    public:
        int maxDistance(std::vector<int>& colors);
        void test() override;
    };
}

#endif //ALGORITHM_TWUFURTHESTHOUSESWITHDIFFERENTCOLORS_H