//
// Created by Ruiguo Yang on 2026/6/20.
//

#ifndef ALGORITHM_MAXIMUMBUILDINGHEIGHT_H
#define ALGORITHM_MAXIMUMBUILDINGHEIGHT_H

#include "../Base.h"

namespace leetcode {
    class MaximumBuildingHeight: public Base {
    public:
        int maxBuilding(int n, std::vector<std::vector<int>>& restrictions);
        void test() override;
    };
}

#endif //ALGORITHM_MAXIMUMBUILDINGHEIGHT_H