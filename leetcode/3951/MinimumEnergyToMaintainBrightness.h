//
// Created by ruiguo on 2026/6/19.
//

#ifndef ALGORITHM_MINIMUMENERGYTOMAINTAINBRIGHTNESS_H
#define ALGORITHM_MINIMUMENERGYTOMAINTAINBRIGHTNESS_H

#include "../Base.h"

typedef long long ll;

namespace leetcode {
    class MinimumEnergyToMaintainBrightness: public Base {
    public:
        std::vector<std::vector<int>> mergeIntervals(std::vector<std::vector<int>>& intervals);
        long long minEnergy(int n, int brightness, std::vector<std::vector<int>>& intervals);
        void test() override;
    };
}

#endif //ALGORITHM_MINIMUMENERGYTOMAINTAINBRIGHTNESS_H
